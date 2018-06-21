#ifdef __DEBUG__
#include <iostream>
using namespace std;
#endif

#import <arpa/inet.h>

#include "lib/SLL.h"

void list::createnode(struct peer, bool active) {
	node *temp = new node;
	temp->peeraddr = peer;
	temp->peeractive = active;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

const char *list::display() {
	node *temp = new node;
	temp = head;
	ret = "";
#ifdef __DEBUG__
	cout << inet_ntoa(temp->peeraddr.sin_addr.s_addr) << ":" << temp->peeraddr.sin_port;
#endif
	strcat(ret, inet_ntoa(temp->peeraddr.sin_addr.s_addr));
	strcat(ret, ":");
	strcat(ret, temp->peeraddr.sin_port);
	temp = temp->next;
	while (temp != NULL) {
#ifdef __DEBUG__
		cout << " " << inet_ntoa(temp->peeraddr.sin_addr.s_addr) << ":" << temp->peeraddr.sin_port;
#endif
		strcat(ret, " ");
		strcat(ret, inet_ntoa(temp->peeraddr.sin_addr.s_addr));
		strcat(ret, ":");
		strcat(ret, temp->peeraddr.sin_port);
		temp = temp->next;
	}
}

void list::insert_start(struct peer, bool active) {
	node *temp = new node;
	temp->peeraddr = peer;
	temp->active = active;
	temp->next = head;
	head = temp;
}

void list::insert_end(struct peer, bool active) {
	node *temp = new node;
	temp->peeraddr = peer;
	temp->active = active;
	tail->next = temp;
	tail = temp;
}

