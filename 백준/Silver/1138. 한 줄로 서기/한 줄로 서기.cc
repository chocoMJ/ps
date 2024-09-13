#include <iostream>
#include <vector>

using namespace std;

vector<int> line(11, -1);

int lining(int num_of_taller) {
	int pos = 0;
	while (1) {
		if (num_of_taller == 0 && line[pos] == -1) break;
		if (line[pos] == -1) {
			pos++;
			num_of_taller--;
		}
		else {
			pos++;
		}
	}
	return pos;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num_of_taller;
		cin >> num_of_taller;
		line[lining(num_of_taller)] = i;
	}
	for (int i = 0; i < N; i++) {
		cout << line[i] << " ";
	}
	cout << endl;
	return 0;
}

