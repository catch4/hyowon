#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {

	int n, h;

	scanf("%d %d", &n, &h);

	vector <int> bottom, top;

	for (int i = 0; i < n / 2; i++) {
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		bottom.push_back(x);
		top.push_back(y);
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int result = INF;
	int cnt = 1;
	for (int i = 1; i <= h; i++)

	{
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		temp += top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin());

		if (result == temp)
			cnt++;

		else if (result > temp)
		{
			result = temp;
			cnt = 1;
		}
	}

	printf("%d %d", result, cnt);

	return 0;
}