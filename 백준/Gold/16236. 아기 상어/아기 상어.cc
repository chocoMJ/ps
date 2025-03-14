#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct compare {
	bool operator()(pair< pair<int, int>, int> a, pair < pair<int, int>, int> b) {
		if (a.second == b.second) {
			if (a.first.first == b.first.first) {
				return a.first.second > b.first.second;
			}
			else return a.first.first > b.first.first;
		}
		else return a.second > b.second;
	}
};

int N;

int map[20][20];
int visited[20][20];

bool can_Eat = true;
int size_Shark = 2;
int exp_Shark = 0;
int sum_Dist = 0;
int eatable_Fish = 0;

pair<int,int> loc_Shark;

vector<int> num_Fish(10);

void eat(pair<int,int> target_Loc, int dist) {
	can_Eat = true;
	eatable_Fish--;
	sum_Dist += dist;
	map[loc_Shark.first][loc_Shark.second] = 0;
	map[target_Loc.first][target_Loc.second] = 9;
	loc_Shark = target_Loc;

	exp_Shark += 1;
	if (exp_Shark == size_Shark) {
		size_Shark++;
		exp_Shark = 0;
		eatable_Fish += num_Fish[size_Shark - 1];
	}
	memset(visited, false, sizeof(visited));
}

void bfs() {
	int min_dist = 9876342;

	queue<pair<pair<int, int>, int>> que;
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int, int>, int>>, compare> fish_que;

	que.push({ loc_Shark, 0 });

	visited[loc_Shark.first][loc_Shark.second] = true;

	while (!que.empty()) {
		pair<int, int> cur_Loc = que.front().first;
		int x = cur_Loc.first;
		int y = cur_Loc.second;
		int dist = que.front().second;
		
		que.pop();

		if (x != 0 && !visited[x - 1][y] && min_dist >= dist + 1) {
			if (map[x - 1][y] == size_Shark || map[x-1][y] == 0) {
				visited[x - 1][y] = true;
				que.push({ { x - 1, y }, dist + 1});
			}
			else if (map[x - 1][y] < size_Shark) {
				fish_que.push({ { x - 1, y }, dist + 1 });
				min_dist = dist + 1;
			}
		}
		if (y != 0 && !visited[x][y - 1] && min_dist >= dist + 1) {
			if (map[x][y - 1] == size_Shark || map[x][y - 1] == 0) {
				visited[x][y - 1] = true;
				que.push({ { x, y - 1 }, dist + 1 });
			}
			else if (map[x][y - 1] < size_Shark && min_dist >= dist + 1) {
				fish_que.push({ { x, y - 1 }, dist + 1 });
				min_dist = dist + 1;
			}
		}
		if (y != N - 1 && !visited[x][y + 1] && min_dist >= dist + 1) {
			if (map[x][y + 1] == size_Shark || map[x][y + 1] == 0) {
				visited[x][y + 1] = true;
				que.push({ { x, y + 1 }, dist + 1 });
			}
			else if (map[x][y + 1] < size_Shark && min_dist >= dist + 1) {
				fish_que.push({ { x, y + 1 }, dist + 1 });
				min_dist = dist + 1;
			}
		}
		if (x != N - 1 && !visited[x + 1][y] && min_dist >= dist + 1) {
			if (map[x + 1][y] == size_Shark || map[x + 1][y] == 0) {
				visited[x + 1][y] = true;
				que.push({ { x + 1, y }, dist + 1 });
			}
			else if (map[x + 1][y] < size_Shark && min_dist >= dist + 1) {
				fish_que.push({ { x + 1, y }, dist + 1 });
				min_dist = dist + 1;
			}
		}
	}
	if (!fish_que.empty()) {
		eat(fish_que.top().first, fish_que.top().second);
	}
	else {
		can_Eat = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) loc_Shark = { i, j };
			else num_Fish[map[i][j]]++;
		}
	}

	eatable_Fish = num_Fish[1];

	while (can_Eat && eatable_Fish != 0) {
		bfs();
	}

	cout << sum_Dist << endl;

	return 0;
}