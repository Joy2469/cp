//Aditi Jain
//
//https://codeforces.com/problemset/problem/1088/B


#include <iostream>
#include <set>
#include <vector> //include vector
#include <algorithm>

using namespace std;


void codeforces1088B()
{


    int input; int num;
    cin >> num; int k;
    cin >> k;

    //we are using sets as it always sorted
    set <int> A;
    int i =0;
    while (i < num)
    {
        cin >> input;
            A.insert(input);
        i++;
    }
    A.insert(0);
    // we are inserting 0 by ourselves as we can control it . and no other zero will be added.
    //if during in subraction they arise they will automatically get deleted.


    auto it=A.begin();
    for (int i=0;i<k;i++)
    {
        if (next(it)==A.end())
            cout << "0\n";
        else
        {
            //in the first instance it will point to 0 and the next to the smallest element
            cout  << *next(it)-*it<< "\n";
            it=next(it);
        }
    }
}

int main() {

    codeforces1088B();
}
