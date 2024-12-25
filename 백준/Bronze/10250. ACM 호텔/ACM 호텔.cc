#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int H, W, N;
		cin >> H >> W >> N;

		int height = N % H;
		if (height == 0) height = H;
		height *= 100;

		int width = N / H + 1;
		if (N % H == 0) width -= 1;

		cout << height + width << endl;
	}
}