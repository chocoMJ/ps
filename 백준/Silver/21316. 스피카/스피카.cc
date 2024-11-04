#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<vector<int>> star(13);

void input() {
	for (int i = 1; i <= 12; i++) {
		int a, b;
		cin >> a >> b;
		star[a].push_back(b);
		star[b].push_back(a);
	}
}

int sum_edge(int n) {
	int sum = 0;
	for (int i = 0; i < star[n].size(); i++) {
		sum += star[star[n][i]].size();
	}
	return sum;
}

int main() {
	input();

	for (int i = 1; i < 13; i++) {
		if (star[i].size() == 1) {
			if (sum_edge(star[i][0]) == 6) {
				cout << star[i][0] << endl;
			}
		}
	}
}