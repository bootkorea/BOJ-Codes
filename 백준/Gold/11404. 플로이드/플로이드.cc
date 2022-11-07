#include <iostream>
#define INF 987654321
using namespace std;

int N, M;
int arr[101][101];

int main() 
{
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) // 비용 설정
	{
		for(int j = 0; j < N; j++)
		{
			arr[i][j] = INF;
		}
		arr[i][i] = 0; // 제자리 노코스트
	}
	
	for(int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		a--, b--;
		
		arr[a][b] = min(c, arr[a][b]);
	}
	
	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(arr[i][j] == INF) arr[i][j] = 0;
			
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}