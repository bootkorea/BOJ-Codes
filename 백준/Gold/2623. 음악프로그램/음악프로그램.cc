#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int indegree[1001];
vector<int> vec[1001];
vector<int> result;
vector<int> tem;

void Solve()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		result.push_back(temp);
		
		for(int i = 0; i < vec[temp].size(); i++)
		{
			int next = vec[temp][i];
			indegree[next]--;
			
			if(indegree[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int main() 
{
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int cnt, temp, num;
		cin >> cnt;
		
		cin >> temp;
		for(int j = 1; j < cnt; j++)
		{
			cin >> num;
			vec[temp].push_back(num);
			indegree[num]++;
			temp = num; // next turn
		}
	}
	
	Solve();
	
	if(result.size() != N)
	{
		for(int i = 0; i < result.size(); i++)
		{
			result.pop_back();
		}
		tem.push_back(0);
	}
	else
	{
		tem = result;
	}
	
	for(int i = 0; i < tem.size(); i++)
	{
		cout << tem[i] << "\n";
	}
	
	return 0;
}