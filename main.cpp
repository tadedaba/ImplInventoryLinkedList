/*
	**** This is the "main.cpp" testing file  ****
	This file tests the validity of the class implimentation 
	functions. The "main.cpp" has the following major duties:
	1. It provides the user with a menu choice to enable them 
		to choose from the available menus. It repeats the menu 
		once the choosen task is completed and waits for the second
		choce until the user chooses to quit the program. 
	2. It intializes the class LinkedList and calls its member functions
		to perform the desired operations. Once the operation is over,
		it anounces the result of that particular operation (choice). 
	3. It declare, implement, and run a function called 
		searchArray(const char [], int, char) that searches for the the 
		presence of the choice entered by a user in a constant array. 
		If the search is successful, the choice is performed.
		If the search is unsuccessful, it displays a message accordngly.    
*/
#include <iostream>
#include "inv.h"
#include <iomanip>
#include "inv.cpp"
#include <ostream>
#include <fstream>
using namespace std;
bool searchArray(const char [], int, char);
int main(int argc, const char * argv[]){
	char ch;
	const char array[] = {'c', 'e', 'i', 'm', 'l', 'n', 's', 'q', 'r', 'w'};
	int num; string name; double p; int q; 
	bool in, ck;
	MyInventory source, list, list2;
	cout << " This program will perform the following"
		 << " tasks.\n You must choose and enter the task"
		 << "\n you want to perform according to the \n instructions"
		 << " in the lists\n";
	cout << " ==================================" << endl;
	cout << " Please choose from the list below." << endl;
	cout << " ==============================================" << endl;
	cout << " => I -- Insert Item"<<setw(30)<<"=> R -- Remove Item\n"
		 	<< " => E -- Check Emptiness"<<setw(25)<<"=> C -- Copy Items\n"
		 	<< " => L -- Lookup an Item"<<setw(27)<<"=> N -- Count Items\n"
		 	<< " => S -- Search Value"<<setw(32)<<"=> W -- Print Contents\n"
		 	<< " => M -- Make Empty"<<setw(31)<<"=> Q -- Exit Program" << endl;
	cout << " ===============================================" << endl;	 
	cin >> ch;
	in = searchArray(array, sizeof(array), ch);
	if(in == false){
		cout << " The choice you entered doesn't exist.\n";
		cout << " See you later.\n Goodby!"<< endl;
		exit(0);
	}
	else{
		while(ch){
			switch(ch){
				case 'i':
					cout << "Enter inventory to insert: ";
					cin >> num >> name >> p >> q;
					list.insert(num, name, p, q);
					list2.insert(num, name, p, q);
					cout << "Inventory inserted successfully."<<endl;
					break;
				case 'r':
					cout << "Enter inventory to remove: ";
					cin >> num;
					list.remove(num);
					cout << "Inventory removed successfully."<<endl;
					if(list.isEmpty() == true)
						list.~MyInventory();
					break;
				case 'e':
					ck = list.isEmpty();
					if(ck == true)
						cout << "List is empty."<<endl;
					else
						cout << "List is not empty."<<endl;
					break;
				case 'c':
					cout << "Copy of the initial list:\n";
					source = list2;
					cout << source << endl;
					break;
				case 'l':
					cout << "Enter an item to check: ";
					cin >> num;
					if(list.isPresent(num) == true)
						cout << "Stack Number"<<num <<" is in the list.\n";
					else
						cout << "Stack Number "<<num <<" is not in the list.\n";
					break;
				case 'n':
					cout << "The list has "<<list.listLength()<<" items"<<endl;
					break;
				case 's':
					cout << "Enter the index of the inventory you want to access: ";
					cin >> num;
					cout << "The inventory at index "<<num<<" is: ";
					cout << list.kthValue(num) << endl;
					break;
				case 'w':
					if(list.isEmpty())
						cout << "The list is empty\n";
					else{
						cout << "Here are the items in the current list:\n";
						cout << "=======================================\n";
						cout << list << endl;
					}
					break;
				case 'm':
					list.~MyInventory();
					cout << "List is re-initialized to empty.\n";
					break;
				case 'q':
					cout << "You chose to quit the program.\n";
					cout << "See you later!";
					exit(0);
					break;	
			}
			cout << " Please choose from the list below." << endl;
			cout << " ==============================================" << endl;
			cout << " => I -- Insert Item"<<setw(30)<<"=> R -- Remove Item\n"
		 			<< " => E -- Check Emptiness"<<setw(25)<<"=> C -- Copy Items\n"
		 			<< " => L -- Lookup an Item"<<setw(27)<<"=> N -- Count Items\n"
		 			<< " => S -- Search Value"<<setw(32)<<"=> W -- Print Contents\n"
		 			<< " => M -- Make Empty"<<setw(31)<<"=> Q -- Exit Program" << endl;
			cout << " ===============================================" << endl;		 
			cin >> ch;
		}
		
	}
	return 0;
}
bool searchArray(const char A[], int n, char ch){
	int i = 0;
	bool found = false;
	while (i < n ){
		if (ch == A[i] || tolower(ch) == A[i])
			found = true;
		i++;
	}
	return found;
}
