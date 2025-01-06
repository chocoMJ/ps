#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vec(100001);
int parent_of_node[100001];
bool is_visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> que;
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end;
		cin >> start >> end;

		vec[start].push_back(end);
		vec[end].push_back(start);
	}

	que.push(1);
	is_visited[1] = true;

	while (!que.empty()) {
		int current = que.front();
		que.pop();

		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i];
			if (is_visited[next] == true) continue;

			que.push(next);
			is_visited[next] = true;
			parent_of_node[next] = current;
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent_of_node[i] << '\n';
	}

	return 0;
}