// 24-02-2021

/*
Now assume given array circular that is first element comes again after the last element.

INPUT :   
    2
    6
    -1 4 -6 7 5 -4
    7
    4 -4 6 -6 10 -11 12
OUTPUT :    
    12 = 7+5
    22 = 12+4-4+6-6+10   

Max subarray sum = Total sum of the array - Sum of nonContributing elements
Sum of nonContributing elements = Kadane of the array with all the elements negative of before.
This means subtracting the max negative sum of the array.

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int kadane(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

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
        int wrapSum;
        int nonWrapSum;
        nonWrapSum = kadane(arr, n);
        int totalSum = 0;
        for (int i = 0; i < n; i++) 
        {
            totalSum += arr[i];
            arr[i] = -arr[i];
        }
        wrapSum = totalSum + kadane(arr, n);
        cout << max(wrapSum, nonWrapSum) << endl;
    }
    return 0;
}