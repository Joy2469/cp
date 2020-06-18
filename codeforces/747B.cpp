//Aditi Jain
//
//https://codeforces.com/problemset/problem/747/B


#include <iostream>
#include <vector> //include vector
#include <algorithm> //for sort



using namespace std;

//comparator function definition is in global. we use it to return t or f
bool f(int x, int y)
{
    return x>y;
}

int median(vector<int> medi)
{
    sort(medi.begin(), medi.end());     // sort

    double median;
    if (medi.size() % 2 == 0)           // even
        median = (medi[medi.size() / 2 - 1] + medi[medi.size() / 2]) / 2;
    else                                // odd
        median = medi[medi.size() / 2];

    return median;
}

void codeforces747B()
{


    char input; int num;
    cin >> num;


    vector <char> Genome;
    int A =0, C =0, G=0, T=0, i=0, Q= 0;
    while (i < num)
    {
        cin >> input;
        Genome.push_back(input);
        i++;
    }

    if (num % 4 != 0)
    {
        printf("===");
        return;
    }


    for( i = 0; i< num; i++)
    {
        if(Genome.at(i)== 'A')
            A++;
        else if(Genome.at(i)== 'C')
            C++;
        else if(Genome.at(i)== 'G')
            G++;
        else if(Genome.at(i)== 'T')
            T++;
        else
            Q++;
    }


    if(Q==0 && A!=C && C!= T && T!=G && G!=A)
    {
        cout << "===";
        return;
    }

    int max1 = A > C? A: C;
    int max2 = G > T? G: T;
    int max = max1 > max2 ?  max1: max2;

    if(max> num/4)
    {
        printf("===");
        return;
    }


    for (int j = 0; j < num; j++)
    {
        if (Genome.at(j) == '?')
        {
            if(A < num/4)
            {
                Genome.at(j) = 'A';
                A++;
            }
            else if( G < num/4)
            {
                Genome.at(j) = 'G';
                G++;
            }
            else if( C < num/4)
            {
                Genome.at(j) = 'C';
                C++;
            }
            else if( T < num/4) {
                Genome.at(j) = 'T';
                T++;
            }
        }
    }


    for (int i = 0; i < num; i++)
        cout << Genome.at(i);

}

int main() {

    codeforces747B();
}
