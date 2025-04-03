#include <iostream>

using namespace std;

int INF = 987654321;
int item[101];
int dist[101][101];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int N, M, R;

	int answer = 0;

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++) {
		cin >> item[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < R; i++) {
		int a, b, r;
		cin >> a >> b >> r;

		dist[a][b] = r;
		dist[b][a] = r;
	}

	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int start = 1; start <= N; start++) {
		int num_item = 0;
		for (int end = 1; end <= N; end++) {
			if (dist[start][end] <= M) {
				num_item += item[end];
			}
		}
		if (answer < num_item) answer = num_item;
	}

	cout << answer << endl;

	return 0;
}

