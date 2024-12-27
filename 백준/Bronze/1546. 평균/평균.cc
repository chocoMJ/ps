#include <iostream>

using namespace std;

int main() {
	int N;
	float max_score = 0;
	float sum_score = 0;
	cin >> N;
	float* score = new float[N];

	for (int i = 0; i < N; i++) {
		cin >> score[i];
		if (max_score < score[i]) max_score = score[i];
	}

	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max_score * 100;
		sum_score += score[i];
	}

	cout << sum_score / N << endl;

	delete[] score;
}