#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 11;
	int N, M;
	cin >> N >> M;

	vector<int> can_solve(M);

	for (int i = 0; i < M; i++) {
		int num_Q, solve = 0;
		cin >> num_Q;

		while (num_Q--) {
			int Q;
			cin >> Q;
			solve += (1 << (Q - 1));
		}
		can_solve[i] = solve;
	}

	for (int team = 1; team < (1 << M); team++) {
		int solved = 0;
		int num_team = 0;
		for (int i = 0; i < M; i++) {
			if (team & (1 << i)) {
				solved = solved | can_solve[i];
				num_team++;
			}
		}
		if (solved == ((1 << N) - 1)) ans = min(num_team, ans);
	}
	if (ans == 11) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}