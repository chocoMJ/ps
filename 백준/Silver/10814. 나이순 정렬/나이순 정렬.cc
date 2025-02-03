#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

struct member_system {
	int age;
	string name;
	int num;
};

member_system member[100000];

bool compare(member_system i, member_system j) {
	if (i.age == j.age) {
		return i.num < j.num;
	}
	return i.age < j.age;
}

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> member[i].age >> member[i].name;
		member[i].num = i;
	}

	sort(member, member + N, compare);

	for (int i = 0; i < N; i++) {
		cout << member[i].age << ' ' << member[i].name << endl;
	}

	return 0;
}