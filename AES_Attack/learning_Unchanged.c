#include <netinet/in.h>
#include <openssl/aes.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <poll.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
double packets;
double ttotal;
double t[16][256];
double tsq[16][256];
long long tnum[16][256];
double u[16][256];
double udev[16][256];
char n[16];
int s;
int size;
unsigned char key[16];
AES_KEY expanded;
unsigned char zero[16];
unsigned char scrambledzero[16];
/*
unsigned int timestamp(void)
{
  unsigned int bottom;
  unsigned int top;
  asm volatile(".byte 15;.byte 49" : "=a"(bottom),"=d"(top)); return bottom;
}
*/
unsigned int timestamp(){
  unsigned a, d;
  asm volatile("rdtsc" : "=a"(a), "=d"(d));
  return ((unsigned long) a) | (((unsigned long)d)<<32);
}

void handle(char out[40],char in[],int len) {
  unsigned char workarea[len * 3]; int i;
  for (i = 0;i < 40;++i) out[i] = 0; 

  //*(unsigned int *) (out + 32) = timestamp();

  if (len < 16) return;
  i = 0;
	//for (i = 0;i < 1;++i) 
	out[i] = in[i];
  for (i = 16;i < len;++i) workarea[i] = in[i];
  *(unsigned int *)(out + 32) = timestamp(); 
	AES_encrypt(in,workarea,&expanded);
  /* a real server would now check AES-based authenticator, */ /* process legitimate packets, and generate useful output */
  //for (i = 0;i < 1;++i) 
  *(unsigned int *) (out + 36) = timestamp();
  i = 0;
	out[16 + i] = scrambledzero[i];
  //*(unsigned int *)(out + 36) = timestamp();
}


struct sockaddr_in server;
struct sockaddr_in client; socklen_t clientlen; int s;
char in[1537];
int r;
char out[40];

void tally(double timing) {
  int j;
  int b;
	j = 0;
  //for (j = 0;j < 1;++j) {
    b = 255 & (int) n[j]; ++packets;
    ttotal += timing;
    t[j][b] += timing;
    tsq[j][b] += timing * timing; tnum[j][b] += 1;
  //}
}

void printpatterns(void)
{
  int j;
  int b;
  double taverage;
  taverage = ttotal / packets;
  j = 0;
  //for (j = 0;j < 16;++j) {
  for (b = 0;b < 256;++b) {
    u[j][b] = t[j][b] / tnum[j][b]; udev[j][b] = tsq[j][b] / tnum[j][b]; udev[j][b] -= u[j][b] * u[j][b]; udev[j][b] = sqrt(udev[j][b]);
    printf("%2d %4d %3d %lld %.3f %.3f %.3f %.3f\n" ,j
           ,size
           ,b
           ,tnum[j][b]
           ,u[j][b]
           ,udev[j][b]
           ,u[j][b] - taverage
           ,udev[j][b] / sqrt(tnum[j][b])
           );
  }
  //}
  fflush(stdout);
}
int timetoprint(long long inputs) {
  if (inputs < 10000) return 0;
  if (!(inputs & (inputs - 1))) return 1; return 0;
}


main(int argc,char **argv) {
  
  if (read(0,key,sizeof key) < sizeof key) return 111; 
  AES_set_encrypt_key(key,128,&expanded); 
  AES_encrypt(zero,scrambledzero,&expanded);
  int power2=4;
  int j;
  //size = atoi(argv[1]);
  size = 16;
  char packet[2048];
  char out[40];
  struct pollfd p;
  long long inputs = 0;
  
  // study;
  for (;;){
    for (;;){
      if (size < 16) continue;
      if (size > sizeof packet) continue;
      for (j = 0; j < size; ++j)
        packet[j] = random();
	  	j = 0;
//    for (j = 0; j < 1; ++j)
      n[j] = packet[j];
      handle(out,packet,size);
      unsigned int timing;
      timing = *(unsigned int *) (out + 36);
      timing -= *(unsigned int *) (out + 32);
      
      if (timing < 10000){
        //printf("tally\n");
        tally(timing);break;
      }
    }
  
  ++inputs;
  if (timetoprint(inputs)){
    printpatterns();
//	  printf("remove %lld\t%d\n",inputs,++power2);
  }
//  if (power2 == atoi(argv[2])) {
  if (power2 == 17){
	//printpatterns();
return 1;
}
  }
}
