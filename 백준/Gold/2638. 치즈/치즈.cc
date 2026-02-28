#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;

int N, M;
int answer = 0;
int Map[101][101];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isValid(int x, int y)
{
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= N) return false;
	if (y >= M) return false;

	return true;
}

void bfs_findKillerAir()
{
	queue<pair<int, int>> que;
	que.push({ 0,0 });
	
	Map[0][0] = 2;

	while (!que.empty())
	{
		pair<int, int> current = que.front();
		int currentX = current.first;
		int currentY = current.second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int x = currentX + dx[i];
			int y = currentY + dy[i];

			if (isValid(x, y) && (Map[x][y] == 0))
			{
				que.push({ x, y });
				Map[x][y] = 2;
			}
		}
	}
}

bool IsCheeseKilled(int i, int j)
{
	int count = 0;

	int currentX = i;
	int currentY = j;

	for (int i = 0; i < 4; i++)
	{
		int x = currentX + dx[i];
		int y = currentY + dy[i];

		if (Map[x][y] == 2) count++;
	}

	if (count >= 2) return true;
	return false;
}

bool FindDeadCheese()
{
	int flag = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 1)
			{
				flag = false;
				{
					if(IsCheeseKilled(i, j))
						Map[i][j] = 0;
				}
			}
		}
	}

	return flag;
}

void clearMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 2) Map[i][j] = 0;
		}
	}
}

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Map[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	cin >> N >> M;

	//입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			Map[i][j] = a;
		}
	}

	while (1)
	{
		bool isEnd = false;
		bfs_findKillerAir();
		isEnd = FindDeadCheese();
		if (isEnd) break;
		clearMap();
		answer++;
	}

	cout << answer<< endl;
}

