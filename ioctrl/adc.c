#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fd,r = 0,i = 0;
	const char *adc = "/dev/adc";
	char buffer[512];
	int len = 0;

	memset(buffer,0,sizeof(buffer));
	printf("sizeof(buffer) = %d\n",sizeof(buffer));
	if((fd = open(adc,O_RDWR|O_NOCTTY|O_NDELAY))<0) {
		printf("open %s failed\n",adc);
		exit(1);
	}
	else
	{
		len = read(fd,buffer,10);
		for(i = 0;i<10;i++)
		{
			printf("buffer[%d] = %s\n",i,buffer[i]);

		}
		if(len == 0)
		{
			printf("read error\n");
		}
		else
		{
			r = atoi(buffer);
			printf("r raw =%d\n",r);
			r = (int) (r*10000/0xfff);
			printf("r=%d\n",r);
		}
	}

}

