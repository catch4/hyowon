#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

stack<char> s;

int solve(char *str);
int checkLoop(char c1, char c2, int value);

int solve(char *str) {

	int check = 0;
	int result = 0;

	for (int i = 0; i < strlen(str); i++) {

		//checkLoop를 돌렸을때 -1이면 잘못된 괄호
		if (check == -1) {
			printf("0");
			return 0;
		}

		//여는 괄호면 스택에 푸시
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else {
		//닫는 괄호

			//스택이 비어있으면 잘못된 괄호
			if (s.empty()) {
				printf("0");
				return 0;
			}
			//닫는괄호가 ) 면
			if (str[i] == ')') {
				if (s.top() == '(') {
					//스택 top이 ( 면 팝하고 2를 푸시
					s.pop();
					s.push('2');
				}
				else {
					//다른 문자이면 checkLoop
					check = checkLoop('[', '(', 2);
				}
			}
			//닫는괄호가 ] 면
			else if (str[i] == ']') {
				if (s.top() == '[') {
					//스택 top이 [ 면 팝하고 3를 푸시
					s.pop();
					s.push('3');
				}
				else {
					//다른 문자이면 checkLoop
					check = checkLoop('(', '[', 3);
				}
			}
		}
	}


	//for문이 끝나면 스택에 숫자만 남아있다
	//남아있는 숫자를 모두 더하면 답이 나옴
	while (!s.empty())
	{
		//괄호가 있을경우 잘못된 입력
		if (s.top() == '(' || s.top() == ')' || s.top() == '[' || s.top() == ']') {
			printf("0");
			return 0;
		}
		//숫자를 더하고 팝
		result += s.top() - '0';
		s.pop();
	}

	//결과출력
	printf("%d", result);

	return 0;
}

int checkLoop(char c1,char c2,int value) {

	int result = 0;

	while (!s.empty())
	{
		//닫는괄호가 ) 면 checkLoop('[', '(', 2);
		//닫는괄호가 ] 면 checkLoop('(', '[', 3)

		
		if (s.top() == c1) {  // [) , (] 이런경우
			return -1;
		}
		else if (s.top() == c2) { 
			//중첩된괄호인경우 result에 곱하기후 스택에 푸시처리
			s.pop();
			result *= value;
			s.push(result+'0');
			break;
		}
		else {
			//숫자인경우 result에 더하기후 팝
			result += s.top() - '0';
			s.pop();
		}
	}

	return result;
}

int main() {

	char str[35] = "";

	scanf("%s", str);

	solve(str);

	return 0;
}
