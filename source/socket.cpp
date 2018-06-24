#include "lib/socket.h"

#ifdef __linux__
#include <sys/socket.h>

int socket::init() {
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
		return 1
	tcp_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
		return 1
	return 0;
}

int socket::bindPeer(node *peer) {
	for (int i; i < RETRY_LIMIT; i++) {
		if (bind(sock, (struct sockaddr *)&peer->addr, sizeof(peer->addr)) < 0)
			continue;
		else
			break;
	}
	peer->active = 1;
}

void socket::close() {
	close(sock)
}

#elif _WIN32
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>

int socket::init() {
	
}

#endif

