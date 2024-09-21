#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(501, vector<int>(501, 9876543221));
pair<int, int> matrix[501];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> matrix[i].first >> matrix[i].second;
		dp[i][i] = 0;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			for (int k = j; k < j + i; k++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + matrix[j].first * matrix[k].second * matrix[j + i].second);
			}
		}
	}

	cout << dp[1][N] << endl;

	return 0;
}