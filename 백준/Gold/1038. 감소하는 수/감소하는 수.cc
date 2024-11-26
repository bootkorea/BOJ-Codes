#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll N, result = 9;
queue<ll> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if (N < 10)
    {
        cout << N;
        return 0;
    }
    else if (N == 1022)
    {
        cout << 9876543210;
        return 0;
    }
    else if (N > 1022)
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (ll i = 1; i < 10; i++)
            q.push(i);

        while (result <= N)
        {
            ll temp = q.front();
            q.pop();

            ll last = temp % 10;
            for (ll i = 0; i < last; i++)
            {
                q.push(temp * 10 + i);
                result++;

                if (result == N)
                {
                    cout << temp * 10 + i;
                }
            }
        }
    }

    return 0;
}