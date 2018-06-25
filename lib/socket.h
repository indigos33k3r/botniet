#ifndef SOCK_H
#define SOCK_H

#include "../lib/SLL.h"

class bot_socket {
	private:
#ifdef __linux__
	int sock, tcp_sock;
#elif _WIN32
#endif
	struct sockaddr_in;
	public:
	int init();
	int bindPeer(node *peer);
	void close();
};

#endif

