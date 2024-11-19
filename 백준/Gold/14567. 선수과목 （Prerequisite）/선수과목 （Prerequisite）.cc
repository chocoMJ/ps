#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(1001);
vector<int> order(1001);

void dfs(int here, int seq) {
	if (order[here] < seq) order[here] = seq;

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		if (order[there] <= seq) {
			dfs(there, seq + 1);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M; //과목의 수와 선수 조건의 수

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
	}

	for (int i = 1; i <= N; i++) {
		if (order[i] == 0) {
			dfs(i, 1);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << order[i] << ' ';
	}
	cout << endl;
	return 0;

}