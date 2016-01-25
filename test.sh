#! /bin/sh
GPIO_LINUX=21
i=200000
if [ -d /sys/class/gpio/gpio$GPIO_LINUX ]
        then echo "gpio$GPIO_LINUX exists"
else
        echo $GPIO_LINUX > /sys/class/gpio/export
fi
echo "out" > /sys/class/gpio/gpio$GPIO_LINUX/direction
while true; do
        #sleep 3
        echo 1 > /sys/class/gpio/gpio$GPIO_LINUX/value
        usleep $i
        echo 0 > /sys/class/gpio/gpio$GPIO_LINUX/value
        usleep $i


        echo 1 > /sys/class/gpio/gpio$GPIO_LINUX/value
        usleep $i
        echo 0 > /sys/class/gpio/gpio$GPIO_LINUX/value
        usleep $i

        echo 1 > /sys/class/gpio/gpio$GPIO_LINUX/value
        usleep $i
        echo 0 > /sys/class/gpio/gpio$GPIO_LINUX/value
        usleep $i
        if [ -b /dev/sda ]
                then    echo "mount"
                mount /dev/sda1 /mnt/
                /root/encrypte
#               rm /mnt/toCrypt.txt
                umount /mnt
                echo "umount"
        while [ -b /dev/sda ]; do


                echo 1 > /sys/class/gpio/gpio$GPIO_LINUX/value
                usleep 50000
                echo 0 > /sys/class/gpio/gpio$GPIO_LINUX/value
                usleep 50000
        done
        else
                echo "no usb "
                #i=200000
        fi
done
