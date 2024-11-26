#include <bits/stdc++.h>
using namespace std;

int N, result = 0;
vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back(b - a);
    }
    sort(vec.begin(), vec.end());

    if (!(N % 2))
    {
        int mid = N / 2;
        cout << vec[mid] - vec[mid - 1] + 1;
    }
    else
        cout << 1;

    return 0;
}