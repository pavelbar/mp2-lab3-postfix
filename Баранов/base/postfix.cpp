#include "postfix.h"
#include "stack.h"

string TPostfix::ToPostfix()
{ 
	postfix=infix;
	return postfix;
}

double TPostfix::Calculate()
{
	return 0;
}