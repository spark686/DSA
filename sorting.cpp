#include "Sort.h"
#include <vector>
#include <iostream>
using namespace std;

Sort::Sort(vector<int>& v) {
    arr = v;
}


// O(n^2) runtime 
/* from i = 1 to n-1 
    from i swap the item with the previous index until the previous item is less than item i 
*/
// the first line take O(n) and the second line takes at most O(n) this takes O(n^2)
void Sort::insertionSort() {
    int c = 0;
    for (int i = 1; i < arr.size(); ++i) {
        c = i;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] > arr[c]) {
                // cout << "swapping arr[j] = " << arr[j] << "    and arr[i] = " << arr[i] << endl;
                swap(j, c);
                c = j;
            }
            else {
                break;
            }
            // for (int k = 0; k < arr.size(); ++k) {
            //     cout << arr[k] << " ";
            // }
            // cout << endl;
        }
    }
}

void Sort::swap(int a, int b) {
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

// O(n^2) run time
// from i = last to 1, find max and swap with last for last = size - 1, ,..., 1
// finding max takes at most O(n) time and each there are O(n) arrays to check the max
void Sort::selectionSort() {
    if (arr.empty()) {
        return;
    }
    int max = 0;
    int swapHelp = 0;
    for (int i = arr.size() - 1; i >= 1; --i) {
        max = maxIndex(i);
        swap(max, i);
    }
}

// O(n)
// finding max from 0 to index b inclusive
int Sort::maxIndex(int b) const {
    int max = b;
    for (int i = b; i >= 0; --i) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return max;
}

void Sort::print() const {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Sort::checkFailed(vector<int>& inArr) {
    return (inArr != arr);
}


