#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(1000001);

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	while (M--) {
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}