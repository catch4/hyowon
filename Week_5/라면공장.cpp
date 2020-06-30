#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue< int, vector<int>, less<int> > pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int idx = 0;

	for (int i = 0; i<k; i++) {
		if (idx<dates.size()&&dates[idx] == i) {
			pq.push(supplies[idx++]);
		}

		if (stock == 0) {
			if (!pq.empty()) {
				stock += pq.top();
				pq.pop();
				answer++;
			}
		}

		stock--;
	}
	return answer;
}

int main() {


	printf("%d", solution(4, { 4,10,15 }, { 20,5,10 },30));

	return 0;
}