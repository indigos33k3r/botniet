#include "../lib/botniet.h"
#include "../lib/socket.h"
#include "../lib/SLL.h"

#ifdef __linux__
#include <sys/socket.h>

int bot_socket::init() {
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
		return 1;
	tcp_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
		return 1;
	return 0;
}

int bot_socket::bindPeer(node *peer) {
	for (int i = 0; i < RETRY_LIMIT; i++) {
		if (bind(sock, (struct sockaddr *)&peer->addr, sizeof(peer->addr)) < 0)
			continue;
		else
			break;
	}
	peer->active = 1;
}

void bot_socket::bot_close() {
	sock.close();
}

#elif _WIN32
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>

int bot_socket::init() {
	
}

int bot_socket::bindPeer(node *peer) {
	
}

void bot_socket::close() {
	WSAcleanup();
	close(sock);
}

#endif

