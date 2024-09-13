#include <iostream>
#include <vector>

using namespace std;

long long dp[37];

long long solve(long long n) {
	long long ans = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			ans += dp[i] * dp[n - i - 1];
		}
		ans *= 2;
	}
	else {
		for (int i = 0; i <= n / 2 - 1; i++) {
			ans += dp[i] * dp[n - i - 1];
		}
		ans *= 2;
		ans += dp[n / 2] * dp[n / 2];
	}
	return ans;
}

int main() {
	int N;
	cin >> N;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = solve(i);
	}
	cout << dp[N] << endl;
	return 0;
}