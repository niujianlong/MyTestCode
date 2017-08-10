#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(int argc, char const *argv[])
{
	int fd;
	const char *hello_node = "/dev/hello_ctrl";
	if((fd = open(hello_node,O_RDWR|O_NDELAY))<0){
		printf("hello open %s failed!\n", hello_node);
	}
	else{
		printf("open %s success\n",hello_node);
	}
	close(fd);
	return 0;
}
