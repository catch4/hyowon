#include <stdio.h>
#include <string.h>

struct Shark
{
	int s, d, z;
};

int r, c, m, result;
Shark a[101][101];
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

void solve() {
	for (int t = 0; t < c; t++) {
		Shark b[101][101] = { 0 };

		for (int i = 0; i < r; i++) {
			if (a[i][t].z) {
				result += a[i][t].z;
				a[i][t] = { 0,0,0 };
				break;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j].z) {
					if (a[i][j].d < 2) {
						int s = a[i][j].s % ((r - 1) * 2);
						int d = a[i][j].d;
						int ni = i;
						while (s--) {
							if (ni == 0 && d == 0) d = 1;
							if (ni == r - 1 && d == 1) d = 0;
							ni += dx[d];
						}
						if(a[i][j].z>b[ni][j].z)
							b[ni][j]= { a[i][j].s, d, a[i][j].z };
					}
					else {
						int s = a[i][j].s % ((c - 1) * 2);
						int d = a[i][j].d;
						int nj = j;
						while (s--) {
							if (nj == 0 && d == 3) d = 2;
							if (nj == c - 1 && d == 2) d = 3;
							nj += dy[d];
						}
						if (a[i][j].z>b[i][nj].z)
							b[i][nj] = { a[i][j].s, d, a[i][j].z };
					}
					a[i][j] = { 0,0,0 };
				}
			}
		}
		memcpy(a, b, sizeof(b));
	}
}

int main() {

	scanf("%d %d %d", &r, &c, &m);

	for (int i = 0; i<m; i++) {
		int x, y, s, d, z;
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		a[x - 1][y - 1] = { s, d - 1, z };
	}
	solve();
	printf("%d", result);

	return 0;
}