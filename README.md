#Dvorany

![Dvorany](https://dl.dropboxusercontent.com/u/5135185/blog/Dvorany.JPG)

Arduino-powered box that enables the use of the Dvorak keyboard layout on any computer.

##Purpose
If you use Dvorak as your keyboard layout, it's always a pain to use someone else's computer. Trying to type on a QWERTY keyboard not only makes you look like a fool, but is also annoying and terribly slow.

To work around this, you can always go to the system settings and change the keyboard layout to Dvorak. But there are several moments on which this is hard, slow or impossible to do:

* Trying to change the keyboard settings on an operating system different than the one you're used to is hard. And there is the chance that this particular OS doesn't support Dvorak;
* Sometimes you don't have administrator rights on the computer, so you can't change the keyboard settings;
* Trying to pair-program with a QWERTY friend on the same computer is impossible;
* When being interviewed for a job or giving a lecture, sometimes you're prompted to use their computer (and their keyboard layout). Going to all the hassle above can take time and annoy people;
* Trying to set up a BIOS or install an OS from the command line is impossible with Dvorak.

Dvorany aims to solve that problem by using hardware. You can plug any USB keyboard to Dvorany and type using your Dvorak style. Dvorany will appear as a regular USB keyboard to the host (QWERTY) computer, but all your keystrokes will appear as you intended them to appear, as if the system settings are set to use Dvorak.

##See it in action
Instead of talking about it, it's better to see it in action:

<a href="http://youtu.be/hPwisj-K4pg">![Dvorany on Youtube](https://dl.dropboxusercontent.com/u/5135185/blog/dvorany-video.png)</a>

##Can I use it?
Sure. You're always welcome to create a Dvorany yourself. If you want me to make one for you, just mail me at me[at]leocad.io and make your special request.

Instructions on how to create yours can be found at the [wiki page](https://github.com/leocadiotine/Dvorany/wiki/How-to-create-your-Dvorany).

##License
Dvorany source code is released under BSD 2-clause license. Check LICENSE file for more information.

If you use this code, I'd appreciate you refer my name (Leocadio Tiné) and the link to this project's page in your project's website or credits screen. Though you don't have any legal/contractual obligation to do so, just good karma.

##Hardware used on the project
Dvorany uses an [Arduino Uno R3](http://arduino.cc/en/Main/arduinoBoardUno), but can be built using any Arduino board that has a USB port and an Atmega8u2-compatible microcontroller.

On top of that, it uses a USB host shield. The one in the picture is from [Sparkfun](https://www.sparkfun.com/products/9947), but [Circuits@Home](http://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino) have them as well.

##Credits
Dvorany was based on darran's awesome work. Especially [this project](http://hunt.net.nz/users/darran/weblog/c6f35/), which is the base for Dvorany's source code.

This was also only possible thanks to [felis](https://github.com/felis)' great work on creating a [library for Circuits@Home USB shield](https://github.com/felis/USB_Host_Shield/).

##What next?
Dvorany deserves a pretty enclosure, but unfortunately I don't have the skills to make a 3D model and print using a 3D printer. If you want to contribute, please get in touch!

##Suggestions? Comments?
Pull requests are always welcome. So are donations :)

To find me, buzz at `me[at]leocad.io` or [follow me on Twitter](http://www.twitter.com/leocadiotine). To read interesting stuff, go to [my blog](http://blog.leocad.io).

~~~~
:::::::::::::
::         ::
:: Made at ::
::         ::
:::::::::::::
     ::
Hacker School
:::::::::::::
~~~~

<form action="https://www.paypal.com/cgi-bin/webscr" method="post" target="_top">
<input type="hidden" name="cmd" value="_s-xclick">
<input type="hidden" name="encrypted" value="-----BEGIN PKCS7-----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-----END PKCS7-----
">
<input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
<img alt="" border="0" src="https://www.paypalobjects.com/pt_BR/i/scr/pixel.gif" width="1" height="1">
</form>
