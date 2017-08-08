#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

typedef enum {
	BUZZER_OFF, BUZZER_ON
} BUZZER_CMD;

int main(int argc, char *argv[]) {
	int fd;
	//const char *buzzer = "/dev/buzzer_ctl";
	char *buzzer_ctl = "/dev/buzzer_ctl";
	/**/
	while(argc--)
	{
		printf("argv[%d] = %s\n",argc,argv[argc]);
	}
	/*fd = open(buzzer, O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd < 0) {
		printf("%s open faild\n", buzzer);
	}*/
	if((fd = open(buzzer_ctl,O_RDWR|O_NOCTTY|O_NDELAY))<0){
			printf("open %s failed\n",buzzer_ctl);
			exit(1);
		}
	switch (atoi(argv[1])) {
	case BUZZER_OFF:
		ioctl(fd, atoi(argv[1]), atoi(argv[2]));
		break;
	case BUZZER_ON:
		ioctl(fd, atoi(argv[1]), atoi(argv[2]));
		break;
	default:
		printf("only 0 or 1 permit\n");
		break;

	}
	close(fd);
#if 0
	printf("argv[1] is led_index LED1 = 0 , LED2 = 1 \n argv[2] is cmd  0 is light off 1 is light on;\n");

	if(argc != 3)
	{
		printf("you need input led_index and led_cmd\n");
	}

	if((atoi(argv[1]) != LED1) && (atoi(argv[1]) != LED2) )
	{
		printf("argv[1] is led_index  LED1 = 0 or LED2 = 1 is permited\n");
		exit(1);
	}
	else if((atoi(argv[2]) != LIGHT_OFF) && (atoi(argv[2]) != LIGHT_ON) )
	{
		printf("argv[2] is cmd LIGHT_OFF = 0 or LIGHT_ON = 1 is permited\n");
		exit(1);
	}
	else
	{
		if((fd = open(leds,O_RDWR|O_NOCTTY|O_NDELAY))< 0)
		{
			printf("open %s failed\n",leds);
			exit(1);
		}
		else
		{
			switch(atoi(argv[2]))
			{
				case LIGHT_OFF:
				ioctl(fd,atoi(argv[1]),atoi(argv[2]));
				printf("Led%d is LIGHT_OFF",atoi(argv[1]));
				break;
				case LIGHT_ON:
				ioctl(fd,atoi(argv[1]),atoi(argv[2]));
				printf("Led%d is LIGHT_ON",atoi(argv[1]));
				break;
				default:
				break;
			}
		}
		close(fd);
	}
#endif
	return 1;
}
