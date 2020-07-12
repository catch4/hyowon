#include <stdio.h>

int arr[100004];
const int INF = 987654321;

int main() {

	int n, s;
	int start = 0, end = 0;
	int sum = 0;
	int len = INF;

	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sum = arr[0];

	while (start <= end && end < n) {
		if (sum < s) {
			sum += arr[++end];
		}
		else if (sum == s) {
			len = len < (end - start + 1) ? len : (end - start + 1);
			sum += arr[++end];
		}
		else if (sum > s) {
			len = len < (end - start + 1) ? len : (end - start + 1);
			sum -= arr[start++];
		}
	}

	if (len == INF)
		printf("0");
	else
		printf("%d", len);


	return 0;
}