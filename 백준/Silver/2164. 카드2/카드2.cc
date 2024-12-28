#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> que;
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	for(int i = 1; i <= N; i++) {
		que.push(i);
	}

	while (1) {
		que.pop();

		if (que.size() <= 1) break;
		que.push(que.front());
		que.pop();
	}
	cout << que.front() << endl;

}