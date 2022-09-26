#include <bits/stdc++.h>
#define MAX 100000 * 2 + 1
using namespace std;

int result = 0;
int arr[MAX];
string str, temp;

void manacher(string s, int n)
{
	int r = 0, p = 0;
	for (int i = 0; i < n; i++)
	{
		if (i <= r) arr[i] = min(arr[2 * p - i], r - i);
		else arr[i] = 0;

		while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < n && s[i - arr[i] - 1] == s[i + arr[i] + 1])
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

	getline(cin, str);
	int len = str.size();

	for (int i = 0; i < len; i++)
	{
		temp += '#';
		temp += str[i];
	}
	temp += '#';

	manacher(temp, temp.size());
	
	for (int i = 0; i < temp.size(); i++)
	{
		result = max(result, arr[i]);
	}

	cout << result;

	return 0;
}