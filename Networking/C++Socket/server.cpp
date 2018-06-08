#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main()
{
	string x;
	int client, server;
	int portNum = 1500;
	int bufSize = 1024;
	char buffer[bufSize];
	
	struct sockaddr_in serverAddress;
	socklen_t size;
	
	//init socket
	client = socket(AF_INET, SOCK_STREAM, 0);
	if(client < 0)
	{
		cout << "Error establishing conniction" << endl;
		exit(1);
	}
	cout << "Server connection established." << endl;
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htons(INADDR_ANY);
	serverAddress.sin_port = htons(portNum);
	
	//binding socket
	if(bind(client, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0){
		cout << "Error binding socket." << endl;
		exit(1);
	}
	
	size = sizeof(serverAddress);
	cout << "looking for clients" << endl;
	
	//listening socket
	listen(client, 1);
	
	//accept client
	server = accept(client, (struct sockaddr*) &serverAddress, &size);
	
	if(server < 0){
		cout << "Error Accepting socket." << endl;
		exit(1);
	}
	
	send(server, buffer, bufSize, 0);
	cout << "Connected with client..." << endl;
	
	do{
		recv(server, buffer, bufSize, 0);
		cout << "Client: " << buffer << endl;	
		cout << "Server: ";
		
		getline(cin, x, '\n');
		char *buffer = new char[bufSize];
		for(unsigned i = 0; i < x.length(); i++) buffer[i] = x[i];
		buffer[x.length()] = '\0';
		
		send(server, buffer, bufSize, 0);
	}while(true);

	close(client);
	return 0;
}
