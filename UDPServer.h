#ifndef _SpectrumServer_UDPServer_h_
#define _SpectrumServer_UDPServer_h_

// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define MAXLINE 1024 
#define PORT	3000 

using namespace std;

void udpsend(int sockfd, const char *msg, sockaddr_in cliaddr);

#endif
