#ifndef SLL_H
#define SLL_H

struct node {
	struct addr;
	bool active;
	node *next;
};

class SLL {
	private:
	node *head, *tail;
	public:
	SLL();
	void createnode(struct peer, bool active);
	void display();
	void insert_start(struct peer, bool active);
	void insert_end(struct peer, bool active);
	void insert_position(struct peer, bool active);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
};

#endif

