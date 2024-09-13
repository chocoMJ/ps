#include <iostream>

using namespace std;

int dp[10001];

int start_2(int num) {
	return num / 2 + 1;
}

int main() {
	int T, n;
	cin >> T;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	while (T--) {
		cin >> n;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 3] + start_2(i - 2) + 1;
		}
		cout << dp[n] << endl;
	}

	

	return 0;
}