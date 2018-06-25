#ifdef __DEBUG__
#include <iostream>
using namespace std;
#endif

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#include "../lib/SLL.h"

SLL::SLL() {
	head = 0;
	tail = 0;
}

void SLL::createnode(struct sockaddr *peer, bool active) {
	node *temp = new node;
	temp->addr = peer;
	temp->active = active;
	if (head == 0) {
		head = temp;
		tail = temp;
		temp = 0;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

/*const char *SLL::display() {
	node *temp = new node;
	temp = head;
	const char *ret = "";
#ifdef __DEBUG__
	cout << inet_ntoa(temp->addr->sin_addr.s_addr) << ":" << temp->addr.sin_port;
#endif
	strcat(ret, inet_ntoa(temp->addr->sin_addr.s_addr));
	strcat(ret, ":");
	strcat(ret, temp->addr->sin_port);
	temp = temp->next;
	while (temp != 0) {
#ifdef __DEBUG__
		cout << " " << inet_ntoa(temp->addr->sin_addr.s_addr) << ":" << temp->addr.sin_port;
#endif
		strcat(ret, " ");
		strcat(ret, inet_ntoa(temp->addr->sin_addr.s_addr));
		strcat(ret, ":");
		strcat(ret, temp->addr->sin_port);
		temp = temp->next;
	}
	return ret;
}*/

void SLL::insert_start(struct sockaddr *peer, bool active) {
	node *temp = new node;
	temp->addr = peer;
	temp->active = active;
	temp->next = head;
	head = temp;
}

void SLL::insert_end(struct sockaddr *peer, bool active) {
	node *temp = new node;
	temp->addr = peer;
	temp->active = active;
	tail->next = temp;
	tail = temp;
}

void SLL::insert_position(int pos, struct sockaddr *peer, bool active) {
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	cur = head;
	for  (int i; i < pos; i++) {
		pre = cur;
		cur = cur->next;
	}
	temp->addr = peer;
	temp->active = active;
	pre->next = temp;
	temp->next = cur;
}

void SLL::delete_first() {
	node *temp = new node;
	temp = head;
	head = temp->next;
	delete temp;
}

void SLL::delete_last() {
	node *pre = new node;
	node *cur = new node;
	cur = head;
	while (cur->next != 0) {
		pre = cur;
		cur = cur->next;
	}
	tail = pre;
	pre->next = 0;
	delete cur;
}

void SLL::delete_position(int pos) {
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

