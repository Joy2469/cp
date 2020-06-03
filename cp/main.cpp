//#include "stdafx.h"// only for visual studio
#include <iostream>
#include <vector> //include vector
#include <algorithm> //for sort


using namespace std;


//comparator function definition is in global. we use it to return t or f
bool f(int x, int y)
{
    return x>y;
}


int main() {

    vector <int> A = {11,2,3,14};
    cout <<A[1] << endl;
    sort(A.begin(), A.end()); //O(NlogN) because of merge sort
    //2,3,11,14

    //O(logN) binary search
    bool present = binary_search(A.begin(), A.end(), 3); // true
    present = binary_search(A.begin(), A.end(), 4); // false

    //SORTING ARRAY
    A.push_back(100); //add 100 to the end so our array is stoll sorted
    present = binary_search(A.begin(), A.end(), 100); // true

    //2,3,11,14,100
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    //2,3,11,14,100,100,100,100,100,123

    //trying to find the first occurance of 100
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100) ; // >=
    //the iterator is sort a pointer
    //The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val. This means that the function returns the index of the next smallest number just greater than that number.
    //lower_bound and upper_bound are different in one aspect only that is upper_bound is strict while lower bound is greater than and equal to

    //lower_bound and upper_bound is done in log(N) time using binary search
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); //>
    //it=100 (first one)
    //it2=123

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; // 5 . O(1)// this gives exactly how many time 100 is occuring
    //iterators in vectors are random. we can perform airthmetic operations on iterators.

    //sorting vector in reverse
    sort(A.begin(), A.end(), f);
    vector<int>::iterator it3;

    for (it3 = A.begin(); it3 != A.end(); ++it3)
    {
        cout << *it3 << " ";
    }

    cout << endl;





}
