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
		

		printf("Enter the string :");
		n = 0;
		while((buff[n++] = getchar()) != '\n'){}
		
		write(sockfd, &buff, sizeof(buff));
		memset(buff, 0, sizeof(buff));
		read(sockfd, &buff, sizeof(buff));
		printf("From Server : %s", buff);
		if((strncmp(buff, "exit", 4)) == 0){
			printf("Client Exit...\n");
			break;
		}
	}	
}

int socket_creation(){
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	return sockfd;
}

int main(){
	
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	

	if((sockfd = socket_creation()) == -1){
		printf("socket creation failed...\n");
		return 0;
	}else{
		printf("Socket successfully created..\n");
	}
	
	memset(&servaddr, 0 , sizeof(servaddr));

	//assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	if (connect(sockfd , (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0){
		printf("connection with the server failed...\n");
		return 0;
	}else{
		printf("connected to the server.. \n");
	}
	
	chat(sockfd);

	close(sockfd);
	return 0;
}

