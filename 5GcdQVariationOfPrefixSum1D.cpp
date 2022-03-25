// 01-05-2021

// 01-05-2021

//GCDQ
/*
Gcd Queries Problem Code: GCDQ
Add problem to Todo list
Submit

Read problems statements in Mandarin Chinese and Russian.
You are given an array A of integers of size N. You will be given Q queries where each query is represented by two integers L, R. You have to find the gcd(Greatest Common Divisor) of the array after excluding the part from range L to R inclusive (1 Based indexing). You are guaranteed that after excluding the part of the array remaining array is non empty.

Input
First line of input contains an integer T denoting number of test cases.
For each test case, first line will contain two space separated integers N, Q.
Next line contains N space separated integers denoting array A.
For next Q lines, each line will contain a query denoted by two space separated integers L, R.
Output
For each query, print a single integer representing the answer of that query.
Constraints
Subtask #1: 40 points

2 ≤ T, N ≤ 100, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 105
1 ≤ L, R ≤ N and L ≤ R
Subtask #2: 60 points

2 ≤ T, N ≤ 105, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 105
1 ≤ L, R ≤ N and L ≤ R
Sum of N over all the test cases will be less than or equal to 106.
Example
Input:
1
3 3
2 6 9
1 1
2 2
2 3

Output:
3
1
2
Explanation
For first query, the remaining part of array will be (6, 9), so answer is 3. For second query, the remaining part of array will be (2, 9), so answer is 1. For third query, the remaining part of array will be (2), so answer is 2.

Warning : Large IO(input output), please use faster method for IO.
*/

//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(x, arr)           memset((arr),x,sizeof((arr))
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void yash()
{
	int n, q;
	cin >> n >> q;
	int forwardGCD[n + 2] = {0};
	int backwardGCD[n + 2] = {0};
	int arr[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	for (int i = 1; i <= n; ++i)
		forwardGCD[i] = __gcd(forwardGCD[i - 1], arr[i]);
	for (int i = n; i >= 1; --i)
		backwardGCD[i] = __gcd(backwardGCD[i + 1], arr[i]);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << __gcd(forwardGCD[l - 1], backwardGCD[r + 1]) << "\n";
	}
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}