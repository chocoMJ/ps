#include <iostream>

using namespace std;

int parent[1000000];

int find(int x) {
	if (x == parent[x]) return x;
	return find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		for (int i = 0; i < 100000; i++) {
			parent[i] = i;
		}

		cout << "Scenario " << t << ":" << endl;
		int num_user, num_relation;
		cin >> num_user;
		cin >> num_relation;

		for (int i = 0; i < num_relation; i++) {
			int a, b;
			cin >> a >> b;
			merge(a, b);
		}
		int m;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (find(a) == find(b)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << endl;
	}
}