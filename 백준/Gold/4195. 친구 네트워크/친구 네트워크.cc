#include <iostream>
#include <string>
#include <map>
#include <memory.h>

using namespace std;

int num_friend[200002];
int parent[200002];
map<string, int> mapset;

void setting(int& num_people, string a, string b) {
	if (mapset.find(a) != mapset.end()) {
		if (mapset.find(b) == mapset.end()) {
			mapset.insert({ b, num_people });
			num_people++;
		}
	}
	else {
		mapset.insert({ a, num_people });
		num_people++;
		if (mapset.find(b) == mapset.end()) {
			mapset.insert({ b, num_people });
			num_people++;
		}
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;

	int x1 = num_friend[x];
	int y1 = num_friend[y];

	num_friend[x] += y1;
	num_friend[y] += x1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		mapset.clear();
		for (int i = 0; i < 200002; i++) {
			num_friend[i] = 1;
		}
		int num_people = 0;
		int F;
		cin >> F;

		for (int i = 0; i < F * 2; i++) {
			parent[i] = i;
		}

		while (F--) {
			string a, b;
			cin >> a >> b;
			
			setting(num_people, a, b);

			int c = mapset[a];

			merge(c, mapset[b]);

			cout << num_friend[find(c)] << '\n';
		}
	}
}