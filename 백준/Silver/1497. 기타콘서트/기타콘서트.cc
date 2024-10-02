#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	pair<long long, int> p = { 0,100 }; //연주할 수 있는 최대 곡 개수와 그때 필요한 기타 수

	cin >> N >> M;

	vector<long long>guitar(N);

	for (int i = 0; i < N; i++) {
		string name, is_play;
		cin >> name >> is_play;
		long long is_play_i = 0;

		for (int j = 0; j < M; j++) {
			if (is_play[j] == 'Y') is_play_i += ((long long)1 << (M - j - 1));
		}
		guitar[i] = is_play_i;
	}

	for (int choose_guitar = 1; choose_guitar < (1 << N); choose_guitar++) {
		int num_guitar = 0;
		long long played = 0;
		int num_play = 0;
		for (int i = 0; i < N; i++) {
			if (choose_guitar & (1 << i)) {
				num_guitar++;
				played = played | guitar[i];
			}
		}

		for (int i = 0; i < M; i++) {
			if (played & ((long long)1 << i)) num_play++;
		}

		if (num_play > p.first) {
			p = { num_play, num_guitar };
		}

		else if (num_play == p.first) {
			if (num_guitar < p.second) {
				p = { num_play, num_guitar };
			}
		}
	}

	if (p.first == 0) cout << -1 << endl;
	else cout << p.second << endl;

	return 0;
}