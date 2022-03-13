obj-m += proc_rw.o
all:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
insmod:
	sudo insmod proc_rw.ko
rmmod:
	sudo rmmod proc_rw
log:
	sudo dmesg
cat:
	cat /proc/proc_rw
