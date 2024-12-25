#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int result = 0;
		string quiz_result;
		cin >> quiz_result;

		int* arr = new int[quiz_result.length()];

		if (quiz_result[0] == 'O') {
			arr[0] = 1;
			result += 1;
		}
		else arr[0] = 0;

		for (int i = 1; i < quiz_result.length(); i++) {
			if (quiz_result[i] == 'O') {
				arr[i] = arr[i - 1] + 1;
				result += arr[i];
			}
			else arr[i] = 0;
		}

		cout << result << endl;
	}
}