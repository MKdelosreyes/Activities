// Warning: Do not modify this file.
// Implement the linkedlist.h's corner method

#include <iostream>
#include "linkedlist.h"

int main() {
	LinkedList* list = new LinkedList();
    int input, pos;
    int left, right;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
		    case 'c':
                cin >> left;
                cin >> right;
                cout << "Removed " << list->corner(left, right) << " element/s" << endl;
                break;
		    case 's':
		    	cout << "Size: " << list->_size() << endl;
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