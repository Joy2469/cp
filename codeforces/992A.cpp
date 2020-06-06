//Aditi Jain
//
//https://codeforces.com/problemset/problem/992/A


#include <iostream>
#include <set>
#include <vector> //include vector
#include <algorithm>

using namespace std;


void codeforces992A()
{


    int input; int num;
    cin >> num;

    //adding integers in the form of
    set <int> K;

    //To add sets. by substracting we reduce one element at a time to zero. if there are different elemnts. if there is two same they become zero at the same time.
    //Sets doesnt have repitions. so the size of a set is the number of steps we need for the array explode.
    int i = 0;
    while (i < num)
    {
        cin >> input;
        if(input)
            K.insert(input);
        i++;
    }

    cout << K.size();
}

int main() {

    codeforces992A();
}
