#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	int gap = 6;
	int size = 1;

	cin >> N;

	while (1) {
		vec.push_back(vec[size] + gap);
		if (vec[size] + gap > 1000000000) break;
		gap += 6;
		size++;

	}

	for (int i = 0; i < vec.size(); i++) {
		
		if (N < vec[i]) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}