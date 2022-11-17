#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define tiii tuple<int, int, int>
const int MAX = 2000 + 1;
const int INF = 1e9;
using namespace std;

int T;
int n, m, t, s, g, h;
int path = 0;
int sdist[MAX], gdist[MAX], hdist[MAX];
vector<pii> vec[MAX];
vector<int> dest;

void dijkstra(int x, int result[MAX])
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, x });
	result[x] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur][i].first;
			int costcost = vec[cur][i].second;

			if (result[next] > cost + costcost)
			{
				result[next] = cost + costcost;
				pq.push({ -result[next], next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < MAX; i++)
		{
			vec[i].clear();
			sdist[i] = INF;
			gdist[i] = INF;
			hdist[i] = INF;
		}
		dest.clear();

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++)
		{
			int a, b, d; cin >> a >> b >> d;
			vec[a].push_back({ b, d });
			vec[b].push_back({ a, d });
		}
		for (int i = 0; i < t; i++)
		{
			int x; cin >> x;
			dest.push_back(x);
		}

		dijkstra(s, sdist);
		dijkstra(g, gdist);
		path = gdist[h];
		dijkstra(h, hdist);

		sort(dest.begin(), dest.end());
		for (int i = 0; i < dest.size(); i++)
		{
			int temp = dest[i];
			if (sdist[temp] == sdist[g] + path + hdist[temp]) cout << temp << " ";
			else if (sdist[temp] == sdist[h] + path + gdist[temp]) cout << temp << " ";
		} 
		cout << "\n";
	}
	return 0;
}