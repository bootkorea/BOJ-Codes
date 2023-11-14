#include <bits/stdc++.h>
#define MAX 1000000 + 1
using namespace std;

int N, result = 0;
int arr[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int a, b, c;
    for (int i = N - 1; i >= 2; i--)
    {
        c = arr[i];
        b = arr[i - 1];
        a = arr[i - 2];
        if (c >= a + b)
            continue;
        else
        {
            result = a + b + c;
            cout << result;
            return 0;
        }
    }
    cout << -1;

    return 0;
}