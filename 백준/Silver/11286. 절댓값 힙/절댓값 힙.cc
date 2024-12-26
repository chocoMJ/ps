#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct comp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, comp> pq;

int main() {
	int N;
	cin >> N;

	while (N--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.size() == 0) cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(a);
		}
	}

	return 0;
}