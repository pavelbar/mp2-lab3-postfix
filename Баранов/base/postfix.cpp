#include "postfix.h"
#include "stack.h"
#include <iostream>
using namespace std;

string TPostfix::ToPostfix()
{
	string result;
	int result_pos=0;
	TStack<char> stack_op(100);
	//---приоритеты----
	int arg_stack_priority;
	int arg_priority;
	/*http://natalia.appmat.ru/c&c++/postfisso.html
	Алгоритм перевода выражения в постфиксную запись следующий:
	(1) Константы и переменные кладутся в формируемую запись в порядке их появления в исходном массиве.
	При появлении операции в исходном массиве:
	(a) если в стеке нет операций или верхним элементом стека является открывающая скобка, операции кладётся в стек;
	(b) если новая операции имеет больший* приоритет, чем верхняя операции в стеке, то новая операции кладётся в стек;
	(c) если новая операция имеет меньший или равный приоритет, чем верхняя операции в стеке, то 
		операции, находящиеся в стеке, до ближайшей открывающей скобки или до операции с приоритетом меньшим, чем у новой операции,
		перекладываются в формируемую запись, а новая операции кладётся в стек.
	(2)Открывающая скобка кладётся в стек.
	(3)Закрывающая скобка выталкивает из стека в формируемую запись все операции до ближайшей открывающей скобки, открывающая скобка 
		удаляется из стека.
	(4)После того, как мы добрались до конца исходного выражения, операции, оставшиеся в стеке, перекладываются в формируемое выражение.
	*/
	for (int i = 0; i<infix.length(); i++)
	{
		if ((infix[i] = '+') || (infix[i] = '-') || (infix[i] = '*') || (infix[i] = '/'))
		{
			if ((stack_op.IsEmpty() == 0) && (stack_op.Top() == '(')) stack_op.Push(infix[i]);//(a)
			//-----(b)-----
			if  ((stack_op.IsEmpty() == 0))
			{
			arg_stack_priority = Priority(infix[i]);
			arg_priority = Priority(stack_op.Top());
			 if ((stack_op.IsEmpty() == 0) && (arg_priority > arg_stack_priority)) stack_op.Push(infix[i]);
			//-------------
			else
				//-----(c)-----
			{
				if (stack_op.IsEmpty() == 0)
					while ((stack_op.IsEmpty() == 0) && ( (stack_op.Top() != '(') || (arg_priority < Priority(stack_op.Top()))))  //пока
					{


						result[result_pos] = stack_op.Pop();
						result_pos++;

					}
				if (stack_op.IsEmpty() == 0)
				stack_op.Push(infix[i]);
				//-------------
			}
		}
			if ((stack_op.IsEmpty() == 0)&& ( infix[i] == '(' )) stack_op.Push(infix[i]);//(2)
			//-----(3)-----
			if ((stack_op.IsEmpty() == 0) && (infix[i] == ')'))
			{
				while ((stack_op.IsEmpty() == 0)&& (stack_op.Top() != '('))//пока
				{
					result[result_pos] = stack_op.Pop();
					result_pos++;
				}
				if (stack_op.IsEmpty() == 0)
				stack_op.Pop();
			}
			//-------------
		}
		else
		{
			if (stack_op.IsEmpty() == 0)
			stack_op.Push(infix[i]);//(1)
		}
	}
	//-----(4)-----
	while (stack_op.IsEmpty()==0)//пока
	{
		if (stack_op.IsEmpty() == 0)
		result[result_pos] = stack_op.Pop();
		result_pos++;
	}
	//-------------
	postfix = result;
	return postfix;
}

double TPostfix::Calculate()
{
	//not implemented
	return 0;
}