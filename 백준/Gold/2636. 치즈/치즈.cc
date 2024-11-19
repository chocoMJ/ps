#include <iostream>
#include <queue>

using namespace std;

int N, M;
int day = 0;
int map[100][100];
int visited[100][100];
int c[100][100];

int melt_cheeze(); //c배열에서 값이 1인 치즈는, map에서 0으로 바꿔준다. 그리고 녹인 치즈 개수 return한다.
void check_air_cheeze(); //공기와 맞닿는 부분을 c값을 1로 한다.
void init();

int main() {
	cin >> N >> M;
	int answer1 = 0;
	int answer2 = 0;
	int count = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		init();
		check_air_cheeze();
		count = melt_cheeze();
		if (count != 0) {
			answer2 = count;
			answer1++;
		}
		else break;
	}

	cout << answer1 << endl << answer2 << endl;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void check_air_cheeze() {
	queue<pair<int,int>> que;
	que.push({ 0,0 });
	visited[0][0] = true;

	while (!que.empty()) {
		auto front_row = que.front().first;
		auto front_col = que.front().second;
		que.pop();

		if (front_row > 0) {
			if (!visited[front_row - 1][front_col]) {
				visited[front_row - 1][front_col] = true;
				if (map[front_row - 1][front_col] == 0) que.push({ front_row - 1, front_col });
				else c[front_row - 1][front_col] = 1;
			}
		}

		if (front_row < N - 1) {
			if (!visited[front_row + 1][front_col]) {
				visited[front_row + 1][front_col] = true;
				if (map[front_row + 1][front_col] == 0) que.push({ front_row + 1, front_col });
				else c[front_row + 1][front_col] = 1;
			}
		}

		if (front_col > 0) {
			if (!visited[front_row][front_col - 1]) {
				visited[front_row][front_col - 1] = true;
				if (map[front_row][front_col - 1] == 0) que.push({ front_row, front_col - 1 });
				else c[front_row][front_col - 1] = 1;
			}
		}

		if (front_col < M - 1) {
			if (!visited[front_row][front_col + 1]) {
				visited[front_row][front_col + 1] = true;
				if (map[front_row][front_col + 1] == 0) que.push({ front_row, front_col + 1 });
				else c[front_row][front_col + 1] = 1;
			}
		}
	}

}

int melt_cheeze() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (c[i][j] == 1) {
				map[i][j] = 0;
				c[i][j] = 0;
				count++;
			}
		}
	}
	return count;
}