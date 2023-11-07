#include <bits/stdc++.h>
#define MAX 100000 + 1
#define ll long long int
using namespace std;

ll N, Q;
ll arr[MAX], temp[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            temp[i] = 1;
    }

    for (int i = 2; i <= N; i++)
        temp[i] += temp[i - 1];

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y, result = 0;
        cin >> x >> y;

        cout << temp[y - 1] - temp[x - 1] << "\n";
    }

    return 0;
}