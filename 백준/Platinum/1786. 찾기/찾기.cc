#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string str, pattern;
vector<int> vec;
vector<int> ans;
int result = 0;

void preset()
{
	vec.resize(pattern.size(), 0);

	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = vec[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			vec[i] = ++j;
		}
	}
}

void KMP()
{
	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		while (j > 0 && str[i] != pattern[j])
		{
			j = vec[j - 1];
		}
		if (str[i] == pattern[j])
		{
			if (j == pattern.size() - 1)
			{
				ans.push_back(i - pattern.size() + 2);
				result++;
				j = vec[j];
			}
			else j++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	getline(cin, str); getline(cin, pattern);
	
	preset();
	KMP();

	cout << result << "\n";
	for (auto& w : ans)
	{
		cout << w << " ";
	}

	return 0;
}