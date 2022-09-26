#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int N, M;
int Parent[MAX][20], Depth[MAX];
bool Visited[MAX];
queue<int> q;
vector<int> vec[MAX];

int Solve(int x, int y)
{
	if(Depth[x] > Depth[y]) swap(x, y);
	while(Depth[x] != Depth[y])
	{
		int gap = Depth[y] - Depth[x];
		for(int i = 0; i < 20; i++)
		{
			if(gap <= (2<<i))
			{
				y = Parent[y][i];
				break;
			}
		}
	}
	
	while(x != y)
	{
		for(int i = 0; i < 20; i++)
		{
			if(Parent[x][i + 1] == Parent[y][i + 1])
			{
				x = Parent[x][i];
				y = Parent[y][i];
				break;
			}
		}
	}
	return x;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N -1; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	Visited[1] = 1;
	q.push(1);
	
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		
		for(int i = 0; i < vec[temp].size(); i++)
		{
			int num = vec[temp][i];
			if(!Visited[num])
			{
				Depth[num] = Depth[temp] + 1;
				Visited[num] = 1;
				Parent[num][0] = temp;
				
				for(int j = 0; j < 20; j++)
				{
					Parent[num][j + 1] = Parent[Parent[num][j]][j];
					if(Parent[num][j + 1] == 0) break;
				}
				
				q.push(num);
			}
		}
	}
	
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << Solve(a, b) << "\n";
	}
	
	return 0;
}

//https://jason9319.tistory.com/90