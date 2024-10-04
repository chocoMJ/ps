#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, L, R, X;
	int ans = 0;

	cin >> N >> L >> R >> X;
	vector<int> question(N);

	for (int i = 0; i < N; i++) {
		cin >> question[i];
	}

	for (int i = 1; i < (1 << N); i++) {
		int min_dif = 987654321;
		int max_dif = 0;
		int sum_dif = 0;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				min_dif = min(min_dif, question[j]);
				max_dif = max(max_dif, question[j]);
				sum_dif += question[j];
			}
		}

		if (sum_dif >= L && sum_dif <= R && (max_dif - min_dif) >= X) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}