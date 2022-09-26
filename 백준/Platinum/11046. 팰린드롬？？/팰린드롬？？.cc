#include <bits/stdc++.h>
#define MAX 1000000 * 2 + 1
using namespace std;

int N, M;
int arr[MAX], temp[MAX];

void manacher()
{
	int r = 0, p = 0;
	for (int i = 0; i < N; i++)
	{
		if (i <= r) arr[i] = min(arr[2 * p - i], r - i);
		else arr[i] = 0;

		while ((i - arr[i] - 1 >= 0 && i + arr[i] + 1 <=  N - 1) && (temp[i - arr[i] - 1] == temp[i + arr[i] + 1]))
		{
			arr[i]++;
		}

		if (r < i + arr[i])
		{
			r = i + arr[i];
			p = i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		temp[i * 2] = 0;
		cin >> temp[i * 2 + 1];
	}
	N = N * 2 + 1;
	temp[N - 1] = 0;

	manacher();

	cin >> M;
	while (M--)
	{
		int x, y; cin >> x >> y; x--; y--;

		if (arr[x + y + 1] >= y - x + 1) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}