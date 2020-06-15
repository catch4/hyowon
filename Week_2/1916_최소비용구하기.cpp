#include <stdio.h>
#include <string.h>

int arr[1005][1005];
int visit[1005];
int d[1005];
int INF = 1000000000;

int nextVisit(int len) {
	
	int min = INF;
	int minIdx = 0;

	for (int i = 1; i <= len; i++) {
		if (visit[i])
			continue;
		if (d[i] < min) {
			min = d[i];
			minIdx = i;
		}
	}

	return minIdx;
}

int main() {
	int n, m;
	int start, end;
	int current=0;

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				arr[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);
		
		if(c<arr[a][b])
			arr[a][b] = c;
	}

	scanf("%d %d",&start,&end);

	for (int i = 1; i <= n; i++) {
		d[i] = arr[start][i];
	}

	visit[start]=1;

	for (int i = 0; i < n - 2; i++) {
		current = nextVisit(n);
		visit[current] = 1;

		for (int j = 1; j <= n; j++) {
			if (!visit[j]) {
				if (d[j] > d[current] + arr[current][j]) {
					d[j] = d[current] + arr[current][j];
				}
			}
		}

	}

	printf("%d", d[end]);

	return 0;
}