#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[10];
int arr[10];
bool is_used[10];

void bkt(int p)
{
	if (p == M)
	{
		for (int i = 0; i < M; ++i) cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	int pre = 0;
	for (int i = 0; i < N; ++i)
	{
		if (is_used[i]) continue;
		if (num[i] == pre) continue;
		pre = num[i];

		arr[p] = i;
		is_used[i] = true;
		bkt(p + 1);
		is_used[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> num[i];
	sort(num, num + N);

	bkt(0);

	return 0;
}
