#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long long n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		long long N;
		cin >> N;

		while (1) {
			if (isPrime(N)) {
				cout << N << endl;
				break;
			}
			N++;
		}
	}

	return 0;
}