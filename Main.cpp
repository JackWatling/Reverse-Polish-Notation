#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

//Forward declarations
void solve();

//Stack
stack<int> values;
vector<string> words;

int main()
{
	//Get input
	string entry;
	getline(cin, entry);
	istringstream iss(entry);

	while(getline(iss, entry, ' '))
		words.push_back(entry);

	//Solve
	solve();
	cout << values.top() << endl;

	return 0;
}

void solve()
{
	int a;	//Holds stack pop
	int b;	//Holds stack pop

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i][0] == '+')
		{
			b = values.top();
			values.pop();
			a = values.top();
			values.pop();

			values.push(a + b);
		}
		else if (words[i][0] == '-')
		{
			b = values.top();
			values.pop();
			a = values.top();
			values.pop();

			values.push(a - b);
		}
		else if (words[i][0] == '*')
		{
			b = values.top();
			values.pop();
			a = values.top();
			values.pop();

			values.push(a * b);
		}
		else if (words[i][0] == '/')
		{
			b = values.top();
			values.pop();
			a = values.top();
			values.pop();

			values.push(a / b);
		}
		else
		{
			values.push(atoi(words[i].c_str()));
		}
	}

}