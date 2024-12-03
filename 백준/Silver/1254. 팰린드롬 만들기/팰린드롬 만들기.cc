#include <bits/stdc++.h>
using namespace std;

string str;
int result = 0;
bool flag = 0;

bool Solve(string s)
{
    int len = s.length() / 2;

    for (int i = 0; i < len; i++)
    {
        if (s[i] != s[s.length() - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    cin >> str;
    result = str.length() * 2 - 1;
    for (int i = 0; i < str.length(); i++)
    {
        string temp = str.substr(i, str.length());

        if (Solve(temp))
        {
            result = str.length() + i;
            break;
        }
    }

    cout << result;

    return 0;
}