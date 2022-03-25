// 01-05-2021

/*
Print the sum of the square represented by (a, b) as the top left point and (c, d) as the top right point. (1<= N <= 10^3)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 10e3+5;

int arr[N][N];
int pfS[N][N];

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            pfS[i][j] = arr[i][j]+pfS[i-1][j]+pfS[i][j-1]-pfS[i-1][j-1];
        }
    }
    int q;
    cin>>q;  // Query
    while(q--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        cout<<pfS[c][d]-pfS[a-1][d]-pfS[c][b-1]+pfS[a-1][b-1]<<"\n";
    }
    return 0;
}
