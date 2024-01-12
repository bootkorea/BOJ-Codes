#include <bits/stdc++.h>
#define MAX 1000 + 1
using namespace std;

int T, N;
vector<int> vec[MAX];
int Visited[MAX];

void DFS(int x)
{
    Visited[x] = 1;
    for (int i = 0; i < vec[x].size(); i++)
    {
        int next = vec[x][i];
        if (!Visited[next])
            DFS(next);
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        int result = 0;
        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            vec[i].clear();
            Visited[i] = 0;
        }

        for (int i = 1; i <= N; i++)
        {
            int x;
            cin >> x;
            vec[i].push_back(x);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!Visited[i])
            {
                DFS(i);
                result++;
            }
        }
        cout << result << "\n";
    }

    return 0;
}