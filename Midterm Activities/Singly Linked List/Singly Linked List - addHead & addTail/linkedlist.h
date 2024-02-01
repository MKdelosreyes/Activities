#include <cstdlib>
#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List {
	node* head;
	node* tail;
	int size;

	public:
	void add(int num) {
		node* n = (node*) calloc(1,sizeof(node));
		n->elem = num;
		if(size == 0) {
			tail = n;
			head = n;
		}else {
			tail->next = n;
			tail = n;
		}
		tail->next = NULL;
		size++;
	}

    int get(int pos) {
        node* curr = head;
        for(int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        return curr->elem;
    }

    int remove(int num) {
        node* curr = head;
        node* prev;
        int ctr = 0;
        while(curr) {
            if (curr->elem == num) {
                ctr++;
                if (curr == head) {
                    head = head->next;
                } else {
                    if (curr == tail) {
                        tail = prev;
                    }
        			prev->next = curr->next;
                }
    			size--;
    			return ctr;
			}
			prev = curr;
			curr = curr->next;
    		ctr++;
        }
        return -1;
	}

    // TODO implement addHead and addTail
    void addHead(int num) {
        node* n = (node*) calloc(1,sizeof(node));
		n->elem = num;
        if(size == 0) {
            head = n;
            tail = n;
        } else {
    		n->next = head;
    		head = n;
        }
		size++;
    }

    void addTail(int num) {
        add(num);
    }

    void print() {
    	node* curr = head;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
	    	do {
	    		cout << curr->elem;
	    		if (curr->next) {
	    			cout << " -> ";
				} else {
					cout << endl;
				}
	    		curr = curr->next;
			} while (curr);
		}
    }
};