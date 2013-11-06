Gem5
=======

1. Build Gem5:

	$ scons build/ARM/gem5.opt


2. Run full-system simulation arm on ubuntu:

	$ cd 
	$ mkdir full_system_images
	$ cd ~/full_system_images
	$ wget http://www.m5sim.org/dist/current/arm/arm-system-2011-08.tar.bz2
	$ tar jxf arm-system-2011-08.tar.bz2
	$ echo "export M5_PATH=/home/[username]/full_system_images/" >> ~/.bashrc
	$ source ~/.bashrc
	
	$ cd /PATH_TO_GEM5
	$ build/ARM/gem5.opt configs/example/fs.py --disk-image=/home/[username]/full_system_images/disks/arm-ubuntu-natty-headless.img [--mem-size=256MB]

3. Connect to simulator, open another terminal:

	$ telnet localhost 3456

4. If you want to run a program without using full-system simulation

	1). Install x compiler

		$ sudo apt-get install arm-linux-gnueabi
		
	2). Compile your code

		$ arm-linux-gnueabi-gcc -static -o output source.c

	3). Run program, first line for generating help information
	
		$ build/ARM/gem5.opt configs/example/se.py -h 
		$ build/ARM/gem5.opt configs/example/se.py -c PATH_TO_BINARY_FILE

