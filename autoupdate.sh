#! /bin/sh

echo "We are updating your system"
if [ -f /mnt/test.sh ]
	then rm /root/test.sh
	cp /mnt/test.sh /root/
	chmod a+x test.sh
	mv /mnt/autoupdate.sh /mnt/updated.sh
#we wait 10 seconds to be sure that it is not busy when it is unmounted
	sleep 10
	umount /mnt
	/root/test.sh
	
else
	echo "File missing"
	mv /mnt/autoupdate.sh /mnt/not_updated.sh
	sleep 10
	umount /mnt
	/root/test.sh
fi
