#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	while (1) {
		int length[3];
		int a, b, c;
		cin >> length[0] >> length[1] >> length[2];

		sort(length, length + 3);

		if (length[2] == 0) break;

		if (length[0] * length[0] + length[1] * length[1] == length[2] * length[2]) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}