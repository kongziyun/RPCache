#include<math.h>
#include <stdio.h>
#include "rdtsc.h"
unsigned int timestamp(){
  unsigned a, d;
  asm volatile("rdtsc" : "=a"(a), "=d"(d));
  return ((unsigned long)a) | (((unsigned long)d)<<32);
}


void main(void){

  char arrayA[64];
  char arrayB[64];
  int i,j;
  unsigned long long start, end;

  printf("%ld\n", sizeof(unsigned long long));
 for (i = 0; i < 64; ++i)
  {   
    m5_setpid(1); 
    arrayA[i] = 1;
    m5_setpid(0);
  }

 for (j = 0; j < 64;++j){
    for (i = 0; i < 64; ++i){
      start = rdtsc();
      arrayB[i] = 2;
      start = rdtsc() - start;
      printf("%d %d\ttime:%lld\n",i,j, start);
    }
    printf("\n");
  }
 
}
