//22-02-2021

/*
Longest ARITHMETIC Subarray [Google KICKSTART]
Arithmetic Subarray = {9, 10}, {3, 3, 3}, {9, 7, 5, 3}

Question : 
    Given an array, find the length of the longest subarray.

    10  7   4   6   8   10  11
      -3  -3  2   2   2    1

      4     6    8    10
        2     2     2

        Output = 4;
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
        int n, ans = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int diff = arr[1] - arr[0];
        int curr = 0;
        for (int j = 2; j < n; j++)
        {
            if (diff == arr[j] - arr[j - 1])
            {
                curr++;
            }
            else
            {
                diff = arr[j] - arr[j - 1];
                curr = 2;
            }
            ans = max(ans, curr);
        }
        cout << ans << "\n";
    }
    return 0;
}
