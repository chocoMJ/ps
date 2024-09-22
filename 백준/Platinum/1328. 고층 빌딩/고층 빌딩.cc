#include <iostream>

using namespace std;

long long dp[101][101];
long long C[101][101];
long long f[101];

const long long MOD = 1000000007;

static void set_C() {
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = ((C[i - 1][j - 1] % MOD) + (C[i - 1][j] % MOD)) % MOD;
		}
	}
}

void set_f() {
	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i <= 100; i++) {
		f[i] = (i * f[i - 1]) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long ans = 0;
	long long N, L, R;

	set_C();
	set_f();

	cin >> N >> L >> R;

	if (N <= 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = f[i - 1];
				continue;
			}
			else if (j == i) {
				dp[i][j] = 1;
				continue;
			}
			for (int pos = j; pos <= i; pos++) {
				dp[i][j] += ((dp[pos - 1][j - 1] * f[i - pos] % MOD) * C[i - 1][pos - 1]) % MOD;
				dp[i][j] %= MOD;
			}
		}
	}

	for (long long pos = L; pos <= N - R + 1; pos++) {
		if (pos == 1) ans += (C[N - 1][pos - 1] * dp[N - pos][R - 1]) % MOD;
		else if (pos == N) ans += (C[N - 1][pos - 1] * dp[pos - 1][L - 1]) % MOD;
		else if (pos >= 1 && pos <= N) ans += (((C[N - 1][pos - 1] * dp[pos - 1][L - 1]) % MOD) * dp[N - pos][R - 1]) % MOD;

		ans %= MOD;
	}

	cout << ans % MOD << endl;

	return 0;
}