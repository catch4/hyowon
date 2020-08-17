#include <iostream>

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

char arr[2001][2001];

int main() {

	int n, m;
	int cnt = 0;
	int result = 1;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (arr[i][j] != arr[nx][ny]) {
						cnt++;
						break;
					}
				}
			}
		}
	}

	//2^(색이 정해지지 않은 격자의 수) 
	for (int i = 0; i < (n*m) - cnt; i++) {
		result = (result * 2) % 1000000007;
	}

	cout << result;

	return 0;
}