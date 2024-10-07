#include <iostream>
# define MOD 1000000007

using namespace std;

long long big_pow(long long A, long long X) {
	if (X == 1) return A;
	if (X % 2 != 0) return (A * big_pow(A, X - 1)) % MOD;
	return (big_pow(A, X / 2) * big_pow(A, X / 2)) % MOD;
}

int main() {
	long long A, X;
	cin >> A >> X;

	cout << big_pow(A % MOD, X) << endl;

	return 0;
}