#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph(100001);

bool visited[100001];

int max_point = 0;
long long max_distance = 0;

void dfs(int start, long long dist, long long& max_distance) {
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		int point = graph[start][i].first;
		if (!visited[point]) {
			dfs(point, dist + graph[start][i].second, max_distance);
		}

		if (max_distance < dist) {
			max_distance = dist;
			max_point = start;
		}
	}
}

int main() {
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int start;
		cin >> start;

		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;
			int b;
			cin >> b;
			graph[start].push_back({ a,b });
		}
	}

	dfs(1, 0, max_distance);

	//방문처리 초기화
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	max_distance = 0;

	dfs(max_point, 0, max_distance);

	cout << max_distance << endl;

	return 0;
}