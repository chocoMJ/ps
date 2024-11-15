#include <iostream>

using namespace std;

int INF = 987654321;
int graph[101][101];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 101; i++) { //초기화
		for (int j = 0; j < 101; j++) {
			graph[i][j] = INF;
			if (i == j) graph[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int start, end, weight;

		cin >> start >> end >> weight;

		if(graph[start][end] > weight) graph[start][end] = weight;
	}

	for (int k = 1; k <= n; k++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				graph[start][end] = min(graph[start][end], graph[start][k] + graph[k][end]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF) cout << 0 << ' ';
			else cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}