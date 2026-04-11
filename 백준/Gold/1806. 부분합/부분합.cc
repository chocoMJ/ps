#include <iostream>

using namespace std;

int min(int a, int b)
{
	if (a > b) return b;
	return a;
}

int main()
{
	int N, S;
	int start = 0;
	int end = 0;
	int sum;
	int answer = 987654321;
	int* arr;
	cin >> N >> S;

	arr = new int[N + 1];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] >= S) {
			cout << 1 << endl;
			return 0;
		}
	}

	sum = arr[0];
	arr[N] = 0;

	while (end < N)
	{
		if (start == end)
		{
			end++;
			sum += arr[end];
			continue;
		}

		if (sum >= S)
		{
			answer = min(answer, end - start + 1);
			sum -= arr[start];
			start++;
		}
		else
		{
			end++;
			sum += arr[end];
		}
	}

	if (answer == 987654321) cout << 0 << endl;
	else
		cout << answer << endl;

	delete[] arr;
}