#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int
main (int argc,char *argv[])
{
	int n,fd1,fd2;
	char buf[4096];
	if((fd1=open(argv[1],O_RDWR,0777))<0)
	{
		printf("%s isn't found!\n",argv[1]);
		exit(-1);
	}
	fd2=open(argv[2],O_RDWR|O_CREAT,0777);
	n=read(fd1,buf,4096);
	write(fd2,buf,n);
	printf("the size of first file :%d\n",n);
	exit(0);
}
