#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(10001);
vector<bool> visited(10001);
vector<int> answer;
queue<int> que;

int max_hack = 0;

int bfs(int i) {
	int num_hack = 0;
	visited[i] = true;
	num_hack++;
	que.push(i);

	while (!que.empty()) {
		int front = que.front();
		que.pop();

		for (int index = 0; index < graph[front].size(); index++) {
			int there = graph[front][index];
			if (!visited[there]) {
				num_hack++;
				visited[there] = true;
				que.push(there);
			}
		}
	}
	return num_hack;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[j] = false;
		}
		int a = bfs(i);
		if (a > max_hack) {
			answer.clear();
			answer.push_back(i);
			max_hack = a;
		}
		else if (a == max_hack) answer.push_back(i);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}

	return 0;
}