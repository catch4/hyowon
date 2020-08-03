#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 9;

string sudoku[MAX];
bool row[MAX][MAX + 1]; //열, 1 ~ 9
bool col[MAX][MAX + 1]; //행, 1 ~ 9
bool square[MAX][MAX + 1]; //3 * 3 박스 idx, 1 ~ 9

int change2SquareIdx(int y, int x)
{
	return (y / 3) * 3 + x / 3;
}

void DFS(int cnt)
{
	if (cnt == 81) //Sudoku는 총 81칸
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				cout << sudoku[i][j];
			cout << "\n";
		}
		exit(0); //답을 하나만 출력
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (sudoku[y][x] - '0') //칸이 채워져있다면
		DFS(cnt + 1);
	//채워져있지 않았고
	else
	{
		for (int k = 1; k <= MAX; k++)
		{
			//sudoku 규칙에 적합하면 채우고 본다
			if (!col[x][k] && !row[y][k] && !square[change2SquareIdx(y, x)][k])
			{
				sudoku[y][x] = k + '0';
				col[x][k] = true;
				row[y][k] = true;
				square[change2SquareIdx(y, x)][k] = true;
				DFS(cnt + 1);
				sudoku[y][x] = '0';
				col[x][k] = false;
				row[y][k] = false;
				square[change2SquareIdx(y, x)][k] = false;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < MAX; i++)
	{
		cin >> sudoku[i];
		for (int j = 0; j < MAX; j++)
		{
			int num = sudoku[i][j] - '0';
			if (num)
			{
				col[j][num] = true;
				row[i][num] = true;
				square[change2SquareIdx(i, j)][num] = true;
			}
		}
	}

	DFS(0); //sudoku는 81칸

	return 0;
}