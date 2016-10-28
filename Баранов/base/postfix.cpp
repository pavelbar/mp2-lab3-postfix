#include "postfix.h"
#include "stack.h"

string TPostfix::ToPostfix()
{
	postfix = infix;
	return postfix;
}

double TPostfix::Calculate()
{
	//not implemented
	return 0;
}