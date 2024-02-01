#include <cstdlib>
#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List {
	node* head;
	node* tail;
	int size;

	void addBetween(int num, node* pred, node* succ) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		n->prev = pred;
		n->next = succ;
		pred->next = n;
		succ->prev = n;
		size++;
	}

    void addTail(int num) {
    	addBetween(num, tail->prev, tail);
    }

	public:

	// constructor
	LinkedList() {
		// HEADER sentinel
		head = (node*) calloc( 1, sizeof(node) );
		// TRAILER sentinel
		tail = (node*) calloc( 1, sizeof(node) );
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	void add(int num) {
		addTail(num);
	}

    int get(int pos) {
        // IGNORE for now
        return 0;
    }

    int remove(int num) {
        // IGNORE for now
        return 0;
	}

    int _size() {
        return size;
    }

    // TODO implement the corner method
    // Note: You must NOT use any other methods here
    int corner(int left, int right) {
        node* top;
        node* down;
        node* curr;
        int count;

        count = 0;
        curr = head;
        while(curr) {
            if(count == left) {
                top = curr;
            }
            count++;
            curr = curr->next;
        }

        count = 0;
        curr = tail;
        while(curr) {
            if(count == right) {
                down = curr;
            }
            count++;
            curr = curr->prev;
        }
        top->next = down;
        down->prev = top;
        count = size - (left+right);
        size = (left+right);
        return count;
    }

    void print() {
    	node* curr;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
			cout << "From HEAD: ";
    		curr = head->next;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != tail->prev) {
	    			cout << " -> ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->next;
			}
			cout << "From TAIL: ";
    		curr = tail->prev;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != head->next) {
	    			cout << " <- ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->prev;
			}
		}
    }
};