#include <stdio.h>

const int i = 0;
int main(){
   int * p = &i;
   *p = 2;
   printf("i=%d\n",i);
   return 1;
		
}
