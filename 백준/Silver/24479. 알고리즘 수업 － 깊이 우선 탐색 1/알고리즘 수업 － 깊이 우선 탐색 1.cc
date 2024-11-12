#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(100001);
bool visited[100001];
vector<int> answer(100001);
int cnt = 0;

void dfs(int r) {
	visited[r] = true;
	cnt++;

	answer[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		if (visited[graph[r][i]] != true) {
			visited[graph[r][i]] = true;
			dfs(graph[r][i]);
		}
	}
}

int main() {
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << answer[i] << '\n';

	return 0;
}