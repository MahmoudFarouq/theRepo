#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int main()
{
	string x;
	int client;
	int portNum = 1500;
	int bufSize = 1024;
	char buffer[bufSize];
	
	struct sockaddr_in serverAddress;	
	
		
	//init socket
	client = socket(AF_INET, SOCK_STREAM, 0);	
	
	if(client < 0){
		cout << "Error creating socket.." << endl;
		exit(1);
	}
	cout << "client socket created." << endl;
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(portNum);
			
	//CONNECTING TO  socket
	if(connect(client, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == 0)
	{
		cout << "Connecting..." << endl;
	}
	
	recv(client, buffer, bufSize, 0);
	cout << "connection confirmed" << endl;
	
	do{
		cout << "Client: ";
		getline(cin, x, '\n');
		char *buffer = new char[bufSize];
		for(unsigned i = 0; i < x.length(); i++) buffer[i] = x[i];
		buffer[x.length()] = '\0';
		
		send(client, buffer, bufSize, 0);
		recv(client, buffer, bufSize, 0);
		cout << "Server: " << buffer << endl;
	}while(true);
	
	close(client);
	return 0;
}
