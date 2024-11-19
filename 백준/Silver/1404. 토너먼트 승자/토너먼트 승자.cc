#include <bits/stdc++.h>
#define MAX 8
using namespace std;

double arr[MAX][MAX];
double DP[4][MAX];

int main()
{
    // 입력 처리
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (i < j)
            {
                cin >> arr[i][j];
                arr[i][j] /= 100.0;
                arr[j][i] = 1 - arr[i][j];
            }
        }
    }

    for (int i = 0; i < MAX; i++)
        DP[0][i] = 1.0;

    for (int round = 1; round <= 3; round++)
    {
        int Size = (1 << round);
        for (int i = 0; i < MAX; i += Size)
        {
            for (int j = i; j < i + Size / 2; j++)
            {
                for (int k = i + Size / 2; k < i + Size; k++)
                {
                    DP[round][j] += DP[round - 1][j] * DP[round - 1][k] * arr[j][k];
                    DP[round][k] += DP[round - 1][j] * DP[round - 1][k] * arr[k][j];
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
        cout << fixed << setprecision(9) << DP[3][i] << " ";

    return 0;
}