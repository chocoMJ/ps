#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	int height = 0;
	int day = 0;
	int A_B;
	int goal;

	cin >> A >> B >> V;

	A_B = A - B;
	goal = V - A;

	if (goal % A_B == 0) {
		cout << goal / A_B + 1 << endl;
	}
	else {
		cout << goal / A_B + 2 << endl;
	}

	return 0;
}