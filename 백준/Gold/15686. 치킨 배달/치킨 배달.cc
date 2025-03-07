#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int map[50][50];

int totalRemoveChicken = 0;
int totalBuildChicken = 0;
int answer = 987654321;
vector<pair<int, int>> location_Chicken;
vector<pair<int, int>> location_house;
vector<bool> is_build;

int cal_ChickenDist() {
	int answer_dist = 0;
	for (int i = 0; i < location_house.size(); i++) {
		int house_x = location_house[i].first;
		int house_y = location_house[i].second;
		int min_dist = 987654321;

		for (int j = 0; j < location_Chicken.size(); j++) {
			int chicken_x = location_Chicken[j].first;
			int chicken_y = location_Chicken[j].second;
			if (is_build[j] == false) continue;
			if (min_dist > abs(house_x - chicken_x) + abs(house_y - chicken_y)) {
				min_dist = abs(house_x - chicken_x) + abs(house_y - chicken_y);
			}
		}
		answer_dist += min_dist;
	}
	return answer_dist;
}

void remove_Chicken(int index, int currentRemoveChicken) {
	if (currentRemoveChicken == totalRemoveChicken) {
		if (answer > cal_ChickenDist()) {
			answer = cal_ChickenDist();
		}
	}
	else {
		for (int i = index; i < location_Chicken.size(); i++) {
			if (is_build[i] == true) {
				is_build[i] = false;
				remove_Chicken(i + 1, currentRemoveChicken + 1);
				is_build[i] = true;
			}
		}
	}

}

void build_Chicken(int index, int currentBuildChicken) {
	if (currentBuildChicken == totalBuildChicken) {
		if (answer > cal_ChickenDist()) {
			answer = cal_ChickenDist();
		}
	}
	else {
		for (int i = index; i < location_Chicken.size(); i++) {
			if (is_build[i] == false) {
				is_build[i] = true;
				build_Chicken(i + 1, currentBuildChicken + 1);
				is_build[i] = false;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				location_Chicken.push_back({ i, j });
				is_build.push_back(false);
			}
			else if (map[i][j] == 1)
				location_house.push_back({ i, j });
		}
	}

	totalBuildChicken = M;
	totalRemoveChicken = location_Chicken.size() - M;

	if (location_Chicken.size() / 2 >= M) {
		for (int i = 0; i < is_build.size(); i++) {
			is_build[i] = false;
		}
		build_Chicken(0, 0);
	}
	else {
		for (int i = 0; i < is_build.size(); i++) {
			is_build[i] = true;
		}
		remove_Chicken(0, 0);
	}

	cout << answer << endl;

	return 0;
}