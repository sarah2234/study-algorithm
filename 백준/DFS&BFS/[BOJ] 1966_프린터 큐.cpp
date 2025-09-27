#include <iostream>
#include <vector>
using namespace std;

void PriorityQueue()
{
	int docCnt, printDocIndex; // printDocIndex: Ã£´Â ¹®¼­
	cin >> docCnt >> printDocIndex;
	int cnt = 1;
	vector<int*> docPriority;
	int x;
	for (int j = 0; j < docCnt; j++)
	{
		cin >> x;
		docPriority.push_back(new int(x));
	}

	int* printDocPointer = docPriority[printDocIndex];
	while (printDocPointer != NULL)
	{
		int maxPriority = 0;
		for (int j = 0; j < docPriority.size(); j++)
		{
			if (*docPriority[j] > *docPriority[maxPriority])
			{
				maxPriority = j;
			}
		}
		if (docPriority[maxPriority] == printDocPointer)
		{
			cout << cnt << "\n";
			for (int i = 0; i < docPriority.size(); i++)
			{
				docPriority.clear();
			}
			return;
		}

		if (maxPriority != 0)
		{
			while (*docPriority[0] != *docPriority[maxPriority])
			{
				int* temp = docPriority[0];
				//docPriority.erase(docPriority.begin() + maxPriority);
				docPriority.erase(docPriority.begin());
				docPriority.push_back(temp);
				maxPriority--;
				if (maxPriority < 0)
					maxPriority = docPriority.size() - 1;
			}
		}

		docPriority.erase(docPriority.begin());
		cnt++;
	}
}
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0, x; i < n; i++)
	{
		PriorityQueue();
	}
	return 0;
}
