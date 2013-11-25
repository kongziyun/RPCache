AES Attack
=========

1. Compiling:

		$ gcc -O3 -o learning learning.c -lcrypto -lm
		$ gcc -O3 -o correlate correlate.c -lm
		$ gcc -O3 -o search search.c -lcrypto

2. [AES_Key] could be [/dev/zero] or generate by hardware:

	$ dd if=/dev/urandom of=secretkey bs=16 count=1

3. Learning phase
	
	$ ./learning [PACKET_SIZE] [NUMBER_OF_PACKETS_ORDER_OF_2] < /dev/zero > study.[PACKET_SIZE].[ORDER_OF_2]

4. Attacking phase

	$ ./learning [PACKET_SIZE] [NUMBER_OF_PACKETS_ORDER_OF_2] < secretkey > attack.[PACKET_SIZE].[ORDER_OF_2]

5. Analyzing (make sure that the packet sizes of study_stats and attack_stats are the same). 

	$ (tail -256 [STUDY_STATS]; tail -256 [ATTACK_STATS]) | ./correlate >> attack
	$ cat attack	

6. Searching secret key

	$ ./search < attack

