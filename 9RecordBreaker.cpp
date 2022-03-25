//22-02-2021

/*
RECORD BREAKER [Google Kickstart]

Question : 
    Given an array, find the record breaking element. An Element is record breaking if it satisfies the following cases :   
        1) The element is strictly larger than the previous all elements.
        2) Either it is the last element, the element must be strictly larger than the folowing element.
    Note that the very first element can be record breaking.        
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
        if (n == 1)
        {
            cout << "1"
                 << "\n";
        }
        else
        {
            int ans = 0;
            int mx = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > mx && arr[i] > arr[i + 1])
                {
                    // cout << i << " ";
                    ans++;
                }
                mx = max(mx, arr[i]);
            }
            // cout << endl;
            cout << ans << "\n";
        }
    }
    return 0;
}
