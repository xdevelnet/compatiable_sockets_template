#include <stdio.h>

#if defined(_WIN32)
#include <winsock2.h>
typedef int socklen_t;
#define close(a) closesocket(a)
#define SOCKOPT_ARG_COMPAT(a) ((const char *) a)
#define SOCKINIT WSADATA WsaData;WSAStartup( MAKEWORD(2,2), &WsaData );
#define SOCKSTOP WSACleanup();
#if !defined(__GNUC__)
#pragma comment(lib, "Ws2_32.lib")
#endif
#else
#define SOCKOPT_ARG_COMPAT(a) ((void *) a)
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define SOCKINIT
#define SOCKSTOP
#endif

#include <sys/types.h>
#include <stdlib.h>
#include <iso646.h>

#define strizeof(a) (sizeof(a)-1)

const char payload1[] = "here is payload1\n";
const char payload2[] = "here is payload2\n";

int main() {
	SOCKINIT
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd < 0) {
		perror("can't socket");
		exit(EXIT_FAILURE);
	}
	int optval[1] = {1};
	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, SOCKOPT_ARG_COMPAT(optval), sizeof(optval)) < 0) {
		perror("can't setsockopt");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in myaddr = {.sin_family = AF_INET, .sin_port = htons(8888), .sin_addr.s_addr = INADDR_ANY};
	if (bind(fd, (struct sockaddr *) &myaddr, sizeof(myaddr)) < 0) {
		perror("can't bind");
		close(fd);
		exit(EXIT_FAILURE);
	}
	
	char buffer[1000];
	
	ssize_t got = 0;
	
	struct sockaddr incoming_addr[1];
	socklen_t incoming_addr_len[1] = {sizeof(incoming_addr)};
	
	start_over:
	
	got = recvfrom(fd, buffer, sizeof(buffer), 0, incoming_addr, incoming_addr_len);
	if (got < 0) {
		perror("GOT LESS THEN ZERO! OMG!");
		close(fd);
		exit(EXIT_FAILURE);
	}
	
	if (
		sendto(fd, payload1, strizeof(payload1), 0, incoming_addr, *incoming_addr_len) < 0 or
		sendto(fd, payload2, strizeof(payload2), 0, incoming_addr, *incoming_addr_len) < 0
		) {
		perror("can't sendto");
		exit(EXIT_FAILURE);
	}
	
	goto start_over; // I DARE YOU
	
	SOCKSTOP
	
	return EXIT_SUCCESS;
}
