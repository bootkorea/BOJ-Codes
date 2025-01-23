#include <iostream>
#include <stdio.h>
#define MAX 50 + 1
using namespace std;

int N, M, result = 0;
int arr1[MAX][MAX], arr2[MAX][MAX];

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &arr1[i][j]);
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < N - 2; i++)
    {
        for(int j = 0; j < M - 2; j++)
        {
            if(arr1[i][j] != arr2[i][j])
            {
                for(int x = i; x <= i + 2; x++)
                {
                    for(int y = j; y <= j + 2; y++)
                    {
                        arr1[x][y] = 1 - arr1[x][y];
                    }
                }
                result++;
            }
            else continue;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr1[i][j] != arr2[i][j])
            {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << result;
    
    return 0;
}