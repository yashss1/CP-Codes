// 19-02-2021

/*
Linear Search :     
    Searching for an key element begining with first element till last.
    Time Complexity = O(n);

Binary Search :     
    Taking a sorted array, finding the middle element then see whether the key element is in the first or the second half, and reduce the length of for loop.
    Time Complexity :   
        Lets assume we get our key element after kth iteration.  
        After first iteration, length of array = n/2;
        After second iteration, length of array = n/4;
        After third iteration, length of array = n/8;
        After kth iteration, length of array = n/(2)^k;

        Length of array after kth iteration will be one
            n/(2)^k = 1;
            n = (2)^k;
            Taking log on both sides.
            logn = klog2;
            k = logn;;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int find(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n, k;
    cout << "Enter the key Element followed by the size of array and the Sorted array (each in new line) : \n";
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The Element is present at the " << find(arr, n, k) << "th index\n";
    return 0;
}
