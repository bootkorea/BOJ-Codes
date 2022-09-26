#include <bits/stdc++.h>
#define MAX 500000 + 1
#define INF 987654321
using namespace std;

int N;
int arr[MAX], temp[MAX];
long long result = 0;

void Merge(int x, int num, int y)
{
	int idx = x;
	int i = x;
	int j = num + 1;
	long long cnt = 0;

	while (i <= num || j <= y)
	{
		if (i > num)
		{
			temp[idx++] = arr[j++];
			cnt++;
		}
		else if (j > y)
		{
			temp[idx++] = arr[i++];
			result += cnt;
		}
		else if (arr[i] <= arr[j])
		{
			temp[idx++] = arr[i++];
			result += cnt;
		}
		else
		{
			temp[idx++] = arr[j++];
			cnt++;
		}
	}

	for (i = x; i <= y; i++)
	{
		arr[i] = temp[i];
	}
}

void Solve(int x, int y)
{
	int num;

	if (x < y)
	{
		num = (x + y) / 2;

		Solve(x, num);
		Solve(num + 1, y);
		Merge(x, num, y);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	Solve(0, N - 1);

	cout << result;

	return 0;
}