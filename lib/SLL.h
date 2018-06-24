#ifndef SLL_H
#define SLL_H

#include <sys/socket.h>

struct node {
	struct sockaddr addr;
	bool active;
	node *next;
};

class SLL {
	private:
	node *head, *tail;
	public:
	SLL();
	void createnode(struct sockaddr *peer, bool active);
	const char *display();
	void insert_start(struct sockaddr *peer, bool active);
	void insert_end(struct sockaddr *peer, bool active);
	void insert_position(int pos, struct sockaddr *peer, bool active);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
};

#endif

