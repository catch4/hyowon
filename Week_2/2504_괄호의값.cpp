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

		//checkLoop�� �������� -1�̸� �߸��� ��ȣ
		if (check == -1) {
			printf("0");
			return 0;
		}

		//���� ��ȣ�� ���ÿ� Ǫ��
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else {
		//�ݴ� ��ȣ

			//������ ��������� �߸��� ��ȣ
			if (s.empty()) {
				printf("0");
				return 0;
			}
			//�ݴ°�ȣ�� ) ��
			if (str[i] == ')') {
				if (s.top() == '(') {
					//���� top�� ( �� ���ϰ� 2�� Ǫ��
					s.pop();
					s.push('2');
				}
				else {
					//�ٸ� �����̸� checkLoop
					check = checkLoop('[', '(', 2);
				}
			}
			//�ݴ°�ȣ�� ] ��
			else if (str[i] == ']') {
				if (s.top() == '[') {
					//���� top�� [ �� ���ϰ� 3�� Ǫ��
					s.pop();
					s.push('3');
				}
				else {
					//�ٸ� �����̸� checkLoop
					check = checkLoop('(', '[', 3);
				}
			}
		}
	}


	//for���� ������ ���ÿ� ���ڸ� �����ִ�
	//�����ִ� ���ڸ� ��� ���ϸ� ���� ����
	while (!s.empty())
	{
		//��ȣ�� ������� �߸��� �Է�
		if (s.top() == '(' || s.top() == ')' || s.top() == '[' || s.top() == ']') {
			printf("0");
			return 0;
		}
		//���ڸ� ���ϰ� ��
		result += s.top() - '0';
		s.pop();
	}

	//������
	printf("%d", result);

	return 0;
}

int checkLoop(char c1,char c2,int value) {

	int result = 0;

	while (!s.empty())
	{
		//�ݴ°�ȣ�� ) �� checkLoop('[', '(', 2);
		//�ݴ°�ȣ�� ] �� checkLoop('(', '[', 3)

		
		if (s.top() == c1) {  // [) , (] �̷����
			return -1;
		}
		else if (s.top() == c2) { 
			//��ø�Ȱ�ȣ�ΰ�� result�� ���ϱ��� ���ÿ� Ǫ��ó��
			s.pop();
			result *= value;
			s.push(result+'0');
			break;
		}
		else {
			//�����ΰ�� result�� ���ϱ��� ��
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
