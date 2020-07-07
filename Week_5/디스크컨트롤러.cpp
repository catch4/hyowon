#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair <int, int> a, const pair <int, int> b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
	}
	return false;
}

int solution(vector<vector<int>> jobs) {
	
	int answer = 0;
	int start = 0; 
	int time = 0;

	vector <pair <int, int>> disks;

	for (int i = 0; i < jobs.size(); i++)
		disks.push_back(make_pair(jobs[i][0], jobs[i][1]));

	sort(disks.begin(), disks.end(), cmp);
	
	while (!disks.empty())
	{
		for (int i = 0; i < disks.size(); i++) {
			if (disks[i].first <= start) {
				start += disks[i].second;
				time += start - disks[i].first;
				disks.erase(disks.begin()+i);
				break;
			}

			if (i == disks.size() - 1)
				start++;
		}
	}

	answer = time / jobs.size();

	return answer;
}


int main() {

	//printf("%d", solution({ {0, 3},{1, 9},{2, 6} }));
	printf("%d",solution({ { 0, 10 },{ 1, 28 },{ 2, 6 },{ 3, 4 },{ 4, 14 },}));

	return 0;
}