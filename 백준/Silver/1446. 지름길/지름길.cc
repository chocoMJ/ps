#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 987654321;

vector<vector<pair<int, int>>> graph(10001); //순서는 가중치, 정점
vector<int> min_distance(10001, INF);

void dijkstra(int start) {
	min_distance[start] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;
	
		pq.pop();

		if (min_distance[current] < distance) continue; 

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].second;
			int next_distance = distance + graph[current][i].first;

			if (next_distance < min_distance[next]) {
				min_distance[next] = next_distance;
				pq.push({ -next_distance, next });
			}
		}
	}
}


int main() {
	int N, D;
	cin >> N >> D; //지름길 개수와 고속도로의 길이

	for (int i = 0; i < D; i++) { //모든 거리를 하나의 노드로 취급
		graph[i].push_back({ 1, i + 1 });
	}
	
	for (int i = 0; i < N; i++) { //입력
		int start, end, weight;
		cin >> start >> end >> weight;

		graph[start].push_back({ weight, end });
	}

	dijkstra(0);

	cout << min_distance[D] << endl;
}