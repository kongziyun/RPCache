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
  //arrayB[32]='d';
  printf("%ld\n", sizeof(unsigned long long));
  m5_setpid(1);

  for (i = 0; i < 64; ++i)
    arrayA[i] = '1';

  m5_setpid(0);
  for (i = 0; i < 64; ++i)
  {
    m5_setpid(1);
    start = rdtsc();
    arrayA[i] = '1';
    end = rdtsc();
    m5_setpid(0);
    printf("A: %d\ttime:%lld\n", i, end - start);

    start = rdtsc();
    arrayB[i] = '1';
    end = rdtsc();
    printf("B: %d\ttime:%lld\n\n", i, end - start);

 }

  printf("sddd\n");
   for (j = 0; j < 3; ++j)
  for (i = 0; i < 64;++i){
   
     start = rdtsc();
      arrayB[i] = '4';
      end = rdtsc();
      printf("%d\t B\ttime in between: %lld\n", i, end - start);
  }

  printf("sdfsdf\n\n");
 m5_unsetpid(1);  
  for (j = 0; j < 3; ++j)
  for (i = 0; i < 64;++i){
   
     start = rdtsc();
      arrayB[i] = '4';
      end = rdtsc();
      printf("%d\t B\ttime in between: %lld\n", i, end - start);
  }



 
}
