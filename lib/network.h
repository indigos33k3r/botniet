#include "lib/socket.h"
#include "lib/SLL.h"

#ifndef NETWORK_H
#define NETWORK_H

class network {
	private:
	SLL *peers;
	socket *sock;
	public:
	network();
	void server();
};

#endif

