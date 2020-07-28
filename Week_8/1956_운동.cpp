#include <stdio.h>

int arr[402][402];
const int INF = 987654321;
int min = INF;

int main() {

	int v, e;

	scanf("%d %d", &v, &e);

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		if (z < arr[x][y])
			arr[x][y] = z;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (arr[i][i] >= INF)
			continue;

		min = arr[i][i] < min ? arr[i][i] : min;
	}

	if (min >= INF)
		printf("-1");
	else
		printf("%d", min);

	return 0;
}