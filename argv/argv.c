#include <stdio.h>
int main(int argc, char *argv[]){
	while(argc--){
		printf("argv[%d] = %s\n",argc,argv[argc]);
	}
}
