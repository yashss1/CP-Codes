// 21-02-2021

/*
BUBBLE SORT :    
    Reapetedly swap two adjacent elements if they are in wrong order.
 
    1) 12 45 23 51 19 11    // Doing this n-1 times
       12 45 23 51 19 11
       12 23 45 51 19 11
       12 23 45 19 51 11
       12 23 45 19 11 51              // This is not the sorted element, but we have bubbled out the largest element.
   
    2) 12 23 45 19 11 51    // Doing this n-2 times, as biggest 1 element is already at last so no need to check that.
       12 23 45 19 11 51
       12 23 19 45 11 51
       12 23 19 11 45 51

    3) 12 23 19 11 45 51    // Doing this n-3 times
       12 23 19 11 45 51
       12 19 23 11 45 51
       12 19 11 23 45 51

    4) 12 19 11 23 45 51    // Doing this n-4 times
       12 19 11 23 45 51
       12 11 19 23 45 51

    5) 11 12 19 23 45 51    // Doing this n-5 times
       11 12 19 23 45 51         

        ith Iteration = n - i;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bubbleSort(int arr[], int n)
{
   int counter = 1;
   while (counter < n)
   {
      for (int i = 0; i < n - counter; i++)
      {
         if (arr[i] > arr[i + 1])
         {
            swap(arr[i], arr[i + 1]);
         }
      }
      counter++;
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
   bubbleSort(arr, n);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << "\n";
   return 0;
}