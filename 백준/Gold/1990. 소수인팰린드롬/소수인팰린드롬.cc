#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> Pelindrome;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int a, b;
	cin >> a >> b;

	Pelindrome.push_back(5);
	Pelindrome.push_back(7);

	for (int digit = 2; digit <= 8; digit++) {
		int half_digit = digit / 2;

		// 홀수 자릿수 palindrome 생성
		if (digit % 2 != 0) {
			for (int i = pow(10, half_digit - 1); i < pow(10, half_digit); i++) {
				string strnum = to_string(i);
				if ((strnum[0] - '0') % 2 == 0) continue; // 첫 자리가 짝수면 건너뜀

				string rev = strnum;
				reverse(rev.begin(), rev.end());

				// 중간 자리에 0부터 9까지 넣어 모든 경우의 수 생성
				for (int mid = 0; mid <= 9; ++mid) {
					string candidate = strnum + to_string(mid) + rev;
					int num = stoi(candidate);
					if (isPrime(num)) {
						Pelindrome.push_back(num);
					}
				}
			}
		}
		// 짝수 자릿수 palindrome 생성
		else {
			for (int i = pow(10, half_digit - 1); i < pow(10, half_digit); i++) {
				string strnum = to_string(i);
				if ((strnum[0] - '0') % 2 == 0) continue; // 첫 자리가 짝수면 건너뜀

				string rev = strnum;
				reverse(rev.begin(), rev.end());

				string candidate = strnum + rev;
				int num = stoi(candidate);
				if (isPrime(num)) {
					Pelindrome.push_back(num);
				}
			}
		}
	}

	// 범위 내에서 결과 출력
	for (int i = 0; i < Pelindrome.size(); i++) {
		if (Pelindrome[i] < a) continue;
		else if (Pelindrome[i] > b) break;
		else cout << Pelindrome[i] << '\n';
	}

	cout << -1 << endl;

	return 0;
}
