#include <bits/stdc++.h>
#define MAX 50 + 1
using namespace std;

int N, result = 0;
vector<int> vec;

int main()
{
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    vector<int> DP(N, 0);

    for (int i = 0; i < N; i++)
    {
        double MAX_INC = -1e10;
        for (int j = i + 1; j < N; j++)
        {
            double inc = (double)(vec[j] - vec[i]) / (j - i);
            if (inc > MAX_INC)
            {
                DP[i]++;
                DP[j]++;
                MAX_INC = inc;
            }
        }
    }

    for (auto x : DP)
    {
        result = max(result, x);
    }
    cout << result << '\n';

    return 0;
}