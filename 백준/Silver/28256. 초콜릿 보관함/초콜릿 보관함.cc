#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chocolate[8];
vector<int> checknum;
vector<int> real_num;

void input_checknum(int n) {
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		checknum.push_back(a);
	}
}

int input_chocolate() {
	int x = -1;
	string temp;
	cin >> temp;

	for (int i = 0; i < 3; i++) {
		if (temp[i] == 'O') chocolate[i] = true;
		else {
			chocolate[i] = false;
			x = i;
		}
	}

	cin >> temp;
	if (temp[0] == 'O') chocolate[7] = true;
	else {
		chocolate[7] = false;
		x = 7;
	}
	if (temp[2] == 'O') chocolate[3] = true;
	else {
		chocolate[3] = false;
		x = 3;
	}

	cin >> temp;
	for (int i = 0; i < 3; i++) {
		if (temp[i] == 'O') chocolate[6 - i] = true;
		else {
			chocolate[6 - i] = false;
			x = 6 - i;
		}
	}
	return x;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int sum = 0;
		int x = input_chocolate();
		int n;
		cin >> n;
		input_checknum(n);

		if (x == -1) {
			if (checknum.size() == 1 && checknum[0] == 8) {
				cout << 1 << endl;
			}
			else cout << 0 << endl;

			checknum.clear();
			real_num.clear();

			continue;
		}

		for (int i = 0; i <= 8; i++) {
			if (chocolate[(i + x) % 8] == false) {
				if (sum != 0) real_num.push_back(sum);
				sum = 0;
			}
			else {
				sum++;
			}
		}
		sort(real_num.begin(), real_num.end());
		if (real_num == checknum) cout << 1 << endl;
		else cout << 0 << endl;

		checknum.clear();
		real_num.clear();
	}
}