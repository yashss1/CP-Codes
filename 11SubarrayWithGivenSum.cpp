// 24-02-2021

/*
SUBARRAY WITH GIVEN SUM [Google, Amazon, Facebook, VISA]   

Problem : 
    Given an unsorted array A of size n of positive numbers, find a subarray which adds to a given number s.    

INPUT :     
    n = 5, s = 12;
    arr[] = {1, 2, 3, 7, 5}
OUTPUT :    
    2 4
Explaination : 
    The sum of the elements from 2nd position to 4rth position is 12.


Brute Force :   
    2 For loops. Time complexity : O(n^2)
Optimized :     
    Keep 2 pointers strt and en(end), and currSum will store SUM from arr[strt] to arr[en].
    Increment en till currSum + a[en] > s;
    Start increasing strt untill currSum <= s;
    Time Complexity : O(n);
    
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
        int n, s;
        cin >> n >> s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int strt = -1, en = -1, sum = 0, i = 0, j = 0;
        for (; j < n && sum + arr[j] <= s; j++)
        {
            sum += arr[j];
        }
        if (sum == s)
        {
            cout << i + 1 << " " << j + 1 << "\n";
            goto end;
        }
        while (j < n)
        {
            sum += arr[j];
            while (sum > s)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == s)
            {
                strt = i + 1;
                en = j + 1;
                break;
            }
            j++;
        }
        cout << strt << " " << en << "\n";
    end:
        int yash;
    }
    return 0;
}
