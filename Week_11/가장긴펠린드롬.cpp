#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
	int answer = 1;
	int len = s.length();

	while (len >= 2) {
		int start = 0;
		for (int i = 0; i <= s.length() - len; i++) {
			bool flag = false;

			if (len % 2 != 0) {
				for (int k = 0; k < len / 2; k++) {
					if (s[i + k] != s[i + len / 2 * 2 - k]) {
						flag = true;
						break;
					}
				}
				if (!flag)
					return len;
			}
			else {
				for (int k = 0; k < len / 2; k++) {
					if (s[i + k] != s[i + len / 2 * 2 - 1 - k]) {
						flag = true;
						break;
					}
				}
				if (!flag)
					return len;
			}
		}
		len--;
	}
	return answer;
}

int main() {

	//cout << solution("abcdcba")<<'\n';
	cout << solution("abacde");
	

	return 0;
}