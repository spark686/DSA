#include "Sort.h"
#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

Sort::Sort(vector<int>& v) {
    arr = v;
}


// O(nlogn) runtime
// it has the balanced binary search tree structure which means the height of the tree is bounded by O(logn). Each insertion and rotation takes O(logn) amortized
void Sort::balancedBST() {
    set<int> s(arr.begin(), arr.end());
    int i = 0;
    for (auto a: s) {
        arr[i] = a;
        ++i;
    }
}

// O(nlogn) runtime
/* 1. inserting all elements to the array takes at most O(nlogn)
   2. taking out the max element from the heap and putting them in j index where j goes from n -1 to 0 
        returning max takes O(1) and popping max element from heap takes O(logn) 
        This means (2) also takes O(nlogn)
*/ 
void Sort::heapSort() {
    priority_queue<int> v;
    for (int i = 0; i < arr.size(); ++i) {
        v.push(arr[i]);
    }
    for (int i = 0; i < arr.size(); ++i) {
        arr[arr.size() - 1 - i] = v.top();
        v.pop(); 
    }
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



// O(nlogn) runtime
// takes O(n) space complexity?
// basic divide and conquer algorithm 
/* 1. divide array into half until they all become singletons O(log n)
   2. while iterating up, using the two finger algoirthm, from each side left and right(which is sorted) vector. O(n)
   This means since both arrays are sorted, compare the first element from each array that hasn't been used to construct larger vector, 
   put the max in the new large vector and increment the index of the item that has been inserted. 
   If there is a case where the item of the left or right vector hasn't been all used, insert all of them in the end of the new large vector.
   This algoirthm takes O(nlogn) time. 
*/
void Sort::mergeSort() {
    if (arr.size() == 0) {
        return;
    }
    arr = mergeSortHelp(0, arr.size() - 1);
}

vector<int> Sort::mergeSortHelp(int a, int b) {
    vector<int> ans;
    if (a > b) {
        return ans;
    }
    else if (a == b) {
        ans.push_back(arr[a]);
        return ans;
    }
    vector<int> recAns(b - a + 1, 0);
    int mid = (b + a) / 2;
    vector<int> left = mergeSortHelp(a, mid);
    vector<int> right = mergeSortHelp(mid + 1, b);
    int leftPt = 0;
    int rightPt = 0;
    int j = 0;
    while (leftPt < left.size() && rightPt < right.size()) {
        if (left[leftPt] < right[rightPt]) {
            recAns[j] = left[leftPt];
            leftPt++;
        }
        else {
            recAns[j] = right[rightPt];
            rightPt++;
        }
        ++j;
    }
    // leftover from top while loop
    while (leftPt < left.size()) {
        recAns[j] = left[leftPt];
        leftPt++;
        j++;
    }
    while (rightPt < right.size()) {
        recAns[j] = right[rightPt];
        rightPt++;
        j++;
    }
    return recAns;
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


