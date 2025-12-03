#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int stat_point[101][101];
vector<bool> isVisited;
int team_people;
int N;
int answer = 99999999;

void Calculate_point();

void Combination(int depth, int start);


int main()
{
	cin >> N;

	team_people = N / 2;
	isVisited.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> stat_point[i][j];
		}
	}

	Combination(0, 1);

	cout << answer << endl;
}

void Calculate_point()
{
	int point_a = 0;
	int point_b = 0;


	for (int i = 1; i <= N; i++)
	{
		if (isVisited[i])
		{
			for (int j = 1; j <= N; j++)
			{
				if (isVisited[j]) point_a += stat_point[i][j];
			}
		}

		else
		{
			for (int j = 1; j <= N; j++)
			{
				if (!isVisited[j]) point_b += stat_point[i][j];
			}
		}
	}
	if (answer >= abs(point_a - point_b)) answer = abs(point_a - point_b);
}

void Combination(int depth, int start)
{
	if (depth == team_people)
	{
		Calculate_point();
		return;
	}

	for (int i = start; i <= N; i++)
	{
		isVisited[i] = true;
		Combination(depth + 1, i + 1);
		isVisited[i] = false;
	}
}
