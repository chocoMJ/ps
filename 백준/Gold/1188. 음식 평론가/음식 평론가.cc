#include <iostream>

using namespace std;

int cal_cutting(int N, int M) {
	int sum_cutting = 0;
	if (N == 0) return 0;
	if (M % N == 0) return sum_cutting + N * ((M / N) - 1);
	if (N > M) return sum_cutting + cal_cutting(N % M, M);



	sum_cutting += N * (M / N);
	return sum_cutting + cal_cutting(N, M - (N * (M / N)));
}

int main() {
	int N, M;
	cin >> N >> M;
	
	cout << cal_cutting(N, M) << endl;
	return 0;
}