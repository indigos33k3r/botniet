#include "lib/botniet.h"
#include "lib/socket.h"
#include "lib/SLL.h"

network::network() {
	list *peers = new list;
	socket *sock = new socket;
	for (int i; i < RETRY_LIMIT; i++) {
		if (sock.init == 0)
			break;
	}
	
}

