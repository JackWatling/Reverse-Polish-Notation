#include <vector>

class Stack
{
private:
	int m_size;
	int m_top;
	std::vector<int> m_data;

public:
	//Constructors
	Stack();
	Stack(int size);

	//Accessors & Mutators
	bool push(int value);
	int pop();
};