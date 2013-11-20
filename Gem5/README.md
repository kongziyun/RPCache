Gem5
=======

1. Build Gem5:

	$ scons build/ARM/gem5.opt
	For X86: scons build/X86/gem5.opt

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


5. To use the new pseudo instruction call the function declared in util/m5/m5op.h. 
   Then (cross-)compile your source code with the m5 utilities like:
  	gcc -o foo foo.c -I ${GEM5}/util/m5 ${GEM5}/util/m5/m5op_x86.S


   To get your code into the simulation, you can add the binary to the disk image 
	sudo mount -o loop,offset=32256 /dist/m5/system/disks/linux-x86.img /mnt/tmp cp foo /mnt/tmp/bin
   or read it directly into the simulation 
	build/X86/gem5.debug configs/example/fs.py -r 1 --script=foo m5term localhost 3456 
	m5 readfile > foo chmod +x foo ./foo
   Adding to the disk image requires restarting the simulation, 
   whereas if you have a checkpoint loaded you can read the file in directly using m5 readfile.
