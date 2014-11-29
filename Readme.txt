
Copyright 2014 by Alexander Balasch http://coolrobotprojects.blogspot.co.at/

This work is licensed under the Creative Commons Attribution-NonCommercial 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc/4.0/.

this project has been inspired by:

http://pleasantsoftware.com/developer/3d/spherebot/

///////////////////////////////////////////////////////////////////////////////////

Features of 2.0:

-Complete rework of the internal Communication, now based on the Qt-internal SerialPort library.
 No need for the QextSeriallibrary any more. The communication is now event-based and not polling-based
 what reduces cpu-usage enormously.

-Support for Multilayered Prints:
	The program seeks each line with M01 in the code and extracts the layername from that line.
	After each layer you will be promted to change the pen for the next layer. 
	Just press OK and it will automatically load the next layer and start printing.
	In the end you will be asked if you want to restart the print.

-persistence of loaded file and connected port

-General improvements and Bugfixes

-Optimisations of the firmware


-The attached Version of inkscape portable already comes with the needed eggbot-extensions installed.
 Simply run inkscape.exe

HOW TO:

0.) Build the Eggbot

	I used these CAD files: https://www.thingiverse.com/thing:22438

1.) Upload the Arduino sketch.

	(I have added an additional multiplicator to the y-Step calculation to 
	match my spherebot to the unicorn-script coordinates. You will maybe have to
	do the same adjustment for your Spherebot)

	(You will also have to redefine your pins accordingly to your electronics design)

2.) Start the Spherebot-UI.exe int the /bin folder and connect to your Arduino

Warning for custom Firmwares:
		
	The send file function will only work if the arduino answers
	each sent command with a message that contains "ok:" so that 
	the next command is sent.
				

3.) Print stuff: Sources - https://github.com/matthewbeckler/HackPittsburghMedia

    Here is a Version of Inkscape portable which has the needed Extensions for the 
    Spherebot preinstalled: https://github.com/thunderbug1/Inkscape_portable_for_Spherebot

PS:Have fun with it ;)
