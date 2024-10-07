#include <iostream>
#include <math.h>
#include <vector>

#define MAX_N 5000000

using namespace std;

int minFactor[MAX_N + 1];

void find_minFactor() {
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= MAX_N; i++) {
		minFactor[i] = i;
	}
	int sqrtn = int(sqrt(MAX_N));

	for (int i = 2; i <= sqrtn; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= MAX_N; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}

vector<int> factor(int N) {
	vector<int> ret;

	while (N > 1) {
		ret.push_back(minFactor[N]);
		N /= minFactor[N];
	}

	return ret;
}

void print_vec(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;
	
	find_minFactor();

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;

		vector<int> ret = factor(k);

		print_vec(ret);
	}

	return 0;
}