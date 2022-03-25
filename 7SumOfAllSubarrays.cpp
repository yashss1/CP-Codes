// 22-02-2021

/*
SUBARRAY :  
    Continuous part of the array.
    Number of subarray of an array with n elements = nC2 + n = n*(n+1)/2;

SUBSEQUENCE :   
    A subsequence is a sequence that can be derived from an array by selecting zero or more elements, without changing the order of the remaining elements.
        1   0   2   7   5
    --> 2   7   2        
    Number if subsequence of an array = 2^n ; 

Every Subarray is a Subsequence but every Subsequence is not a Subarray.    
*/

/*
Question : 
    Display the sum of all the subarrays of the given array.

KANDANE's Algorithm does the same with time complexity O(n).    
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr = 0;
            for (int j = i; j < n; j++)
            {
                curr += arr[j];
                cout << curr << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

