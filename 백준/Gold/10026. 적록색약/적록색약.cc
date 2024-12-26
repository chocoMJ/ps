#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool bfs_normal(char** picture, bool** is_visited, int i, int j, int N) {
	queue<pair<int, int>> que;
	if (is_visited[i][j] == true) return false;

	que.push({ i, j });
	is_visited[i][j] = true;
	char color = picture[i][j];

	while (!que.empty()) {
		pair<int, int> top_loc = que.front();
		
		int x = top_loc.first;
		int y = top_loc.second;
		que.pop();

		if (x > 0 && !is_visited[x - 1][y] && picture[x - 1][y] == color) {
			is_visited[x - 1][y] = true;
			que.push({ x - 1, y });
		}
		if (x < N - 1 && !is_visited[x + 1][y] && picture[x + 1][y] == color) {
			is_visited[x + 1][y] = true;
			que.push({ x + 1, y });
		}
		if (y > 0 && !is_visited[x][y - 1] && picture[x][y - 1] == color) {
			is_visited[x][y - 1] = true;
			que.push({ x, y - 1 });
		}
		if (y < N - 1 && !is_visited[x][y + 1] && picture[x][y + 1] == color) {
			is_visited[x][y + 1] = true;
			que.push({ x, y + 1 });
		}
	}
	return true;
}

int main() {
	int N;
	int answer_normal = 0;
	int answer_special = 0;
	cin >> N;

	char** picture = new char* [N];
	bool** is_visited = new bool* [N];
	for (int i = 0; i < N; i++) {
		picture[i] = new char[N];
		is_visited[i] = new bool[N];
		for (int j = 0; j < N; j++) {
			is_visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			picture[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer_normal += bfs_normal(picture, is_visited, i, j, N);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			is_visited[i][j] = false;
			if (picture[i][j] == 'G') picture[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer_special += bfs_normal(picture, is_visited, i, j, N);
		}
	}

	cout << answer_normal << ' ' << answer_special << endl;

	for (int i = 0; i < N; i++) {
		delete[] picture[i];
		delete[] is_visited[i];
	}
	delete[] picture;
	delete[] is_visited;
	return 0;
}