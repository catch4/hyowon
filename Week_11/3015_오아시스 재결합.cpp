#include <stdio.h>
#include <stack>

using namespace std;

int main() {

	int n;
	long long cnt = 0;
	stack<pair<int, int>> s;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d", &h);

		pair<int, int> p = make_pair(h, 1);

		while (!s.empty()) {
			if (s.top().first <= h) {
				cnt += (long long)s.top().second;
				if (s.top().first == h)
					p.second += s.top().second;
				s.pop();
			}
			else {
				if (!s.empty())
					cnt += 1LL;
				break;
			}
		}
		s.push(p);
	}

	printf("%lld", cnt);

	return 0;
}