#include <stdio.h>

int arr[12][12];
bool check[12];
int n, result;

void dfs(int depth, int sum) {
	if (depth == 11) {
		result = result > sum ? result : sum;
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (!check[i] && arr[depth][i]) {
			check[i] = true;
			dfs(depth + 1, sum + arr[depth][i]);
			check[i] = false;
		}
	}
}

int main() {

	scanf("%d", &n);
	
	while (n--) {
		result = 0;
		for (int i = 0; i < 11; i++) {
			check[i]=false;
			for (int j = 0; j < 11; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dfs(0, 0);
		printf("%d\n", result);
	}

	return 0;
}