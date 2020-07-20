#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;


vector<int> solution(vector<string> gems) {

	vector<int> answer = { 1, (int)gems.size() };

	set<string> jewels;

	map<string, int> ans;

	for (int i = 0; i < gems.size(); i++) {
		jewels.insert(gems[i]);
	}

	int start = 0, end = 0;
	int diff = gems.size();

	while (true) {

		if (ans.size() == jewels.size()) {
			if (diff > end - start) {
				diff = end - start;
				answer[0] = start + 1;
				answer[1] = end;
			}

			if (ans[gems[start]] == 1) {
				ans.erase(gems[start]);
				start++;
			}
			else if (ans[gems[start]] - 1 > 0) {
				ans[gems[start]]--;
				start++;
			}
		}
		else if (end == gems.size()){
			break;
		}
		else {
			ans[gems[end]]++;
			end++;
		}
	}
	return answer;
}

int main() {
	//vector <int> test = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	//vector <int> test = solution({ "AA", "AB", "AC", "AA", "AC" });
	//vector <int> test = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
	vector <int> test = solution({ "XYZ", "XYZ", "XYZ" });

	for (int i = 0; i < test.size(); i++) {
		printf("%d ", test[i]);
	}

	return 0;
}