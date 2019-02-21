#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080

void chat(int sockfd){
	
	char buff[MAX];
	int n;
	while(1){
		memset(buff,0,MAX);
		read(sockfd,&buff,sizeof(buff));
		printf("From client: %s\t To cilent : ",buff);
		memset(buff, 0, MAX);
		n = 0;
		while((buff[n++] = getchar()) != '\n'){}
		write(sockfd, &buff, sizeof(buff));
		if(strncmp("exit", buff, 4) == 0){
			printf("Server Exit...\n");
			break;
		}
	}	
}

int socket_creation(){
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	return sockfd;
}

void setInformation(struct sockaddr_in *servaddr){
	//initailize
	memset(servaddr, 0, sizeof(servaddr));
	//assign IP, PORT
	servaddr->sin_family = AF_INET;
	servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr->sin_port = htons(PORT);
}

struct sockaddr_in test(){
	struct sockaddr_in test;
	test.sin_family = AF_INET;
	test.sin_addr.s_addr = htonl(INADDR_ANY);
	test.sin_port = htons(PORT);
	return test;
}

int main(){

	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	
	if((sockfd = socket_creation())  == -1){
		printf("socket creation failed...\n");
		return 0;
	}else{
		printf("Socket successfully created..\n");
	}
	
	setInformation(&servaddr);
	
	//Binding newly created socket to given IP and verifica
	if((bind(sockfd, (struct sockaddr_in*)&servaddr,
				       	sizeof(servaddr))) != 0){
		printf("socket bind failed...\n");
		return 0;
	}else{
		printf("Socket successfully binded...\n");
	}

	if((listen(sockfd, 5)) != 0){
		printf("Listen failed...\n");
		return 0;
	}else{
		printf("Server listening...\n");
	}
	
	len = sizeof(cli);

	connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
	if (connfd < 0){
		printf("server accept failed...\n");
		return 0;
	}else{
		printf("Server accept the client...\n");
	}
	
	chat(connfd);

	close(sockfd);

	return 0;
}

