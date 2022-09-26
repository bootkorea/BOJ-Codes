#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
const int MAX = 10000 + 1;
using namespace std;

int V, E, id, result = 0;
int arr[MAX];
bool IsSCC[MAX];

stack<int> st;
vector<int> vec[MAX];
vector<vector<int>> point;

int DFS(int x)
{
    arr[x] = ++id;
    st.push(x);

    int cnt = arr[x];

    for (int d : vec[x])
    {
        if (arr[d] == 0) cnt = min(cnt, DFS(d));
        else if (!IsSCC[d]) cnt = min(cnt, arr[d]);
    }

    if (cnt == arr[x])
    {
        vector<int> v;
        while (1)
        {
            int temp = st.top();
            st.pop();

            v.push_back(temp);
            IsSCC[temp] = true;

            if (temp == x) break;
        }
        sort(v.begin(), v.end());
        point.push_back(v);
        result++;
    }
    return cnt;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int x, y; cin >> x >> y;
        vec[x].push_back(y);
    }

    for (int i = 1; i <= V; i++)
    {
        if (arr[i] == 0) DFS(i);
    }

    cout << result << "\n";
    sort(point.begin(), point.end());

    for (auto cur : point)
    {
        for (int scc : cur)
        {
            cout << scc << " ";
        }
        cout << "-1\n";
    }
    
    return 0;
}