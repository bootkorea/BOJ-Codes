#include <bits/stdc++.h>
#define MAX 100 + 1
using namespace std;

int N, temp = 0, result = 1;
int arr[MAX][MAX], Visited[MAX][MAX];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void DFS(int x, int y, int k)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;

        if (arr[nx][ny] > k && !Visited[nx][ny])
        {
            Visited[nx][ny] = 1;
            DFS(nx, ny, k);
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] > temp)
                temp = arr[i][j];
        }
    }

    for (int k = 0; k <= temp; k++)
    {
        int cnt = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Visited[i][j] = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] > k && !Visited[i][j])
                {
                    cnt++;
                    Visited[i][j] = 1;
                    DFS(i, j, k);
                }
            }
        }

        if (cnt > result)
            result = cnt;
    }
    cout << result;

    return 0;
}