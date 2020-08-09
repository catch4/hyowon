#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>>ans;

string get_ans(int sec) {
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (sec > ans[i].second)
			return ans[i].first;
	}
	return "";
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string cmd,c;
		int s;

		cin >> cmd >> c >> s;

		if (cmd == "type")
		{
			string temp;

			if (ans.size())
				temp = ans.back().first + c;
			else 
				temp = c;
			
			ans.push_back({ temp,s });
		}
		else
		{
			string temp;
			temp = get_ans(s - atoi(c.c_str()));
			ans.push_back({ temp,s });
		}
	}
	cout << ans.back().first;


	return 0;
}