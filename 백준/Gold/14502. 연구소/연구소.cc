#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void choose_wall(const int& N, const int& M, vector<vector<int>>& map, vector<vector<bool>>& visited, int depth, int index_i, const vector<pair<int, int>>& locationVirus, int& answer) {
	if (depth == 3) {
		int num_safe = 0;
		for (int i = 0; i < locationVirus.size(); i++) {
			queue<pair<int, int>> que;
			pair<int, int> cur_loc = locationVirus[i];
			int x = cur_loc.first;
			int y = cur_loc.second;

			if (visited[x][y]) continue;

			visited[x][y] = true;
			que.push({ x,y });

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;

				que.pop();

				if (x > 0 && visited[x - 1][y] == false && map[x - 1][y] != 1) {
					visited[x - 1][y] = true;
					que.push({ x - 1, y });
				}
				if (x < N - 1 && visited[x + 1][y] == false && map[x + 1][y] != 1) {
					visited[x + 1][y] = true;
					que.push({ x + 1, y });
				}
				if (y > 0 && visited[x][y - 1] == false && map[x][y - 1] != 1) {
					visited[x][y - 1] = true;
					que.push({ x, y - 1 });
				}
				if (y < M - 1 && visited[x][y + 1] == false && map[x][y + 1] != 1) {
					visited[x][y + 1] = true;
					que.push({ x, y + 1 });
				}
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[j][k] == 0 && !visited[j][k]) {
					num_safe++;
				}
			}
		}

		if (num_safe > answer) {
			answer = num_safe;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
	}

	else {
		for (int i = 0; i <= N * M - 1; i++) {
			if (map[i / M][i % M] == 0) {
				map[i / M][i % M] = 1;
				choose_wall(N, M, map, visited, depth + 1, i + 1, locationVirus, answer);
				map[i / M][i % M] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> locationVirus;
	vector<vector<bool>> visited;
	vector<vector<int>> map;
	int N, M;
	int answer = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> vec;
		vector<bool> temp;
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			vec.push_back(a);
			temp.push_back(false);
			if (a == 2) locationVirus.push_back({ i,j });
		}
		map.push_back(vec);
		visited.push_back(temp);
	}

	choose_wall(N, M, map, visited, 0, 0, locationVirus, answer);

	cout << answer << endl;

	return 0;
}