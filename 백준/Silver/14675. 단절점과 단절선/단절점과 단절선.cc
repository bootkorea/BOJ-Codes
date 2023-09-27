#include <bits/stdc++.h>
#define ll long long int
#define MAX 100000 + 1
using namespace std;

int N, Q;
vector<vector<int>> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vec.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int t, k;
        cin >> t >> k;

        if (t == 1)
        {
            if (vec[k].size() > 1)
                cout << "yes"
                     << "\n";
            else
                cout << "no"
                     << "\n";
        }
        else
            cout << "yes"
                 << "\n";
    }

    return 0;
}