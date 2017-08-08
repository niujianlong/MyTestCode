#include <stdio.h>

union
{
   unsigned char a[10];
   int i;	
}u;


int main(void)
{
  char b[10];
  int alignerror = 0;
  int k = 0;
  int *p = (int*)&(u.a[1]);
  *p =0xffaa;
  char *pt = &b[1];
  *pt = 0xffffffffff;
  long l = *(long *)pt;
  printf("l = %x\n",l);
  for(k=0;k<10;k++){			
  printf("a=%d\n",u.a[k]);
  }
  *(int*)(((unsigned long)&alignerror) + 1) = 0x1;
  printf("alignerror = %x\n",alignerror);
}
