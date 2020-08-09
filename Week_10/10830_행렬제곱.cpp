#include <iostream>

using namespace std;

long long n,b,arr[6][6],result[6][6],temp[6][6];

void cal(long long a[6][6],long long b[6][6]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

int main() {
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
		result[i][i] = 1;
	}

	while (b > 0)
	{
		if (b % 2 == 1) {
			cal(result, arr);
		}
		cal(arr, arr);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}