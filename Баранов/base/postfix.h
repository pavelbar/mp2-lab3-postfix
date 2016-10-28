#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
	string infix;
	string postfix;
public:
	TPostfix(string val)
	{
		infix = val;
	}
	TPostfix(const TPostfix &v)
	{
		infix = v.infix;
		postfix = v.postfix;
	}

	int Priority(char val)
	{
		if ((val == '*') || (val == '/')) return 2;
		if ((val == '+') || (val == '-')) return 1;
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	double Calculate(); // Ââîä ïåðåìåííûõ, âû÷èñëåíèå ïî ïîñòôèêñíîé ôîðìå
};

#endif