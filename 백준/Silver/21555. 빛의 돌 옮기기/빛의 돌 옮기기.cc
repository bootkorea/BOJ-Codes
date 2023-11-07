#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define MAX 200000 + 1
using namespace std;

ll N, K, result = 0;
ll arr[MAX][2][2];
vector<pii> vec;

ll Solve(int i, int carry, int pickup)
{
    if (i == N)
        return 0;

    result = arr[i][carry][pickup];
    if (result != -1)
        return result;

    result = 0;
    if (carry == 1)
        result = min(Solve(i + 1, carry, pickup) + vec[i].first, Solve(i + 1, 0, 1) + vec[i].second + K);
    if (pickup == 1)
        result = min(Solve(i + 1, carry, pickup) + vec[i].second, Solve(i + 1, 1, 0) + vec[i].first + K);

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vec.resize(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i].first;
    for (int i = 0; i < N; i++)
        cin >> vec[i].second;

    memset(arr, -1, sizeof(arr));

    cout << min(Solve(1, 1, 0) + vec[0].first, Solve(1, 0, 1) + vec[0].second);

    return 0;
}