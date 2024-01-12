#include <bits/stdc++.h>
#define MAX 20 + 1
using namespace std;

int N, result = 0;
int arr[MAX];
int Visited[MAX];
vector<string> vec[MAX];
map<string, int> mp;

void DFS(int x)
{
    Visited[x] = 1;
    arr[x] = 1;

    for (string name : vec[x])
    {
        int next = mp[name];

        if (!Visited[next])
            DFS(next);

        else if (arr[next])
            result++;
    }
    arr[x] = 0;
}

int main()
{
    int T = 0;
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;

        mp.clear();

        for (int i = 0; i < N; i++)
        {
            vec[i].clear();
            arr[i] = 0;
            Visited[i] = 0;
        }
        result = 0;

        for (int i = 0; i < N; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;

            if (mp.find(s1) == mp.end())
            {
                int size = mp.size();
                mp[s1] = size;
            }

            vec[mp[s1]].push_back(s2);
        }

        for (int i = 0; i < N; i++)
        {
            if (!Visited[i])
                DFS(i);
        }

        T++;
        cout << T << " " << result << "\n";
    }
    return 0;
}
