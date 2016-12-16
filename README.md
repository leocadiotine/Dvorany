#Dvorany

![Dvorany](http://static.leocad.io/Dvorany.JPG)

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

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/hPwisj-K4pg/0.jpg)](http://www.youtube.com/watch?v=hPwisj-K4pg)

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

[![Donate button](https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=PPHGB75L9LUC4&lc=US&item_name=Leocadio%20Tin%c3%a9&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donate_LG%2egif%3aNonHosted)
