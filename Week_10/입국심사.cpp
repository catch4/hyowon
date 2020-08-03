#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());
	long long right = times[times.size() - 1] * n;
	long long left = 0;
	answer = right;

	while (left <= right) {
		long long sum = 0;
		long long mid = (left + right) / 2;

		for (long long i = 0; i<times.size(); i++) {
			sum += mid / times[i];
		}

		if (sum<n) {
			left = mid + 1;
		}
		else {
			if (answer>mid)
				answer = mid;
			right = mid - 1;
		}
	}

	return answer;
}