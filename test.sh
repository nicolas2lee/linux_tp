#! /bin/sh
GPIO_LINUX=21
i=0
while true; do
	sleep 3
	if [ -b /dev/sda ]
		then	echo "mount"
		mount /dev/sda1 /mnt/
		sleep 1 
		ls /mnt
		umount /mnt
		if [ -d /sys/class/gpio/gpio$GPIO_LINUX ]
		then echo "gpio$GPIO_LINUX exists"
		else
			echo $GPIO_LINUX > /sys/class/gpio/export
		fi
		echo "out" > /sys/class/gpio/gpio$GPIO_LINUX/direction
		while [ $i -le 2 ];do
			echo 1 > /sys/class/gpio/gpio$GPIO_LINUX/value 
			sleep 1
			echo 0 > /sys/class/gpio/gpio$GPIO_LINUX/value 
			sleep 1
			echo $i
			i=$(($i+1))
		done
	else
		echo "not ok"
		i=0
	fi
done

