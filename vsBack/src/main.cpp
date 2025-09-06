#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

int main() {

	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	struct sockaddr_in serverAddr, clientAddr;
	int clientSize = sizeof(clientAddr);

	// Initialize Winsock
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Create socket
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	// Bind
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY; // Accept connections on any IP
	serverAddr.sin_port = htons(12345); // Port number

	bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

	// Listen
	listen(serverSocket, SOMAXCONN);
	std::cout << "Server listening on port 12345...\n";

	// Accept a client
	clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
	std::cout << "Client connected!\n";

	// Receive data
	char buffer[512];
	int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

	if (bytesReceived > 0) {
		buffer[bytesReceived] = '\0'; // Null-terminate the string
		std::cout << "Received: " << buffer << std::endl;
	}

	// Send response
	std::string response = "Hello from server!";
	send(clientSocket, response.c_str(), response.size(), 0);

	// Cleanup
	closesocket(clientSocket);
	closesocket(serverSocket);
	WSACleanup();
}