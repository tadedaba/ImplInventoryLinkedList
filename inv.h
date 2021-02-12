/*
  *** This is the "inv.h" header file. ****
	It contain the following three main parts.
		1. The class MyInventory
			=> This class hosts:
				--> The private data type struct
				--> The private function get_node()  
					to declare and initialize
					the struct object.  
				--> The public constructors 
					- LinkedList() declaration and implimentation
					- LinkedList(const LinkedList& source) declaration.
				--> The declaration of eight public functions & one friend function.
		2. The implementation of the friend function outside the class.
	Precondition for this program to run properly:
		=> The program can read in file from the local machine only. 
	Postcondition for the program 
		=> It can handle any number of items.
		=> It lists the items from smallest to the largest inventory number.
		=> It performs the following functions:
			-> retaining the copy of the original data
			-> inserting new item
			-> deleting an item
			-> re-initializing the list to empty
			-> searching and returning the kth value of the list
			-> looking up for an item in the list
			-> checking if the list content for emptiness
			-> print the list on the screen
			-> counting the number of items in the list.
*/
#include <iostream>
#include <iomanip>
#ifndef _INV
#define _INV
#include <ostream>
#include <string>
#include <fstream>
using namespace std;
class MyInventory{
	private:
		struct Node{
			long int num;
			string name;
			double price;
			int quantity;
			Node * next;
			Node * last;
	};
	Node * head; 
	Node * getNode(long int num_0, string name_0, 
				double p_0, int q_0, Node * list);
	public:
		MyInventory(){		//default constructor
			head = NULL;
		}
		MyInventory(const MyInventory& source);	// copy constructor
		~MyInventory();	// destructor 
		// to re-initialize the list to empty. The make_empty() function 
		// is absent becouse it will have the same function as re_initialize()
		//void re_Initialize(); 
		void insert(long int new_num, string new_name, 
				double new_p, int new_q);			//to insert items to the list
		void remove(long int old_num); 		//to remove items from the list
		void operator = (MyInventory source); //"="Operator overloading 
		bool isEmpty(); 			//to check if the list is empty or not
		int listLength(); 		//to get the number of nodes in the list
		bool isPresent(long int t_num); //to check if an item is in the list
		void make_empty();
		//to access the kth item of the list
		long int kthValue(long int numval);	
		//the friend function is used for the purpose of 
		//"<<" operator overloading. 
		friend ostream& operator << (ostream& out_s, const MyInventory& l);
		void readFile(ifstream& in);
};
// Implimentation of the friend function.
ostream& operator << (ostream& out_s, const MyInventory& l){
	double total = 0;
	MyInventory::Node * ptr;
	ptr = l.head;
	cout << left << setw(8) << "Number"
		 		 		<< "   " << "Name" 
						<< "     " << "UnitPrice" 
						<< "   " <<"Quantity" 
						<< "       " << "Value" << endl;
	cout << "--------------------------------------------------------\n";
	while(ptr -> next != NULL){
		cout << left << setw(10) << fixed;
		out_s << ptr -> num 
			  << left << fixed << setw(10)<<ptr -> name << setprecision(2) 
			  << "$ " << left << fixed << setw(10) << ptr -> price 
			  << left << fixed << setw(14)<<ptr -> quantity << setprecision(2) 
			  << "$ " <<left << fixed << setw(8)<< (ptr ->price) * (ptr ->quantity)
						  << endl;
		ptr = ptr -> next;
		total = total + (ptr ->price) * (ptr ->quantity);
	}
	cout << "--------------------------------------------------------\n";
	cout << "Total value of inventory =                 $ " << total <<endl; 
	return out_s;
}
#endif	//end of header file definition.
/* =======================================================================*/
