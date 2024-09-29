#include <iostream>
#include <queue>

using namespace std;

queue<int> homework[200001];
priority_queue<int> pq;
int ans = 0;

void Set_Homework(int N) {
	while (N--) {
		int deadline, reward;
		cin >> deadline >> reward;

		homework[deadline].push(reward);
	}
}

void PushToPQ(int deadline) {
	while (!homework[deadline].empty()) {
		pq.push(homework[deadline].front());
		homework[deadline].pop();
	}
}

void DoWork() {
	if (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
}

int main() {
	int N;
	cin >> N;

	Set_Homework(N);
	
	for (int deadline = 200000; deadline >= 1; deadline--) {
		PushToPQ(deadline);
		DoWork();
	}

	cout << ans << endl;
}