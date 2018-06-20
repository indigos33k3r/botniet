#include "lib/socket.h"
#include "lib/SLL.h"

#ifdef __linux__
#include <socket.h>

int socket::init() {
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1) {
		return 0;
	}
	list peers;
	return 1;
}

int socket::addPeer(const char *addr, uint16_t port) {
	peers.
}

#elif _WIN32
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>

int socket::init() {
	
}

#endif

