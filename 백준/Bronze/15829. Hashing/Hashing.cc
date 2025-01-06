#include <iostream>
#include <string>

using namespace std;

const int MOD = 1234567891;
const int R = 31;

int main() {
	int dp[51];
	int L;
	int hash = 0;
	string s;
	cin >> L;
	cin >> s;

	dp[0] = 1;
	dp[1] = R;
	for (int i = 2; i <= 50; i++) {
		dp[i] = (dp[i - 1] * R) % MOD;
	}

	for (int i = 0; i < L; i++) {
		hash += ((s[i] - 'a' + 1) * dp[i]) % MOD;
	}

	cout << hash << endl;

	return 0;
}