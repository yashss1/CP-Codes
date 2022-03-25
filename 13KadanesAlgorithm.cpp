// 24-02-2021

/*
Finding the Maximum sum of the Subarray of an array including non-positive elements.

    Array     : -1   4   -6   7   -4
    CurrenSum : -1   4   -2   7    3
                 0        0

Add array in currSum one by one, and if at a index currSum becomes less than 0, do currSum = 0.
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
        cout << kadane(arr, n) << "\n";
    }
    return 0;
}



//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define bits(x)           __builtin_popcount(x)
#define all(x)            (x).begin(),(x).end()
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
inline int gcd(int a, int b)          {if (b == 0) return a;    return gcd(b, a % b);}

int fpow(int x, int y, int p = MOD) {
    x = x % p; int sum = 1; while (y) {
        if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
    } return sum;
}
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

// Implementation of Kadane's algorithm for
// 1D array. The function returns the maximum
// sum and stores starting and ending indexes
// of the maximum sum subarray at addresses
// pointed by start and finish pointers
// respectively.
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check
    // for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    // There is at-least one
    // non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers
    // in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

int n, m;
vector<vector<int>> v;

// Using Kadane's Algorithm :- https://www.youtube.com/watch?v=yCQN096CwWM
int maxSum_On3() {
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i, sum, start, finish;

    for (int left = 1; left <= n; left++) {
        int temp[n + 1];
        memset(temp, 0, sizeof(int) * (n + 1));
        for (int right = left; right <= m; right++) {
            for (int i = 1; i <= n; i++) {
                temp[i] += v[i][right];
            }

            int sum = kadane(temp, &start, &finish, n);

            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // finalLeft, finalRight, finalTop, finalBottom gives us the maximum sum rectangle
    return maxSum;

}

int maxSum_On4() {
    vector<vector<int>> hsh;
    hsh.resize(n + 1, vector<int> (m + 1));
    int mx = INT_MIN;

    //Calculting sum from (i,j) to (n,m) for each cell.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int sum_curr = 0;
            for (int x = i; x <= n; x++) {
                for (int y = j; y <= m; y++) {
                    sum_curr += v[x][y];
                }
            }
            hsh[i][j] = sum_curr;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //  for (int j = 1; j <= m; j++) {
    //      cout << hsh[i][j] << ' ';
    //  }
    //  cout << '\n';
    // }

    // Now calcuating sum of all the rectangles from (x1,y1)->(x2,y2)
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= m; y2++) {
                    int t1 = hsh[x1][y1], t2 = 0, t3 = 0, t4 = 0;
                    if (x2 != n)t2 = hsh[x2 + 1][y1];
                    if (y2 != m)t3 = hsh[x1][y2 + 1];
                    if (x2 != n && y2 != m)t4 = hsh[x2 + 1][y2 + 1];
                    int sum_curr = t1 - t2 - t3 + t4;
                    mx = max(mx, sum_curr);
                }
            }
        }
    }

    return mx;
}

void yash()
{
    cin >> n >> m;
    v.resize(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    cout << maxSum_On4() << "\n";
    cout << maxSum_On3() << "\n";

}

signed main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // test
    yash();
    return 0;
}