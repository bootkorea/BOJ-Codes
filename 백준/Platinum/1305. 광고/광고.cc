#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
string str, pattern;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> str; pattern = str;
	vec.resize(N + 1);

	int j = 0;
	for (int i = 1; i < N; i++)
	{
		while (j > 0 && pattern[j] != str[i])
		{
			j = vec[j - 1];
		}
		if (str[i] == pattern[j]) vec[i] = ++j;
	}
	cout << N - vec[N - 1];

	return 0;
}