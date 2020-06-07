//Aditi Jain
//
//https://codeforces.com/problemset/problem/1133/C
//https://codeforces.com/contest/808/submission/27143685 solution


#include <iostream>
#include <vector> //include vector
#include <algorithm> //for sort
#include <numeric>


using namespace std;

//comparator function definition is in global. we use it to return t or f
bool f(int x, int y)
{
    return x>y;
}

void codeforces808C()
{
    int n;
    int k;
    pair <int,int> a[100];
    int ans[100];

    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i].first);
        ans[i]=a[i].first;
        a[i].second=i;
    }
    for(int i=0; i<n; i++){

        a[i].first=ans[i]/2;
        k-=ans[i]/2;

        if(ans[i]&1)
        {
            a[i].first++;
            k--;
        }
        if(k<0){
            printf("-1");
            return;}
    }
    sort(a,a+n);
    while(k)
    {
        for(int i=0; i<n&&k; i++)
        {
            if(a[i].first<ans[a[i].second])
                a[i].first++,k--;
        }
    }
    for(int i=0; i<n; i++)
    {
        ans[a[i].second]=a[i].first;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",ans[i]);
    }


}

int main() {

    codeforces808C();
}
