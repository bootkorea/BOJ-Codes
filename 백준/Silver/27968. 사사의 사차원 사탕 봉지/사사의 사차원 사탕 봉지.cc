#include <bits/stdc++.h>
#define MAX 3000000 + 1
#define ll long long int
using namespace std;

int N, M;
ll arr[MAX];

int binarySearch(ll target) {
    int low = 0, high = M - 1;
    int result = M;  // 초기값을 배열 크기로 설정

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result + 1;  // 1을 더해주어서 1-based 인덱스로 반환
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    cin >> arr[0];
    for (int i = 1; i < M; i++) {
        int x;
        cin >> x;
        arr[i] = arr[i - 1] + x;
    }

    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;

        if (arr[M - 1] < x) {
            cout << "Go away!\n";
        } else {
            cout << binarySearch(x) << "\n";
        }
    }

    return 0;
}
