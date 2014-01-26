//forkit version 2 20120730
//ver4 from ver2 20120816
//ver5 from ver4 20121229
//ver6 from ver5 20130217
//ver7 from ver6 20130629, but this is silent mode
//Copyright(c) 2012-2013 Yukimasa Sugizaki. All rights reserved.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

void perror_and_die(char* str)
{
	perror(str);
	exit(errno);	//TODO: is it correct?
}

int main(int argc, char*argv[]){
	int i;
	int fd;
	char str[0xff];

	if(argc==1){
		strncpy(str, "Usage: forkit [command] [args]...\n", 0xff);
		write(2, str, strlen(str));
		exit(EXIT_FAILURE);
	}
	if((fd=open("/dev/null", O_RDWR))<0)
		perror_and_die("open");
	if(!fork()){
		for(i=0; i<2+1; i++)
			if(dup2(fd, i)<0){
				sprintf(str, "dup2(%d)", i);
				perror(str);
				i=errno;
				close(fd);
				exit(i);
			}
		execvp(argv[1], &argv[1]);
		close(fd);
		sprintf(str, "execvp: %s", argv[1]);
		perror_and_die(str);
	}else if(errno){
		perror_and_die("fork");
	}
	return 0;
}
