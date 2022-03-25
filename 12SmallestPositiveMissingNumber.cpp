// 24-02-2021

/*
Smallest Positive Missing Number [Amazon, accoute, Samsung, Snapdeal]  
Problem : 
    You are given an array of size n, Find the smallest positive missing number.
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
        int n, ans;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool check[100000];
        for (int i = 0; i < 100000; i++)
        {
            check[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            check[arr[i]] = 1;
        }
        for (int i = 1; i < 100000; i++)
        {
            if (check[i] == 0)
            {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
