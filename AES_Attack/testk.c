#include<math.h>
#include <stdio.h>
unsigned int timestamp(){
  unsigned a, d;
  asm volatile("rdtsc" : "=a"(a), "=d"(d));
  return ((unsigned long)a) | (((unsigned long)d)<<32);
}


void main(void){

  char arrayA[64];
  char arrayB[64];
  int i,j;
  unsigned int start, end;
  arrayB[32]='d';
  m5_setpid(0);

  for (i = 0; i < 64; ++i)
    arrayA[i] = '1';

//  m5_setpid(-1);

  printf("sddd\n");
  for (i = 0; i < 64;++i){
   
      m5_setpid(0);
      start = timestamp();
      arrayA[i] = '3';
      end = timestamp();
      
  //    m5_setpid(-1);
      printf("%d\t A\ttime in between: %d\n", i, end - start);

      start = timestamp();
      arrayB[i] = '4';
      end = timestamp();
      printf("%d\t B\ttime in between: %d\n", i, end - start);

      printf("what \n");
  } 




  for (j = 0; j < 3; ++j)
  for (i = 0; i < 64; ++i){
    m5_setpid(0);
    start = timestamp();
    arrayA[i] = '3';
    end = timestamp();
    printf("%d\t A\tseperate time: %d\n", i, end - start);
  }

//m5_setpid(-1);
printf("\n");

  for (i = 0; i < 64; ++i){
    start = timestamp();
    arrayB[i] = '3';
    end = timestamp();
    printf("%d\t B\tseperate time: %d\n", i, end - start);
  }

  //m5_unsetpid(0);
  //m5_unsetpid(1);
  printf("\n\n");
  
m5_setpid(1);
}
