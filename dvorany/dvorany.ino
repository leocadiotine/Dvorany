/* Arduino Keyboard HID driver and USB host shield pass through */

/*-
 * Copyright (c) 2011 Darran Hunt (darran [at] hunt dot net dot nz)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <Spi.h>
#include <Max3421e.h>
#include <Usb.h>

/* keyboard data taken from configuration descriptor */
#define KBD_ADDR        1
#define KBD_EP          1
#define KBD_IF          0
#define EP_MAXPKTSIZE   8
#define EP_POLL         0x0a

/* Sticky keys */
#define CAPSLOCK    0x39
#define NUMLOCK     0x53
#define SCROLLLOCK  0x47

/* Sticky keys output report bitmasks */
#define REP_NUMLOCK       0x01
#define REP_CAPSLOCK      0x02
#define REP_SCROLLLOCK    0x04

EP_RECORD ep_record[2];  //endpoint record structure for the keyboard

uint8_t buf[8] = { 0 };      // keyboard buffer
uint8_t old_buf[8] = { 0 };  // last poll

/* Sticky key state */
bool numLock = false;
bool capsLock = false;
bool scrollLock = false;

void setup();
void loop();
bool key_is_new(byte key, byte *report);

MAX3421E Max;
USB Usb;

void setup() 
{
    Serial.begin(9600);
    Max.powerOn();
    delay(200);
}

void loop() 
{
    Max.Task();
    Usb.Task();

    if (Usb.getUsbTaskState() == USB_STATE_CONFIGURING) {
        kbd_init();
        Usb.setUsbTaskState( USB_STATE_RUNNING);
    }

    if (Usb.getUsbTaskState() == USB_STATE_RUNNING) {
        kbd_poll();
    }
}

/* Initialize keyboard */
void kbd_init( void )
{
    byte rcode = 0;  //return code

    /* Initialize data structures */
    ep_record[0] = *(Usb.getDevTableEntry(0,0));  //copy endpoint 0 parameters
    ep_record[1].MaxPktSize = EP_MAXPKTSIZE;
    ep_record[1].Interval  = EP_POLL;
    ep_record[1].sndToggle = bmSNDTOG0;
    ep_record[1].rcvToggle = bmRCVTOG0;
    Usb.setDevTableEntry(1, ep_record);              //plug kbd.endpoint parameters to devtable

    /* Configure device */
    rcode = Usb.setConf(KBD_ADDR, 0, 1);                    
    if (rcode) {
        while(1);  //stop
    }
    delay(2000);
}

/* Poll USB keyboard for new key presses, send through to host via 
 * the Keyboard HID driver in the atmega8u2
 */
void kbd_poll(void)
{
    char i;
    byte rcode = 0;     //return code
    uint8_t ledReport;
    static uint8_t lastLedReport = 0;
    static uint8_t leds = 0;
    static uint8_t lastLeds = 0;

    /* poll keyboard */
    rcode = Usb.inTransfer(KBD_ADDR, KBD_EP, 8, (char *)buf);
    if (rcode != 0) {
	return;
    }

    /* Check for change */
    for (i=0; i<8; i++) {
        if (buf[i] != old_buf[i]) {
          
            translate_to_dvorak(buf);
	    /* Send the new key presses to the host */
	    Serial.write(buf, 8);

	    /* Get led report */
	    ledReport = Serial.read();
#if 0
            /* Not working yet, ledReport is always 0  */
	    if (ledReport != lastLedReport) {
		rcode = Usb.setReport( KBD_ADDR, 0, 1, KBD_IF, 0x02, 0, (char *)&ledReport );
		lastLedReport = ledReport;
	    }
#endif
            break;
	}
    }

    /* Check for status keys and adjust led status */
    for (i=2; i<8; i++) {
	if (buf[i] == 0) {
	    /* 0 marks end of keys in the report */
	    break;
	}
	/* Check new keys for status change keys */
	if (key_is_new(buf[i], old_buf)) {
	    switch (buf[i]) {
	    case CAPSLOCK:
		capsLock =! capsLock;
		leds = capsLock ? leds |= REP_CAPSLOCK : leds &= ~REP_CAPSLOCK;
		break;
	    case NUMLOCK:
		numLock =! numLock;
		leds = numLock ? leds |= REP_NUMLOCK : leds &= ~REP_NUMLOCK;
		break;
	    case SCROLLLOCK:
		scrollLock =! scrollLock;
		leds = scrollLock ? leds |= REP_SCROLLLOCK : leds &= ~REP_SCROLLLOCK;
		break;
	    default:
	        break;
	    }
	}
    }

    /* Got a change in LED status? */
    if (lastLeds != leds) {
	Usb.setReport( KBD_ADDR, 0, 1, KBD_IF, 0x02, 0, (char *)&leds );
	lastLeds = leds;
    }

    /* update the old buffer */
    for (i=0; i<8; i++) {
	old_buf[i] = buf[i];
    }

}

/*
* Function:    key_is_new(key, report)
* Description: see if key is new or is already in report
* Returns:     false if found, true if not
*/
bool key_is_new(uint8_t key, uint8_t *report)
{
    uint8_t ind;
    for (ind=2; ind<8; ind++) {
	if (report[ind] == key) {
	    return false;
	}
    }
    return true;
}
