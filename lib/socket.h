#ifndef SOCK_H
#define SOCK_H

class socket {
	private:
	int sock;
	struct sockaddr_in;
	public:
	int init();
	int bindPeer(struct peerAddr);
};

#endif

