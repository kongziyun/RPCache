#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rdtsc.h"
#include <openssl/aes.h>
#define UNLIMIT
#define MAXARRAY 60000 /* this number, if too large, will cause a seg. fault!! */

struct myStringStruct {
  char qstring[128];
};

int compare(const void *elem1, const void *elem2)
{
  int result;
  
  result = strcmp((*((struct myStringStruct *)elem1)).qstring, (*((struct myStringStruct *)elem2)).qstring);

  return (result < 0) ? 1 : ((result == 0) ? 0 : -1);
}


int
main(int argc, char *argv[]) {
  struct myStringStruct array[MAXARRAY];
  FILE *fp;
  int i,count=0;
  unsigned char key[16], zero[16], scrambledzero[16];
  AES_KEY expanded;
  unsigned long long start; 
  if (argc<2) {
    fprintf(stderr,"Usage: qsort_small <file>\n");
    exit(-1);
  }
  else {
    fp = fopen(argv[1],"r");


  if (read(0, key, sizeof key) < sizeof key) return 111;
  AES_set_encrypt_key(key, 128, &expanded);
  m5_setpid(1);
  AES_encrypt(zero, scrambledzero, &expanded);
  m5_setpid(0);
      

  start = rdtsc();
    while((fscanf(fp, "%s", &array[count].qstring) == 1) && (count < MAXARRAY)) {
	 count++;
    }
  }
  printf("\nSorting %d elements.\n\n",count);
  qsort(array,count,sizeof(struct myStringStruct),compare);
  
  for(i=0;i<count;i++)
    printf("%s\n", array[i].qstring);
  start = rdtsc() - start;
  printf("\n\nCycle count: %lld\n\n", start);
  return 0;
}
