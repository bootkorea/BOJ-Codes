#include <iostream>
#define MAX 100000 + 1
using namespace std;

int N;
int arr[MAX][2 + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[1][2] = 1;

    for(int i = 2; i <= N; i++)
    {
        arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % 9901;
        arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
        arr[i][2] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
    }

    cout << (arr[N][0] + arr[N][1] + arr[N][2]) % 9901;

    return 0;
}