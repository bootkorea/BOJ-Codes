#include <bits/stdc++.h>
#define ll long long
const int MAX = 1e5 + 1;
using namespace std;

ll N;
ll result = 0;
int arr[MAX + MAX];
pair<int, int> p[50000 + 1];
bool b[50000 + 1];

int query(int l, int r)
{
    int res = 0;

    for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1)
    {
        if (l % 2 == 1) res += arr[l++];
        if (r % 2 == 1) res += arr[--r];
    }
    return res;
}

void update(int x, int val)
{
    for (arr[x += MAX] = val; x > 1; x >>= 1)
    {
        arr[x >> 1] = arr[x] + arr[x ^ 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N * 2; i++)
    {
        int x; cin >> x;
        if (!b[x])
        {
            b[x] = 1;
            p[x - 1].first = i;
        }
        else
        {
            b[x] = 0;
            p[x - 1].second = i;
        }
    }
    sort(p, p + N);

    for (int i = 0; i < N; i++)
    {
        result += query(p[i].first + 1, p[i].second);
        update(p[i].second, 1);
    }
    cout << result;

    return 0;
}