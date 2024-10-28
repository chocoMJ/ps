#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

bool is_visit[10001];
bool is_prime[10001];

void era() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	int sqrtn = 100;
	for (int i = 2; i <= sqrtn; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= 10000; j += i) { //i*i부터 순회를 시작함
				is_prime[j] = false;
			}
		}
	}
}

int replaceDigit(int digit, int number, int n) {
	string numstr = to_string(number);

	numstr[digit] = '0' + n;

	return stoi(numstr);
}

int main() {
	queue<pair<int, int>> que;
	era();

	int T;
	cin >> T;
	while (T--) {
		bool impossible = true;
		memset(is_visit, 0, sizeof(is_visit));
		while (!que.empty()) {
			que.pop();
		}
		int start, end;
		cin >> start >> end;
		que.push({ start, 0 });
		is_visit[start] = true;

		while (!que.empty()) {
			pair<int, int> top = que.front();
			que.pop();
			if (top.first == end) {
				cout << top.second << endl;
				impossible = false;
				break;
			}
			for (int i = 1; i <= 9; i++) {
				int new_num = replaceDigit(0, top.first, i);
				if (is_prime[new_num] && !is_visit[new_num]) {
					is_visit[new_num] = true;
					que.push({ new_num, top.second + 1 });
				}
			}
			for (int i = 0; i <= 9; i++) {
				int new_num = replaceDigit(1, top.first, i);
				if (is_prime[new_num] && !is_visit[new_num]) {
					is_visit[new_num] = true;
					que.push({ new_num, top.second + 1 });
				}
			}
			for (int i = 0; i <= 9; i++) {
				int new_num = replaceDigit(2, top.first, i);
				if (is_prime[new_num] && !is_visit[new_num]) {
					is_visit[new_num] = true;
					que.push({ new_num, top.second + 1 });
				}
			}
			for (int i = 1; i <= 9; i+=2) {
				int new_num = replaceDigit(3, top.first, i);
				if (is_prime[new_num] && !is_visit[new_num]) {
					is_visit[new_num] = true;
					que.push({ new_num, top.second + 1 });
				}
			}
		}
		if(impossible) cout << "Impossible" << endl;
	}
}