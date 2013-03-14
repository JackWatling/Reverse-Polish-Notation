#include "Stack.h"

Stack::Stack()
	:m_top(0), m_size(10)
{}

Stack::Stack(int size)
	:m_top(0), m_size(size)
{}

bool Stack::push(int value)
{
	if (++m_top < m_size)
	{
		m_data.push_back(value);
		return true;
	}
	return false;
}

int Stack::pop()
{
	if (m_top-- > 0)
	{
		int value = m_data.at(m_top);
		m_data.pop_back();
		return value;
	}
	return -1;
}