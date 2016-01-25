Objectives

The system has to check if a flash drive is plugged, in that case the system crypts the flash drive then unmount it and a LED blink to signal that the device can be unplugged.

In version 1.0 we have implemented the function which encrypts data in the flash drive.

To run:

*First copy S99Test.sh in /etc/init.d
*Copy test.sh in /root/
*Copy the bin encrypte in /root/
*Reboot the Armadeus.

in the Flash drive you have to store a file named toCrypt.txt which will be crypted.

When no device is plugged in the Armadeus the LED will blink slowly. Plug your flash drive and wait until the LED blinks faster, when it happen you can unplug the device safely.

You will two files in the memory stick, toCrypt.txt and output.txt, the output file is the crypted version of toCrypt.txt if you do not want to save toCrypt.txt you can uncomment the line 31 in test.sh.
