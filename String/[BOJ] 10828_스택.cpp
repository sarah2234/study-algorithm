#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string command;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, command);
		if (command.find("push") != string::npos)
		{
			if (command.substr(0, command.find(' ')) == "push")
				s.push(stoi(command.substr(command.find(' ') + 1)));
		}
		else
		{
			if (command == "pop")
			{
				if (s.size() > 0)
				{
					cout << s.top() << "\n";
					s.pop();
				}
				else
					cout << "-1\n";
			}
			else if (command == "size")
				cout << s.size() << "\n";
			else if (command == "empty")
			{
				if (s.size() == 0)
					cout << "1\n";
				else
					cout << "0\n";
			}
			else if (command == "top")
			{
				if (s.size() >   0)
					cout << s.top() << "\n";
				else
					cout << "-1\n";
			}
		}
	}
	return 0;
}