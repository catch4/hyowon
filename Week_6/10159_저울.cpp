#include <stdio.h>

using namespace std;

int arr[104][104];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}

	//플로이드 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			//i에서 j로 가는길도없고, j에서 i로 가는길도 없을때 ++
			if (arr[i][j] == 0 && arr[j][i] == 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}