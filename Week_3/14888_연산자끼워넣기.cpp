#include <stdio.h>
#include <vector>

using namespace std;

int arr[12];
int op[12];
int idx;
bool visit[12];
vector <int> v;
int n;
int minValue = 1000000001, maxValue = -1000000001;


// 0 : plus
// 1 : minus
// 2 : mul
// 3 : div

void dfs(int depth) {

	if (depth == idx) {
		int sum = arr[0];

		for (int i = 1; i < n; i++) {
			switch (v[i-1])
			{
			case 0:
				sum += arr[i];
				break;
			case 1:
				sum -= arr[i];
				break;
			case 2:
				sum *= arr[i];
				break;
			case 3:
				sum /= arr[i];
				break;
			}
		}
		minValue = minValue > sum ? sum : minValue;
		maxValue = maxValue < sum ? sum : maxValue;

		return;
	}

	for (int i = 0; i < idx; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			v.push_back(op[i]);
			dfs(depth + 1);
			v.pop_back();
			visit[i] = false;
		}
	} 
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++) {
		int x;

		scanf("%d", &x);

		for (int j = 0; j < x; j++) {
			op[idx++] = i;
		}
	}

	dfs(0);

	printf("%d\n%d", maxValue, minValue);

	return 0;
}