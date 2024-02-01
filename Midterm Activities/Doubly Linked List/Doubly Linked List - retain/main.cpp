// Warning: Do not modify this file.
// Create the list's and linkedlist.h's removeAt method

#include <iostream>
#include "linkedlist.h"

int main() {
	LinkedList* list = new LinkedList();
    int input, pos;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
		    case '=':
                cin >> input;
                cout << "Removed " << list->retain(input) << " element/s" << endl;
                break;
		    case 'p':
		    	list->print();
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		}
	} while (op != 'x');
    return 0;
}