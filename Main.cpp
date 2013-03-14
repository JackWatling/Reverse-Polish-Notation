#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Stack.h"

using namespace std;

//Forward declarations
void solve();

//Stack
vector<string> words;
Stack values;

int main()
{
	//Get input
	string entry;
	getline(cin, entry);
	istringstream iss(entry);

	//Push words into vector
	while(getline(iss, entry, ' '))
		words.push_back(entry);

	//Basic malform check
	if (words.size() < 3)
	{
		cout << "Malformed" << endl;
		return 0;
	}

	//Solve
	solve();
	cout << values.pop() << endl;

	return 0;
}

void solve()
{
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i].length() == 1)
		{
			switch(words[i][0])
			{
				//Addition
				case '+':
					values.push(values.pop() + values.pop());
					break;

				//Subtraction
				case '-':
					values.push(-values.pop() + values.pop());
					break;

				//Multiplication
				case '*':
					values.push(values.pop() * values.pop());
					break;

				//Division
				case '/':
					values.push((1.0f / values.pop()) * values.pop());
					break;

				//Numerical
				default:
					values.push(atoi(words[i].c_str()));
					break;
			}
		}
		else
		{
			//Numerical
			values.push(atoi(words[i].c_str()));
		}
	}
}