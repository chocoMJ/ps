#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	set<int> s;
	int N, M;
	cin >> N;

	while (N--)
	{
		int card;
		cin >> card;
		s.insert(card);
	}

	cin >> M;

	while (M--)
	{
		int find_card;
		cin >> find_card;
		if (s.find(find_card) != s.end())
			cout << 1 << ' ';
		else cout << 0 << ' ';
	}
}