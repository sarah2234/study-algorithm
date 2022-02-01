#include <iostream>
using namespace std;

void DrawStars(int num, char** printArray, int offsetRow, int offsetCol);

int main()
{
	int N;
	cin >> N;
	char** printArray = new char* [N];
	for (int i = 0; i < N; i++)
	{
		printArray[i] = new char[N];
		for (int j = 0; j < N; j++)
			printArray[i][j] = ' ';
	}
	DrawStars(N, printArray, 0, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << printArray[i][j];
		cout << endl;
	}
	
	for (int i = 0; i < N; i++)
		delete[] printArray[i];
	delete[] printArray;

	return 0;
}

void DrawStars(int num, char** printArray, int offsetRow, int offsetCol)
{
	if (num == 1)
	{
		printArray[offsetRow][offsetCol] = '*';
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 1 || j != 1)
				DrawStars(num / 3, printArray, i * num / 3 + offsetRow, j * num / 3 + offsetCol);
		}
	}
}