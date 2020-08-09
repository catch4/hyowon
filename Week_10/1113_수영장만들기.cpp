#include <stdio.h>
#include <queue>

using namespace std;

int arr[52][52];
int n, m;
int result;

struct coor
{
	int x;
	int y;
};

queue <coor> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int h) {
	arr[0][0] = h;
	q.push({ 0,0 });

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && arr[nx][ny] < h) {
				arr[nx][ny] = h;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	int max = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}

	for (int i = 1; i <= max; i++) {
		bfs(i);

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (arr[j][k] < i) {
					result++;
					arr[j][k]++;
				}
			}
		}
	}
	
	printf("%d", result);

	return 0;
}

