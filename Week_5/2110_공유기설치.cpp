#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[200010];

int main() {

	int n, c;
	int answer=0;

	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	sort(arr, arr + n);

	int left = 1;
	int right = arr[n-1]- arr[0];

	while (left<=right)
	{
		int mid = (left + right) / 2;
		int cnt = 1;
		int start = arr[0];

		for (int i = 1; i < n; i++) {
			if (arr[i] - start >= mid) {
				start = arr[i];
				cnt++;
			}
		}

		if (cnt >= c) {
			answer = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	
	}

	printf("%d", answer);

	return 0;
}