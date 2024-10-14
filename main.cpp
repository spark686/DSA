#include "Sort.h"
// #include "Sort_Sample.txt"
// #include "Sort_Sample_Answer.txt"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream inF("Sort_Sample.txt");
    ifstream ansF("Sort_Sample_Answer.txt");
    stringstream inputString;
    stringstream ansString;
    string s;
    string answer;
    int a = 0;

    if (!inF.is_open() || !ansF.is_open()) {
        cout << "File not opened correctly. System Terminate." << endl;
        return 1;
    }

    while (getline(inF, s) && getline(ansF, answer)) {
        // cout << "here" << endl;
        inputString << s;
        ansString << answer;
        vector<int> arr;
        vector<int> ansArr;
        while(inputString >> a) {
            arr.push_back(a);
        }
        while (ansString >> a) {
            ansArr.push_back(a);
        }
        Sort test(arr);
        cout << "Before the sorting: ";
        test.print();
        cout << endl << endl;
        // test.selectionSort();
        test.insertionSort();
        cout << "After the selection sorting: ";
        test.print();
        cout << "-------------------------------------------------------------------------" << endl << endl << endl;
        s = "";
        answer = "";
        inputString.clear();
        ansString.clear();
        if (test.checkFailed(ansArr)) {
            cout << "[failed sorting]" << endl;
            return 1;
        }
    }
    cout << "[test succeeded]" << endl;


    return 0;
}