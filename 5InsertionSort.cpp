// 21-02-2021

/*
INSERTION SORT :    
    Insert an element from unsorted array to its correct position in sorted array.

    12 45 23 51 19 11
    12 45 23 51 19 11
    12 23 45 51 19 11
    12 23 45 51 19 11
    12 19 23 45 51 11
    11 12 19 23 45 51

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
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
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}