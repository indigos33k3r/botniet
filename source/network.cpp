#include <thread>

#include "../lib/botniet.h"
#include "../lib/network.h"
#include "../lib/socket.h"
#include "../lib/SLL.h"

using namespace std;

network::network() {
	peers = new SLL;
	sock = new socket;
	// TODO: fill sock->sockaddr_in
	for (int i = 0; i < RETRY_LIMIT; i++) {
		if (sock.init == 0)
			break;
	}
	thread server(network.server);
	server.detach();
}

void network::server() {
	
}

