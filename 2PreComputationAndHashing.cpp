// 01-05-2021

// Doing some Calculations before and storing it so that we dont have to calculate it again and again is called PRE-COMPUTATION.

// Basic Question is storing facotrials of a number in an array fac[n] = fact[n-1]*n;

// HASHING
// Given an array print the count of the repeated numbers;
// If negative numbers are present, add the gratest negative number to each element, and while answering subtract

#include <bits/stdc++.h>
using namespace std;

int arr[100000+2]; // Globally declared arrays are automatically intitalized to 0

int main()
{
    int n, a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        arr[a]++;
    }
    for (int i = 0; i < 100001; i++)
        if(arr[i]!=0)
            cout<<"The Number "<<i<<" is repeated "<<arr[i]<<" times\n";
    return 0;
}
 