#include <iostream>
#include <vector>

using namespace std;

struct node {
	int parent;
};

node tree[200001];
bool is_visit[200001];

int main() {
	int N;
	int root_node;
	int previous_node = 0;
	int num_node = 0;
	cin >> N;

	while (N--) {
		int visit_node;
		cin >> visit_node;
		if (!is_visit[visit_node]) {
			is_visit[visit_node] = true;
			num_node++;
			if (num_node == 1) root_node = visit_node;
			tree[visit_node].parent = previous_node;
		}
		previous_node = visit_node;
	}

	cout << num_node << endl;

	for (int i = 0; i < num_node; i++) {
		if (i == root_node) {
			cout << -1 << ' ';
		}
		else {
			cout << tree[i].parent << ' ';
		}
	}
	return 0;
}