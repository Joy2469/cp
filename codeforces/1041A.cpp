//Aditi Jain
// https://codeforces.com/problemset/problem/1041/A

#include <iostream>
#include <vector> //include vector
#include <algorithm>



using namespace std;


void codeforces1041A()
{
    int input; int num;
    cin >> num;

    //adding integers in the form of
    vector<int> K;

    int i = 0;
    while (i < num)
    {
        cin >> input;
        K.push_back(input);
        i++;
    }

    sort(K.begin(), K.end());

    int max = *max_element(K.begin(), K.end());
    int min = *min_element(K.begin(),K.end());

    int missing_K = max-min+1-num;
    cout << missing_K << endl;

}

int main() {

    codeforces1041A();
}
