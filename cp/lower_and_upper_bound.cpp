//
// Created by Aditi Jain on 6/6/20.
//

//QUESTIONS:
//Given an array
//1. Find the smallest integer greater than x in the array.(simply lower bound)
//2. Find the largest integer less than Or equal to x in the array(somewhat tricky)
//3.Find number of integers greater less than x in the array

#include <iostream>
#include <vector> //include vector
#include <algorithm> //for sort
#include <set>
#include <map>

using namespace std;

void lower_and_upper_bound()
{
    //1.Find the smallest integer greater than x in the array.(simply lower bound)
    int a[]= {5,7,7,90,34,12};
    vector<int> A(a, a + sizeof(a) / sizeof(a[0]) );
    //sorting the vector
    cout << sizeof(a) << endl;
    sort(A.begin(), A.end());
    for(int i: A)
    {
        cout << i << " ";
    }
    cout << endl;

    auto num = lower_bound(A.begin(),A.end(), 7);
    cout << "the smallest integer greater than x in the array: " << *num << endl;

    //2.Find the largest integer less than Or equal to x in the array(somewhat tricky)
    num = upper_bound(A.begin(), A.end(), 35);
    auto it = find(A.begin(), A.end(), *num);
    it--;

    if(it==A.begin())
    {
        cout << "Not Found! " << endl;
    }
    cout << "the largest integer less than Or equal to x in the array: " << *it << endl;


    //3.Find number of integers greater less than x in the array
    cout << "numbers less than or equal ";
    for(auto i = A.begin() ; i <= it; i++)
        cout << *i << " ";
    cout << endl;
    //we dont need to worry about it as the array is already sorted


}

int main() {
    lower_and_upper_bound();
}
