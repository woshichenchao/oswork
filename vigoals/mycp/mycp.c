#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFSIZE 4096

char buf[4096];

int
main(int argc,char **argv)
{
	char * fnin,*fnout;
	int fin,fout,size,k;
	
	size=0;
	
	if ( argc != 3 )
	{
		printf("参数错误！\n");
		exit(1);
	}
	
	fnin=argv[1];
	fnout=argv[2];
	
	if ( (fin=open(fnin,O_RDONLY)) == -1 )
	{
		printf("源文件不存在。\n");
		exit(2);
	}
	
	if ( (fout=open(fnout,O_WRONLY|O_CREAT,0777)) == -1 )
	{
		printf("目标文件打开失败。\n");
		exit(3);
	}
	
	while ( (k=read(fin,buf,BUFSIZE)) > 0 )
	{
		size+=k;
		write(fout,buf,k);
	}
	
	printf("文件大小：%d\n",size);
	
	return 0;
}