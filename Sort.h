#ifndef SORT_H
#define SORT_H
#include <vector>
using namespace std;

class Sort {
    public:
    Sort(vector<int>& v);
    void selectionSort(); // O(n^2) Brute Force
    void insertionSort(); // O(n^2) Brute Force 
    void mergeSort(); // O(nlogn) comparison sort 
    void heapSort(); // O(nlogn) comparison sort
    void balancedBST(); // O(nlogn) comparison sort
    void print() const;
    bool checkFailed(vector<int>& inArr);
    private:
    vector<int> arr;
    vector<int> mergeSortHelp(int a, int b);
    void swap(int a, int b); 
    int maxIndex(int b) const; // return max from index 0 to index b inclusive
};
#endif