#include <bits/stdc++.h>
#define MAX 100000 + 1
using namespace std;

int N, S, result = 0;
int arr[MAX], Visited[MAX];

void Solve(int x)
{
    if (x < 1 || x > N)
        return;
    Visited[x] = 1;

    Solve(x + arr[x]);
    Solve(x - arr[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    cin >> S;
    Solve(S);

    for (int i = 1; i <= N; i++)
    {
        if (Visited[i])
            result++;
    }
    cout << result;

    return 0;
}