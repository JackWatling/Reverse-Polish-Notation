#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Forward declarations
void solve(string entry);

//Stack
stack<int> values;

int main(){
	//Get input
	string entry;
	getline(cin, entry);

	//Solve
	solve(entry);
	cout << values.top() << endl;

	return 0;
}

void solve(string entry){
	int a;	//Holds stack pop
	int b;	//Holds stack pop

	for(int i = 0; i < entry.size(); i++){
		switch(entry[i]){
			case '+':
				a = values.top();
				values.pop();
				b = values.top();
				values.pop();

				values.push((int)a + (int)b);
				break;

			case ' ':
				break;

			default:
				values.push(entry[i] - 48);
				break;
		}
	}
}