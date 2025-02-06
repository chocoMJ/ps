#include <iostream>
#include <queue>

void print_queue(std::queue<int> que) {
	int size = que.size();

	std::cout << '<';

	while (size != 1) {
		std::cout << que.front() << ", ";
		size--;
		que.pop();
	}

	std::cout << que.front() << '>';
}

int main() {
	int N, K;
	int count = 1;
	std::queue<int> que, answer_que;

	std::cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	while (!que.empty()) {
		if (count == K) {
			answer_que.push(que.front());
			que.pop();
			count = 1;
			continue;
		}
		que.push(que.front());
		que.pop();
		count++;
	}

	print_queue(answer_que);

	return 0;
}