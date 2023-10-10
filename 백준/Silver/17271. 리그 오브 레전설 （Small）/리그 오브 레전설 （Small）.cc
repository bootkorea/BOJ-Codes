#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define MAX 10000 + 1
#define DIV 1000000007
using namespace std;

int N, M, result = 1;
int DP[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    DP[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        DP[i] = DP[i - 1];

        if (i - M >= 0)
            DP[i] = (DP[i] + DP[i - M]) % DIV;
    }

    cout << DP[N];

    return 0;
}