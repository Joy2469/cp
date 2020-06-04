//Aditi jain

//notes on stl
//

//#include "stdafx.h"// only for visual studio
#include <iostream>
#include <vector> //include vector
#include <algorithm> //for sort
#include <set>
#include <map>
using namespace std;


//comparator function definition is in global. we use it to return t or f
bool f(int x, int y)
{
    return x>y;
}

void problem() {
    //[x,y]
    //add [2,3]
    //add [10,20],
    //add [30, 400]
    //give me the interval 13. when we say give interval 401

    //we are using sets
    // we are inserting pairs eg (3,15). we can also have (int, char) pair. set is orderd in asceding order
    set<pair<int, int>> S;

    S.insert({2,3});
    S.insert({10, 20});
    S.insert({30,400});
    S.insert({401, 450});


    //sorting in pair
    //(2,3) < (10,20) < (30,400) < (401,450)
    //Pair (a,b) is smaller than pair (c,d)
    // if (a<c), true
    // else if ((a==c) and b<d) true
    //otherwise (c,d) is smaller

    //In arranging the pairs in ascending  order the pairs are first ordered in ascending order using there first co-ordinates (x)
    // if the x co-ordinates of two pairs are equal they are using there y co-ordinates in increasing oder/ascending order.

    //2,3
    //10,20,
    //30,40,
    //401,450

    //let us say ewe are doing an upper bound in 31
    //we will get 30,40

    //upper bound (12, ?)
    // we will get iterator to (30, 40) as 2 < 12, and 10 < 12.
    // then we go one step back and then (10,20) interval contains 12 so we return (10,20)

    //upper bound (10, 0)
    //corner case
    //the x cordinate is the same so we will look for the y co-ordinate
    //so iterator goes on (10,12)
    //we go one step back
    // (2,3) doesnt have our algorithm fails as it says 10, 0 is not there but it is there in the set

    // so the (10, ?), thr question
    // we will need to use INT_MAX  in place of question mark as nothing can be greater than INT_MAX
    //now it returns true
    //we will come to 30, 400
    // go back and see if the thing are working out

    int point = 401;

    auto it = S.upper_bound({point, INT_MAX});
    it--;

    if(it == S.begin())
    {
        cout << "Given point not in any interval" << endl;
        return;
    }
    pair <int , int> current = *it;
    if( current.first <= point && point <=current.second){
        cout << "YES! it is present: " << current.first << " " << current.second << endl;

    }
    else
    {
        cout << "Given point not in any interval" << endl;
    }

    //if point =50
    // YES! it is present: 30 400

    //if point =1
    // we get it = (2,3)
    // then we we go one step back we fails as it =S.begin
    // Given point not in any interval

    //if point = 11
    //YES! it is present: 10 20

    //if point =400
    //YES! it is present: 30 400

    //if point 401
    //YES! it is present: 401 450
}

void maps_demo()
{
   //maps is mapping something to something
   map <int, int> A;
   A[1]=100;
   A[2] = -1;
   A[3] = 200;
   A[10000023] = 1;

   map<char, int> cnt;
   //a lot of permutations are possible of mapping
   string x = "aditi jain";

   for( char c: x)
   {
       cnt[c]++;
   }
   //in logn time we can add someting to map. where N is the current size of the map
   cout << cnt['a'] << " " << cnt['j'] << endl;


}

void set_demo()
{
    //set very powerful
    set<int> S;
    S.insert(1);// logN to add a number
    S.insert(2);// logN
    S.insert(-1);// logN
    S.insert(-10);// logN

    //set interally sorts the elements unlike vectors
    for (int x: S)
    {

        cout << x << " ";
    }
    cout << endl;

    auto it =   S.find(-1);
            //it finds -1 and if it finds that it returns the iterator to that
    if( it==S.end())
    {
        cout << "not present\n";
    } else{
        cout << "present\n";//present
        cout << *it << endl;//-1
    }

    //find >=-1
    // WE DONT NEED to add begin and end in lower bound and upper bound bcz already always sorted
    auto it2 =S.lower_bound(-1);
    auto it3 =S.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;// 1 1

    auto it4 = S.upper_bound(2);
    if( it4==S.end())//true
    {
        cout << "oops cant find it\n";
    }
}
void vector_demo()
{


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
    //the iterator is sort a pointer. gives the leement in LOgN time but array has to always sorted to work
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

    //SIMPLIEFIED
    auto it11 = lower_bound(A.begin(), A.end(), 100) ; // >=
    auto it21 = upper_bound(A.begin(), A.end(), 100); //>
    //it=100 (first one)
    //it2=123

    cout << *it11 << " " << *it21 << endl;
    cout << it21 - it11 << endl; // 5 . O(1)// this gives exactly how many time 100 is occuring

    //sorting vector in reverse
    sort(A.begin(), A.end(), f);

    for (int x:A) //int &x:A) iterate by reference . we can update values
    {
        x++;
        cout << x << " ";
    }
    //124 101 101 101 101 101 15 12 4 3

    cout << endl;



}


int main() {
//set_demo();
problem();
}
