#include <bits/stdc++.h>
using namespace std;

int N, K;
int tree[1 << 20];

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = 1; // 시작 : 1
	int mid = (start + end) / 2; // 아닌 경우 중간값 찾기

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1); // 세그먼트 트리 값 구하기
}

int query(int start, int end, int node, int turn)
{
	if (start == end) return start;

	int mid = (start + end) / 2;

	if (turn <= tree[node * 2]) return query(start, mid, node * 2, turn);
	else return query(mid + 1, end, node * 2 + 1, turn - tree[node * 2]);
}

int update(int start, int end, int node, int del)
{
	tree[node]--;
	if (start == end) return 0;
	else
	{
		int mid = (start + end) / 2;
		if (del <= mid) return update(start, mid, node * 2, del);
		else return update(mid + 1, end, node * 2 + 1, del);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int index = 1;

	cin >> N >> K;
	init(1, N, 1);

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		int size = N - i;
		index += K - 1;

		if (index % size == 0) index = size;
		else if (index > size) index %= size;

		int num = query(1, N, 1, index);
		update(1, N, 1, num);

		if (i == N - 1) cout << num;
		else cout << num << ", ";
	}
	cout << ">";

	return 0;
}