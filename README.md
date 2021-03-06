<b>A loadable Linux Kernel Module (LKM) that creates a "pseudo"-file in /proc and provides read + write functionality for a message on the current development state of the running kernel.</b>

Focus was placed on learning about and understanding /proc, how to communicate between user-space and kernel-space, as well as how to load and unload kernel modules while the kernel is running.

***

<b>Project Overview:</b>

- The proc file system is a virtual file system created when the system boots and destroyed at system shut down. It contains information about various processes running and is generally considered the main kernel information source about the kernel while the kernel is running.
- Linux kernel supports loadable device drivers / kernel modules. These can be added at runtime and can be added without recompiling the entire kernel. They are particularly useful when developing for the kernel and debugging the kernel while the kernel is live.
- After building the C program available in this GitHub, it can be loaded to create a new "pseudo"-file under /proc.
- Current developer / development status can be written and read via the command-line / user-space, helping to keep track of what part of the kernel was last worked on, when it was last worked on, and who last worked on it.
- <i>Project can easily be repurposed to keep track of other information relevant while the Linux OS/kernel is running.</i>

Please view powerpoint (<b>Linux.pptx</b> file in this GitHub) for further details on the project.

***

<b>To Use on a Linux machine:</b>
- download <i>proc_rw.c</i> and <i>Makefile</i> from folder "Code" in this GitHub
- <b>sudo -s</b> - to stay in superuser mode
- <b>cd</b> to where the <i>proc_rw.c</i> and accompanying <i>Makefile</i> are located
- run <b>make</b> command
- <b>make insmod</b> - load the module into the kernel
- <b>lsmod</b> - list kernel modules that are currently running, look for devstate at the top
- <i>To Write: </i><b>echo "Hello world" >> /proc/devstate</b> - updates/overwrites previous development state message
- <i>To Read: </i><b>cat /proc/devstate</b> - get current development state message
- <b>make rmmod</b> - remove module from kernel

***

<b>Tools Used:</b>

<a href="https://www.virtualbox.org/" target="_blank">Virtual Box</a>

Linux distribution / kernel - <a href="https://linuxmint.com/" target="_blank">Linux Mint 19.2 Cinnamon</a>, kernel: <a href="https://www.kernel.org/" target="_blank">4.15.0-54-generic</a>, x86-64 architecture.</b>

<a href="https://github.com/torvalds/linux" target="_blank">Linux Kernel Documentation</a>
