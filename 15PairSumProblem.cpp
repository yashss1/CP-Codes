// 24-02-2021

/*
Check if there exists two elements in an array such that their sum is equal to given k.

Brute force : 
    Using two for loops, but the time Complexity will be O(n^2)

Optimised :     
    Take the sorted array
    One pointer(low) at the first element, other(high) at the last element
    If their sum is greater than 'k' reduce the higer index
    If their sum is less than 'k' increase the lower index
    Time complexity : O(n)
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            if (arr[low] + arr[high] == k)
            {
                cout << low + 1 << " " << high << endl;
                goto end;
            }
            else if (arr[low] + arr[high] > k)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    end:
        int yash;
    }
    return 0;
}
