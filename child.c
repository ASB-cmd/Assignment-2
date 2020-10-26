#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#define PORT 8080

int main(int argc,char const*argv[]){
int ns,uP,valread; // ns= new socket uP= user previlege
char *hello= "hello from server";
char buffer[1024]={0};
	if(argc>1){
	ns=*argv[1];
	hello=argv[2];
	}

	else{
	printf("argument is illegal");
	}

	 printf("In the child\n");
    int privilegeValue= setuid(99999);

    if(privilegeValue==-1){
    printf("Privilege were not dropped");
    exit(EXIT_FAILURE);
    }

    valread=read(ns,buffer,1024);
    printf("child sent message-hello");
    send(ns,hello,strlen(hello),0);
    
    return 0;
}