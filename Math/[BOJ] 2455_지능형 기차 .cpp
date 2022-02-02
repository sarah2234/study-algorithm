#include <iostream>
using namespace std;

int main()
{
	int in, out;
	int max_total = 0;
	int current_total = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> out;
		cin >> in;
		current_total += in - out;
		if (current_total > max_total)
			max_total = current_total;
			
	}
	cout << max_total;

	return 0;
}