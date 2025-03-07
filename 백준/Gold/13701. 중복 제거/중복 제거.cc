#include <iostream>
#include <bitset>

using namespace std;

bitset<33554432> bit;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	while (cin >> num) {
		if (bit[num] == 0) {
			bit.flip(num);
			cout << num << ' ';
		}
	}
	return 0;
}