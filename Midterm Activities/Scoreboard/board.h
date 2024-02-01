#include "entry.h"
class Scoreboard {
	entry board[5];
	int size;
	
	public:
	bool add(entry e) {
		bool added = false;
		for (int i = 0; i < size; i++) {
			entry exist = board[i];
			if (e.score > exist.score) {
				for (int j = size; j >= i+1; j--) {
					if (j == 5) {
						continue;
					}
					board[j] = board[j-1];
				}
				board[i] = e;
				if (size < 5) {
					size++;
				}
				added = true;
				return true;
			}
		}
			if (size < 5) {
				board[size++] = e;
                return true;
			} else {
				cout << "PUNO NA" << endl;
                return false;
			}
    }

    // TODO add method banCollege here
	int banCollege(string college) {
        int count = 0;
        entry e;
        for(int i = 0; i < size; i++) {
            e = board[i];
            if(e.college == college) {
                count++;
                for(int j = i; j < size-1; j++) {
                    board[j] = board[j+1];
                }
                i--;
                size--;
            }
        }
        return count;
    }
    
    void print() {
        for (int i = 0; i < 5; i++) {
            if (i >= size) {
                cout << i+1 << ". (none)" << endl; 
            } else {
            	entry e = board[i];
                cout << i+1 << ". " << e.name << " (" << e.college << ")" << " - " << e.score << endl;
            }
        }
        cout << endl;
    }
};