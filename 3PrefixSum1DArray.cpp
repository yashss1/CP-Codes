// 01-05-2021

/*

arr = 1 2 3 4 5
prefixSum arr = 1 3 6 10 15 

Now if the question is what is the sum of elements from 2 to 4, we can just do 10-1 = 9
So that we dont have to calculate for eack query, this reduces time complexity from square to linear(n)
*/

#include <bits/stdc++.h>
using namespace std;

int a[100001];
int pfS[100001];

int main()
{
    int n, a;
    cin>>n;
    for (int i = 1; i <= n; i++)  // Start indexing from 1
    {
        cin>>a;
        pfS[i] = pfS[i-1]+a;
    }
    int q;
    cin>>q;  //Query
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<"Sum of index "<<l<<" to "<<r<<" is "<<pfS[r]-pfS[l-1]<<"\n";
    }
    return 0;
}
