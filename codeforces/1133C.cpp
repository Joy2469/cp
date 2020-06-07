//Aditi Jain
//
//https://codeforces.com/problemset/problem/1133/C


#include <iostream>
#include <vector> //include vector
#include <algorithm> //for sort



using namespace std;

//comparator function definition is in global. we use it to return t or f
bool f(int x, int y)
{
    return x>y;
}

void codeforces1133C()
{


    int input; int num;
    cin >> num;


    vector <int> A;
    int i =0;
    while (i < num)
    {
        cin >> input;
        A.push_back(input);
        i++;
    }


    sort(A.begin(), A.end());


    int ans = 0;
    int j = 0;
    for (int i = 0; i < num; ++i) {
        while (j < num && A[j] - A[i] <= 5) {
            ++j;
            ans = max(ans, j - i);
        }
    }

    cout << ans << endl;

}

int main() {

    codeforces1133C();
}
