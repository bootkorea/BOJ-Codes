#include <bits/stdc++.h>
const int MAX = 50;
using namespace std;

int result = 0;
int dp[MAX][MAX];
string str;

int Solve(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x >= y) return 0;

	dp[x][y] = min({ Solve(x + 1, y) + 1, Solve(x, y - 1) + 1, Solve(x + 1, y - 1) + (str[x] != str[y]) });
	
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	memset(dp, -1, sizeof(dp));

	int temp = str.length() - 1;
	result = Solve(0, temp);
	for (int i = 0; i < temp; i++)
	{
		for (int j = i + 1; j <= temp; j++)
		{
			memset(dp, -1, sizeof(dp));
			swap(str[i], str[j]);
			
			result = min(result, Solve(0, temp) + 1);
			swap(str[i], str[j]);
		}
	}
	cout << result;

	return 0;
}