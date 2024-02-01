#include <iostream>
#include "list.h"
using namespace std;

class ArrayList : public List {
    int array[5];
    int size;

    public:
    ArrayList() {
        array[0] = 0;
        array[1] = 0;
        array[2] = 0;
        array[3] = 0;
        array[4] = 0;
        size = 0;
    }

    void add(int num) {
        if (size < 5) {
            array[size++] = num;
        } else {
            cout << "PUNO NA MY FRIEND" << endl;
        }
    }

    int remove(int num) {
        // Step 1: FIND the num
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                // Step 2: MOVE the elements to left
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                // Step 3: Set the size
                array[5] = 0;
                size = size-1;
                // Step 4: Return
                return i+1;
            }
        }
        return -1;
    }

    int get(int pos) {
        return array[pos-1];
    }

    // TODO implement method removeAll here
    int removeAll(int num) {
        int count = 0;
        for(int ctr = 0; ctr < size; ctr++) {
            if(array[ctr] == num) {
                count++;
                for(int j = ctr; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                array[size - 1] = 0;
                size--;
                ctr--;
            }
        }

        return count;
    }

    void print() {
        //array[5] = 0;
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};