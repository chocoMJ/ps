#include <iostream>

using namespace std;

int T[1500001];
int P[1500001];
int sum[1500003];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int max_pay(int day, int N) {
	if (day + T[day] - 1 > N) {
		return sum[day + 1];
	}
	return max(P[day] + sum[day + T[day]], sum[day + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	if (T[N] == 1) sum[N] = P[N];
	else sum[N] = 0;

	for (int i = N - 1; i >= 1; i--) {
		sum[i] = max_pay(i, N);
	}
	cout << sum[1] << endl;

	return 0;
}