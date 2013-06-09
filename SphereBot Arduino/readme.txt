v0.1

This is the firmware for an EggBot-style SphereBot.
The firmware directly interprets GCode send over the serial port.

There will be more information on the SphereBot at http://pleasantsoftware.com/developer/3d (in the near future...)

!!!!!!!!
This sketch needs the following non-standard libraries (install them in the Arduino library directory):
SoftwareServo: http://www.arduino.cc/playground/ComponentLib/Servo
TimerOne: http://www.arduino.cc/playground/Code/Timer1
!!!!!!!!

Copyright 2011 by Eberhard Rensch <http://pleasantsoftware.com/developer/3d>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

Part of this code is based on/inspired by the Helium Frog Delta Robot Firmware
by Martin Price <http://www.HeliumFrog.com>

To create tags File: ctags --langmap="C++:+.pde" S*


GCode commands:

G90	Absolut modus
G91	Icremental modus:

M300S0	Servo 0 degree
M300S90	Servo 90 degree


M18	Stepper off

G0X0Y40	Rapid movement (pen 0mm, rotation 40mm)
G1X40Y0 Slower movement (pen 40mm, rotation 0mm)
G1Y10F660 Movement with feed 660mm/s (rotation 10mm)

;	Comment
( .. )	Comment
