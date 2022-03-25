//24-02-2021

/*
FIRST REPEATING ELEMENT [Amazon, Oracle]

Problem :   
    Given an array of size n. The task is to find repeating element in the array of integers. i.e., an element that occurs more than once and whose index of first occurrence is smallest.

INPUT : 
    7
    1 5 3 4 3 5 6
OUTPUT :    
    2
Explanation :   
    5 is appearing twice and its first appearance is at index 2 which is less than 3 whose first occuring index is 3.4

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
        int index[100000];
        for (int i = 0; i < 100000; i++)
        {
            index[i] = -1;
        }
        int minIndex = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (index[arr[i]] != -1)
            {
                minIndex = min(minIndex, index[arr[i]]);
            }
            else
            {
                index[arr[i]] = i;
            }
        }
        if (minIndex == INT_MAX)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << minIndex + 1 << endl;
        }
    }
    return 0;
}
