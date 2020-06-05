#include "SpectrumServer.h"
#include "UDPServer.h"

extern volatile bool work;
extern string globallmess;
extern Mutex globallmess_busy;
extern volatile double numbermess;
extern volatile double numberSentmess;

void udpsend(int sockfd, const char *msg, sockaddr_in cliaddr){
	socklen_t addrlen = sizeof(cliaddr);
	
	//size_t sendlen = MIN(&msg, 1024);
    //size_t remlen  = msg;
    
	size_t msglen  = strlen(msg);
	
	if (msglen < 1024){
		sendto(sockfd, (const char *)msg, msglen,
			MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
			addrlen);
	}
	else {
		size_t sendlen = MIN(msglen, 1024);
		size_t remlen  = msglen;
		const char * curpos = msg;
		Cerr()<< "curpos = "<<curpos <<"\n";
		
		while (remlen > 0)
		{
			ssize_t len = sendto(sockfd, (const char *)curpos, sendlen,
								MSG_CONFIRM, //MSG_CONFIRM, 
								(const struct sockaddr *) &cliaddr,
								addrlen);
			
			Cerr()<< len <<"\n";
			if (len == -1)
	            {break;}
			curpos += len;
			remlen -= len;
			sendlen = MIN(remlen, 1024);
			Cerr()<< len << " = " << remlen<<"\n";
		}
	}
	Cerr()<<"Сообщение отправлено______D0/1\n";
}

void UDPServer(){
	Cerr() << "UDPServer \n";
	
	int sockfd;
	char buffer[MAXLINE];
	//char modifiableString[] = "Hello from client";
	//char *hello = modifiableString;
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE); 
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 ) 
	{
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	}
	
	socklen_t len = sizeof(cliaddr);
	int in = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len);
	
	buffer[in] = '\0';
	Cerr()<<"Client : " << buffer << "\n";
	
	Cerr()<<"Сообщение получено______D0/1\n";
	
	for(;;){
		if (numbermess > numberSentmess){
			Cerr()<<"Debug___0/1";
			
			globallmess_busy.Enter();
			string mess;
			mess = globallmess;
			numberSentmess+=1;
			globallmess_busy.Leave();
						
			Cerr()<<mess.length()<<"\n";
			Cerr()<<"mess = " << mess.c_str() <<"\n";
			
			const char *msg = mess.c_str();
			
			Cerr()<< "msg = "<<msg <<"\n";
			udpsend(sockfd, msg, cliaddr);
		}
	}
}
