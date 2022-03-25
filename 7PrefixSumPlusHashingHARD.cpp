// 01-05-2021

/*
// HackerEarth : Luffy asks "IsPalin" ?
Luffy with his crew is on the way to Dressrosa, where he will be fighting one of the warlords of the sea Doflamingo. But now he is getting bored and wants do a fun activity. He is very much obsessed with palindromes. Given a string S of lower case English alphabet of length N and two Integers L and R he wants to know whether all the letters of the substring from index L to R (L and R included) can be rearranged to form a palindrome or not. He wants to know this for Q values of L and R and needs your help in finding the answer.
Palindrome is a string of characters which when reversed reads same as the original String.

CONSTRAINTS :

1 ≤ t ≤ 10

1 ≤ N, Q ≤ 100000

1 ≤ L ≤ R ≤ N

'a' ≤ S[i] ≤ 'z' for 1 ≤ i ≤ N

INPUT :

First line contains an integer t denoting the number of test cases

First line of each test case contains 2 space separated integers N and Q, the length of the string and number of queries respectively

Next line contains the string S

Each of the Next Q lines contain 2 space separated integers L and R

OUTPUT :

For each query of each test case print "YES" without quotes if letters of the substring from L to R can be rearranged to form a palindrome otherwise output "NO" in new line

Sample Input
2
5 5
abcec
1 2
2 5
3 5
1 5
1 4
5 5
aabbc
1 2
2 5
3 5
1 5
1 4
Sample Output
NO
NO
YES
NO
NO
YES
NO
YES
YES
YES

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
const int N = 1e5 + 7;

int hsh[N][26];

void yash()
{
	rep(i, 0, N)rep(j, 0, 26)hsh[i][j] = 0;
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	rep(i, 0, n)hsh[i + 1][s[i] - 'a']++;
	rep(i, 0, 26)rep(j, 1, n + 1)hsh[j][i] += hsh[j - 1][i];
	while (q--) {
		int l, r;
		cin >> l >> r;
		int oddCnt = 0;
		rep(i, 0, 26) {
			int charCnt = hsh[r][i] - hsh[l - 1][i];
			if (charCnt % 2 != 0)oddCnt++;
		}
		if (oddCnt > 1)cout << "NO\n";
		else cout << "YES\n";
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}