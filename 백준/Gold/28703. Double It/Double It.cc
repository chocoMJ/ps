#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

long long SetPQ(int N); //pq 입력받기

int main() {
	bool is_start = false;
	int N;
	cin >> N;
	int ans = 0;

	long long max = SetPQ(N);

	ans = max - pq.top();

	while (N) {
		if (is_start) N--;
		if (pq.top() * 2 > max) {
			max = pq.top() * 2;
			is_start = true;
		}
		pq.push(pq.top() * 2);
		pq.pop();

		if (ans > max - pq.top()) {
			ans = max - pq.top();
		}
	}

	cout << ans << endl;
	return 0;
}

long long SetPQ(int N) {
	long long max = 0;
	while (N--) {
		int a;
		cin >> a;

		if (max < a) max = a;

		pq.push(a);

	}
	return max;
}