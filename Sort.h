#ifndef SORT_H
#define SORT_H
#include <vector>
using namespace std;

class Sort {
    public:
    Sort(vector<int>& v);
    void selectionSort();
    void insertionSort();
    void print() const;
    bool checkFailed(vector<int>& inArr);
    private:
    vector<int> arr;
    void swap(int a, int b); 
    int maxIndex(int b) const; // return max from index 0 to index b inclusive
};
#endif