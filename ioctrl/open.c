#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
	int fd;
	char *leds = "/dev/leds";
	char *leds1 = "/bin/test1";
	char *leds2 = "/dev/test2";

	if((fd = open(leds,O_RDWR|O_NOCTTY|O_NDELAY)) < 0){
		printf("open %s failed!\n",leds);
    }
	printf("%s fd is = %d\n",leds,fd);


	if((fd = open(leds1,O_RDWR,777)) < 0){
		printf("open %s failed!\n",leds1);
    }
	printf("%s fd is = %d\n",leds1,fd);
	
	if((fd = open(leds2,O_RDWR|O_CREAT,777)) < 0){
		printf("open %s failed!\n",leds2);
    }
	printf("%s fd is = %d\n",leds2,fd);

}

