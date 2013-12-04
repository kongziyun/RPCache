#include<math.h>
#include <stdio.h>
unsigned int timestamp(){
  unsigned a, d;
  asm volatile("rdtsc" : "=a"(a), "=d"(d));
  return ((unsigned long)a) | (((unsigned long)d)<<32);
}


void main(void){

  char array[20];
  int i,j;
  unsigned int start, end;

  for (j = 0; j < 20; ++j){
  for (i = 0; i < 20;++i){
    start = timestamp();
   if(i < 15)
      m5_setpid(0);
   else
      m5_setpid(1);
    array[i] = '1';
    end = timestamp();
    printf("%d\t%d\ttime in between: %d\n", j , i, end - start);
  }
m5_unsetpid(0);
m5_unsetpid(1);
  printf("\n\n");
  }
}
