#ifdef __DEBUG__
#include <iostream>
using namespace std;
#endif

#import <arpa/inet.h>

#include "lib/SLL.h"

list::list() {
	head=NULL;
	tail=NULL;
}

void list::createnode(struct peer, bool active) {
	node *temp = new node;
	temp->addr = peer;
	temp->active = active;
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
	return ret;
}

void list::insert_start(struct peer, bool active) {
	node *temp = new node;
	temp->raddr = peer;
	temp->active = active;
	temp->next = head;
	head = temp;
}

void list::insert_end(struct peer, bool active) {
	node *temp = new node;
	temp->addr = peer;
	temp->active = active;
	tail->next = temp;
	tail = temp;
}

void list::insert_position(int pos, struct peer, bool active) {
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	cur = head;
	for  (int i; i < pos, i++) {
		pre = cur;
		cur = cur->next;
	}
	temp->addr = peer;
	temp->active = active;
	pre->next = temp;
	temp->next = cur;
}

void list::delete_first() {
	node *temp = new node;
	temp = head;
	head = temp->next;
	delete temp;
}

void list::delete_last() {
	node *pre = new node;
	node *cur = new node;
	cur = head;
	while (cur->next != NULL) {
		pre = cur;
		cur = cur->next;
	}
	tail = pre;
	pre->next = NULL;
	delete cur;
}

void list::delete_position(int pos) {
	node *pre = new node;
	node *cur = new node;
	cur = head;
	for (int i; i < pos; i++) {
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
	delete cur;
}

