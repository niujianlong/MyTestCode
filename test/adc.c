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
										printf("1\n");
												memset(buffer,0,sizeof(buffer));
														printf("2\n");
																printf("sizeof(buffer) = %d\n",sizeof(buffer));
																		printf("3\n");
																				if((fd = open(adc,O_RDWR|O_NOCTTY|O_NDELAY))<0) {
																						printf("4\n");
																										printf("open %s failed\n",adc);
																														exit(1);
																																}
																																		else
																																				{
																																								printf("5\n");
																																												len = read(fd,buffer,10);
																																																printf("6\n");
																																																				for(i = 0;i<10;i++)
																																																								{
																																																														printf("7\n");
																																																																				printf("buffer[%d] = %c\n",i,buffer[i]);
																																																																										printf("8\n");

																																																																														}
																																																																																		if(len == 0)
																																																																																						{
																																																																																												printf("9\n");
																																																																																																		printf("read error\n");
																																																																																																						}
																																																																																																										else
																																																																																																														{
																																																																																																																				printf("10\n");
																																																																																																																										r = atoi(buffer);
																																																																																																																																printf("11\n");
																																																																																																																																						printf("r raw =%d\n",r);
																																																																																																																																												printf("12\n");
																																																																																																																																																		r = (int) (r*10000/0xfff);
																																																																																																																																																								printf("13\n");
																																																																																																																																																														printf("r=%d\n",r);
																																																																																																																																																																				printf("14\n");
																																																																																																																																																																								}
																																																																																																																																																																														printf("15\n");
																																																																																																																																																																																}
																																																																																																																																																																																						printf("16\n");
																																																																																																																																																																																								return 1;
																																																																																																																																																																																								}


