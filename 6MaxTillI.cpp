// 22-02-2021

/*
Given an array of size n. For every i '0' to 'n-1', output max(a[0], a[1], a[2],.... a[i])

                 1   0   5   4   6   8
  max till i ;   1   1   5   5   6   8

  To reduce time complexity use max() function.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, mx = INT_MIN;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, arr[i]);
            cout << mx << " ";
        }
        cout << "\n";
    }
    return 0;
}
