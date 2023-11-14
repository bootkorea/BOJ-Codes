#include <bits/stdc++.h>
#define MAX 16
#define ll long long int
using namespace std;

int N, M, K;
int DP[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    int kx, ky;
    if (!K)
        kx = N, ky = N;
    else if (K % M == 0)
        kx = K / M - 1, ky = M - 1;
    else
        kx = K / M, ky = K % M - 1;

    for (int i = 0; i < MAX; i++)
    {
        DP[i][0] = 1;
        DP[0][i] = 1;
    }

    for (int i = 1; i <= kx; i++)
    {
        for (int j = 1; j <= ky; j++)
        {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }

    for (int i = 0; i < MAX; i++)
        DP[kx][i] = DP[kx][ky];
    for (int i = 0; i < MAX; i++)
        DP[i][ky] = DP[kx][ky];

    for (int i = kx + 1; i < N; i++)
    {
        for (int j = ky + 1; j < M; j++)
        {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }

    cout << DP[N - 1][M - 1];

    return 0;
}
