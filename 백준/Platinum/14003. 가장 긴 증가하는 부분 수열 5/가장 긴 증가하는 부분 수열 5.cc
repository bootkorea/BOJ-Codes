#include <bits/stdc++.h>
#define MAX 1000000 + 1
using namespace std;

int N, idx;
int arr[MAX];
int dp[MAX];
vector<int> vec, result;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	vec.push_back(arr[0]);

	for (int i = 1; i < N; i++)
	{
		if (vec[idx] < arr[i])
		{
			vec.push_back(arr[i]);
			idx++;
			dp[i] = idx;
		}
		else
		{
			int cnt = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
			vec[cnt] = arr[i];
			dp[i] = cnt;
		}
	}

	cout << idx + 1 << "\n";

	for (int i = N - 1; i >= 0 && idx >= 0; i--)
	{
		if (dp[i] == idx)
		{
			result.push_back(arr[i]);
			idx--;
		}
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}