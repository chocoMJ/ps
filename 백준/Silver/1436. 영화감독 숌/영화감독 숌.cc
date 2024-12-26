#include <iostream>
#include <string>

using namespace std;

bool is_six(string str) {
	int len = str.length();

	for (int i = 0; i < len - 2; i++) {
		if (str[i] == str[i + 1]) {
			if (str[i] == str[i + 2]) {
				if (str[i] == '6') {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int answer = 0;

	int index = 666;
	while (1) {
		if (is_six(to_string(index))) {
			answer++;
		}

		if (answer == n) {
			cout << index << endl;
			return 0;
		}
		index++;
	}
}