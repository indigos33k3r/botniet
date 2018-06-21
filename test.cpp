#include <iostream>

using namespace std;

#include "lib/SLL.h"

void SLL_test() {
	list SLL;
	SLL.createnode(25);
	SLL.createnode(50);
	SLL.createnode(90);
	SLL.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	SLL.insert_start(55);
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	SLL.insert_start(50);
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	SLL.insert_position(5,60);
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	SLL.delete_first();
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	SLL.delete_last();
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	SLL.delete_position(4);
	cout << SLL.display() << endl;
	cout<<"\n--------------------------------------------------\n";
}

int main(int argc, char *argv[]) {
	SLL_test();
	return 0;
}

