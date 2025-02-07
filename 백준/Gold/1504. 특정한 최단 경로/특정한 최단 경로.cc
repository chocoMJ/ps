#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 98765432;

vector<vector<pair<int, int>>> graph(801);
int min_dist[801][801];

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void dijk(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, compare> pq;
	min_dist[start][start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (min_dist[start][current] < distance) continue;

		for (int i = 0; i < graph[current].size(); i++) {
			int cost = distance + graph[current][i].second;
			int next = graph[current][i].first;

			if (cost < min_dist[start][next]) {
				min_dist[start][next] = cost;
				min_dist[next][start] = cost;
				pq.push({ next, cost });
			}
		}
	}
}

int main() {
	int N, E;
	int point1, point2;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			min_dist[i][j] = INF;
		}
	}

	cin >> point1 >> point2;

	dijk(1);
	dijk(point1);
	dijk(N);

	if (min_dist[1][point1] + min_dist[point2][N] > min_dist[1][point2] + min_dist[point1][N]) {
		if (min_dist[point1][point2] + min_dist[1][point2] + min_dist[point1][N] >= INF) 
			cout << -1 << endl;
		else 
			cout << min_dist[point1][point2] + min_dist[1][point2] + min_dist[point1][N] << endl;
		return 0;
	}
	if (min_dist[point1][point2] + min_dist[1][point1] + min_dist[point2][N] >= INF)
		cout << -1 << endl;
	else 
		cout << min_dist[point1][point2] + min_dist[1][point1] + min_dist[point2][N] << endl;
	return 0;
}