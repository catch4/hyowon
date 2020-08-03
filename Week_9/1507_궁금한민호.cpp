#include <stdio.h>

int dist[22][22];
int a[22][22];
bool c[22][22];
int result;

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int d;

			scanf("%d", &d);

			dist[i][j] = d;
			a[i][j] = d;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || j == k) {
					continue;
				}

				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					printf("-1");
					return 0;
				}

				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					a[i][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != 0 && !c[i][j]) {
				result += a[i][j];

				c[i][j] = true;
				c[j][i] = true;
			}
		}
	}

	printf("%d", result);

	return 0;
}