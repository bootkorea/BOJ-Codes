#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> vec;

int main()
{
    cin >> N;
    vec.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), [](string &a, string &b)
         { return a.length() < b.length(); });

    vector<bool> result(N, 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (vec[j].substr(0, vec[i].length()) == vec[i])
            {
                result[i] = 0;
                break;
            }
        }
    }

    int answer = count(result.begin(), result.end(), 1);
    cout << answer << endl;

    return 0;
}