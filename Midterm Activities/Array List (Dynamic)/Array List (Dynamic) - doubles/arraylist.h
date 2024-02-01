#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.h"
using namespace std;

class ArrayList : public List {
    double* array;
    int size;
    int capacity = 5;

    void dynamic_add() {
		double new_size = ceil(capacity * 2);
		double* new_array = (double*) realloc(array, sizeof(double) * new_size);
		array = new_array;
		capacity = new_size;
	}

	void dynamic_deduce() {
		double new_size = ceil(capacity * 0.7);
		double* new_array = (double*) realloc(array, sizeof(double) * new_size);
		array = new_array;
		capacity = new_size;
	}

    public:
    // constructor
    ArrayList() {
        // initialize array using malloc or calloc here
        array = (double*) calloc(capacity, sizeof(double));
        size = 0;
    }
    void add(double num) {
        // TODO implement add with dynamic array
        if (size == capacity) {
        	dynamic_add();
		}
        array[size++] = num;
    }

    int remove(double num) {
        // TODO implement remove with dynamic array
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                // Step 2: MOVE the elements to left
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                // Step 3: Set the size
                array[size-1] = 0;
                size = size-1;
                // Step 4: Check to reduce capacity
                if (size <= 1.0/2 * capacity && capacity > 5) {
                	dynamic_deduce();
				}
                // Step 5: Return
                return i+1;
            }
        }
        return -1;
    }

    double get(int pos) {
        // TODO implement get
        return array[pos-1];
    }

    void print() {
        int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
        }
        cout << endl;
    }
};