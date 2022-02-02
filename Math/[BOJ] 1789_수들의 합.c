#include <stdio.h>

int main()
{
	double n;
	double sum = 0;
	scanf("%lf", &n);
	int cnt = 1;
	while (sum + cnt <= n)
	{
		sum += cnt;
		cnt++;
	}
	if (sum + cnt > n)
		cnt--;
	printf("%d", cnt);
	return 0;
}