// 19-02-2021

/*
Selection Sort : 
    Find the minimum element in unsorted array and swap it with element at begining.
    12 45 23 51 19 11
    11 45 23 51 19 12
    11 12 23 51 19 45
    11 12 19 51 23 45
    11 12 19 23 51 45
    11 12 19 23 45 51
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
Quiz = You are given 'n' rupees:
    1 rupee = 1 chocolate
    3 chocolate wrapers = 1 chocolate
    What is the number of choclates you can buy?
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, count = 0, wrap = 0;
//         cin >> n;
//         count += n;
//         wrap += n;
//         while (wrap > 2)
//         {
//             count += wrap / 3;
//             wrap /= 3;
//         }
//         cout << count << "\n";
//     }
//     return 0;
// }
