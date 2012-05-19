#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUFFSIZE 4096
#define err_sys(err) {printf(err);exit(1);}
int
main(int argc,char* argv[])
{
	int fd1,fd2,n;
	char buf[BUFFSIZE];
	if((fd1=open(argv[1],O_RDWR,0777))==-1)
		err_sys("open error!");
	fd2=open(argv[2],O_RDWR|O_CREAT,0777);
	n=read(fd1,buf,BUFFSIZE);
	write(fd2,buf,n);
	printf("%d\n",n);
	if(n<0)
		err_sys("read error!");
	
	exit(0);
}
