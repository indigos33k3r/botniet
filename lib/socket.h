#ifndef SOCK_H
#define SOCK_H

class bot_socket {
	private:
#ifdef __linux__
	int sock, tcp_sock;
#elif _WIN32
#endif
	struct sockaddr_in;
	public:
	int init();
	int bindPeer(struct *peerAddr);
	void close();
};

#endif

