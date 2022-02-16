#include <stdio.h>

void cut(int n, int col, int row);
int paper[128][128];
int blue, white;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}
	cut(n, 0, 0);
	printf("%d\n%d\n", white, blue);

	return 0;
}

void cut(int n, int col, int row)
{
	int check = paper[col][row];
	if (n == 1)
	{
		if (check == 1)
			blue++;
		else
			white++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (paper[i + col][j + row] != check)
			{
				cut(n / 2, col, row);
				cut(n / 2, col + n / 2, row);
				cut(n / 2, col, row + n / 2);
				cut(n / 2, col + n / 2, row + n / 2);
				return;
			}
		}
	}
	if (check == 1)
		blue++;
	else
		white++;
}