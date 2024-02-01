// Warning: Do not modify this file.
// Go to linkedlist.h's remove method

#include <iostream>
#include "linkedlist.h"

int main() {
	List* list = new LinkedList();
    int input, res;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
		    case 'g':
		    	cin >> input;
                res = list->get(input);
                if (res == -1) {
                    cout << "Invalid position: " << input << endl;
                } else {
                    cout << "Element at position " << input << " is " << res << endl;
                }
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