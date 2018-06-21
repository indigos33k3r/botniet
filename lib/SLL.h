#ifndef SLL_H
#define SLL_H

struct node {
	struct peeraddr;
	bool active;
	node *next;
};

class list {
	private:
	node *head, *tail;
	public:
	list() {
		head=NULL;
		tail=NULL;
	}
	void createnode(struct peer, bool active);
	void display();

};

#endif

