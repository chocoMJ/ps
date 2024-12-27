#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct doubleque {
	priority_queue<int, vector<int>, less<int>> pq_max;
	priority_queue<int, vector<int>, greater<int>> pq_min;
	map<int, int> mapset;
	int count = 0;

	void input_mode(int i) {
		count++;
		pq_max.push(i);
		pq_min.push(i);

		if (mapset.find(i) == mapset.end()) {
			mapset.insert({ i, 1 });
		}
		else {
			mapset[i] += 1;
		}
	}

	void delete_mode(int i) {
		if (i == -1) {
			while (1) {
				if (pq_min.empty()) return;
				int value = pq_min.top();
				pq_min.pop();
				if (mapset.find(value) == mapset.end()) {
					continue;
				}
				mapset[value] -= 1;
				if (mapset[value] == 0) mapset.erase(value);
				count--;
				break;
			}
		}
		if (i == 1) {
			while (1) {
				if (pq_max.empty()) return;
				int value = pq_max.top();
				pq_max.pop();
				if (mapset.find(value) == mapset.end()) {
					continue;
				}
				count--;
				mapset[value] -= 1;
				if (mapset[value] == 0) mapset.erase(value);
				break;
			}
		}
	}

	void print_answer() {
		while (1) {
			if (pq_max.empty()) {
				cout << "EMPTY" << endl;
				return;
			}
			int value = pq_max.top();
			pq_max.pop();
			if (mapset.find(value) == mapset.end()) {
				continue;
			}
			cout << value << ' ';
			break;
		}

		while (1) {
			if (pq_min.empty()) {
				cout << "EMPTY" << endl;
				return;
			}
			int value = pq_min.top();
			pq_min.pop();
			if (mapset.find(value) == mapset.end()) {
				continue;
			}
			cout << value << endl;
			break;
		}
	}

	void test() {
		char c;
		int i;
		cin >> c >> i;

		if (c == 'I') {
			input_mode(i);
		}
		else {
			delete_mode(i);
		}
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		doubleque dq;

		while (n--) {
			dq.test();
		}
		if (dq.count <= 0) cout << "EMPTY" << endl;
		else dq.print_answer();
	}
}