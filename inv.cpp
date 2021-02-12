/*
	**** This is the "List.cpp" implementation file  ****
	This file implements all the functions defined in the 
	"List.h" header file. Hence it is the file for class
	implimentation. 
*/
#include <iostream>
#include "inv.h"
#include <cstddef>
#include <fstream>
using namespace std;
MyInventory::Node * MyInventory::getNode(long int num_0, 
		string name_0, double p_0, int q_0, Node * list){
	Node * temp;
	temp = new Node;
	temp->num = num_0;
	temp->name = name_0;
	temp->price = p_0;
	temp->quantity = q_0;
	temp->next = list;
	return temp;
}
MyInventory::MyInventory(const MyInventory& source){
	Node * ptr;
	Node * last;
	if(source.head == NULL)
		head = NULL;
	else{
		head = getNode(source.head -> num, 
					   source.head -> name,
					   source.head -> price,
					   source.head -> quantity,
					NULL);
		last = head;
		ptr = source.head -> next;
		while(ptr != NULL){
			last->next = getNode(ptr->num, ptr->name,
								 ptr->price, ptr->quantity, NULL);
			last = last->next;
			ptr  = ptr->next;
		}
	}
}
MyInventory::~MyInventory(){
	Node * temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
}
void MyInventory::operator =(MyInventory source){
	Node * ptr;
	Node * last;
	MyInventory empty;
	if(&source != this){
		empty.~MyInventory();
		
		head = getNode(source.head -> num, 
					   source.head -> name,
					   source.head -> price,
					   source.head -> quantity,
					NULL);
		last = head;
		ptr = source.head -> next;
		while(ptr != NULL){
			last->next = getNode(ptr->num, ptr->name,
								ptr->price, ptr->quantity, NULL);
			last = last->next;
			ptr  = ptr->next;
		}
	}
	else return;
}                                                                                                                                                                                                                                                                                                                                                                                                                 
int MyInventory::listLength(){
	Node * ptr;
	int count = 0;
	ptr = head;
	while(ptr != NULL){
		++count;
		ptr = ptr->next;
	}
	return count;
}
bool MyInventory::isEmpty(){
	Node * ptr;
	ptr = head;
	if(ptr == NULL)
		return true;
	else return false;
}
bool MyInventory::isPresent(long int t_num){
	Node * ptr;
	ptr = head;
	while(ptr != NULL && ptr -> num != t_num){
		ptr = ptr -> next;
	}
	return ptr != NULL;
}
void MyInventory::insert(long int new_num, string new_name, 
				double new_p, int new_q){
	Node* prev;
	if(head == NULL || new_num < head -> num)
		head = getNode(new_num, new_name, new_p, new_q, head);
	else{
		prev = head;
		while(prev -> next != NULL && prev -> next -> num < new_num)
			prev = prev ->next;
		prev -> next = getNode(new_num, new_name, new_p, new_q, 
						       prev -> next);
	}
}
void MyInventory::remove(long int old_num){
	Node * prev;
	Node * temp;
	prev = head;
	if(head -> num == old_num){
		head = head -> next;
		delete prev;
	}
	else{
		while(prev -> next ->num < old_num)
			prev = prev -> next;
		temp = prev -> next;
		prev -> next = temp -> next;
		delete temp;
	}
}
long int MyInventory::kthValue(long int numval){
	Node * prev;
	prev = head->next;
	for(int i = 0; i < numval; i++)
		prev = prev -> next;
	return prev->num;
}
void MyInventory::readFile(ifstream& in){
	Node * last;
	long int num_f; string name_f; double p_f; int q_f; 
	in.open("F:\\School\\CSCI 301\\My Projects ECE 591\\Project 4\\f.dat");
	if (!in)
		cout << " File not found!" << endl;
	else{
		make_empty();
		in >> num_f >> name_f >> p_f >> q_f;
		head->next = getNode(num_f, name_f, p_f, q_f, NULL);
		last = head->next;
		while (!in.eof()){
			last->next = getNode(num_f, name_f, p_f, q_f, NULL);
			last = last->next;
			in >> num_f >> name_f >> p_f >> q_f;
		}
	}	
}
void MyInventory::make_empty(){
	Node * prev;
	prev = head->next;
	if(prev == NULL){}
	else{
		while(prev->next != NULL){
			head->next = prev->next;
			delete prev;
			prev = head->next;
		}
	}
}
/* =======================================================================*/
