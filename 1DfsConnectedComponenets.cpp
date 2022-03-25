// 26-04-2021

/*
Maximum Size Problem Code: RISK
Add problem to Todo list
Submit (Practice)


Chef is playing an easier variation of the board game ‘Risk’ with his friend Mike. There is an N∗M grid, depicting the world map. Each cell of the grid is either 1 or 0 where 1 denotes that there is land on this cell, while 0 denotes water.

In a turn, a player can capture an uncaptured cell that has land, and keep capturing neighbouring cells that share a side with it if they are on land. A cell once captured by a player can't be captured again by another player. The game continues till no uncaptured cell has land. Each player wants to be in control of as many cells of land as possible in total when the game finishes. Find the maximum number of cells of land that Chef can capture if he plays second, and both players play optimally.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains N+1 lines of input.
First line will contain 2 space separated integers N and M denoting the size of the grid.
Each of the next N lines contains a binary string of length M depicting the map.
Output:




For each testcase, output in a single line answer to the problem.

Constraints
1≤N,M≤105
Each character in the grid is either 0 or 1
There's atleast 1 land on the grid
Sum of N∗M over all testcases is almost 106.
Sample Input:
3
4 4
1001
0110
0110
1001
2 2
11
11
3 3
100
010
001
Sample Output:
2
0
1
*/

//YashS
#include <bits/stdc++.h>
#define int long long
#define test  \
    int T;    \
    cin >> T; \
    while (T--)
using namespace std;
const int MOD = 1e9 + 7;

//1) Directions for checking whether a cell is valid or not
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//3) In DFS we need to map what is visited and what is not, which reduces time compexity as well as double counting.
vector<vector<int>> vis;
//2) checking, that it doesnt go outside the boundary
int n, m;
bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) // Checking boundaries
        return false;
    if (vis[x][y])
        return false; // If visited returns false
    return true;
}
int dfs(int x, int y)
{
    vis[x][y] = 1; //As now visited marked to 1
    int ans = 1;   //As a cell is connected to itself
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (!check(X, Y)) //If Visited or outside boundary continue
            continue;
        ans += dfs(X, Y); // If not visited and inside boundary
    }
    return ans;
}

void yash()
{
    cin >> n >> m;
    vis.clear();
    vis.resize(n, vector<int>(m)); //Making matrix of n*m
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '0') //Marking already visited
                vis[i][j] = 1;
        }
    }

    vector<int> sizes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check(i, j)) // Finding If not visited and inside boundary, then pushback the size of the connected component in sizes vector.
                sizes.push_back(dfs(i, j));
        }
    }

    // Now we have the sizes vector, with all the sizes of connected components.
    sort(sizes.begin(), sizes.end(), greater<int>());
    int answer = 0;

    // As chef plays second and alternatively, i = 1 && i+=2;
    for (int i = 1; i < sizes.size(); i += 2)
        answer += sizes[i];

    cout << answer << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    test{
        yash();
    }
    return 0;
}