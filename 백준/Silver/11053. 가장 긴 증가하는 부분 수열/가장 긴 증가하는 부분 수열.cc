#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, result = 0;
	int arr[1001];
	int dp[1001];
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 0; i < N; i++)
	{
		dp[i] = 1;
		
		for (int j = 0; j < i; j++) 
		{
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) 
            {
            	dp[i] = dp[j] + 1;
            }
        }
	}
	
	for (int i = 0; i < N; i++) 
	{
		result = max(result, dp[i]);
	}
    
    cout << result;
	
	return 0;
}