#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 99999;
int arr[40004];
vector <int> vt;

int main() {

	int n;
	int max = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	vt.push_back(-INF);
	for (int i = 0; i < n; i++) {
		if (vt.back() < arr[i]) {
			vt.push_back(arr[i]);
			max++;
		}
		else {
			auto it = lower_bound(vt.begin(), vt.end(), arr[i]);
			*it = arr[i];
		}
	}

	printf("%d", max);

	return 0;
}