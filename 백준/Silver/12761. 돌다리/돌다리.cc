#include <bits/stdc++.h>
#define MAX 100000 + 1
using namespace std;

int A, B, N, M;
int arr[MAX];
int Visited[MAX];
queue<int> q;

int main()
{
    cin >> A >> B >> N >> M;
    int dist[6] = {1,
                   -1,
                   A,
                   B,
                   -A,
                   -B};

    arr[N] = 0;
    Visited[N] = 1;
    q.push(N);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        if (temp == M)
        {
            cout << arr[M];
            break;
        }

        for (int i = 0; i < 6; i++)
        {
            int next = temp + dist[i];
            if (next < 0 || next >= MAX)
                continue;

            if (!Visited[next])
            {
                Visited[next] = 1;
                arr[next] = arr[temp] + 1;
                q.push(next);
            }
        }

        for (int i = 2; i < 4; i++)
        {
            int next = temp * dist[i];
            if (next < 0 || next >= MAX)
                continue;

            if (!Visited[next])
            {
                Visited[next] = 1;
                arr[next] = arr[temp] + 1;
                q.push(next);
            }
        }
    }

    return 0;
}