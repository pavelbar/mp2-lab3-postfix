#include "postfix.h"
#include "stack.h"
#include <iostream>
using namespace std;

string TPostfix::ToPostfix()
{
    char result[MaxSize];
    int result_pos = 0;
    TStack<char> stack_op(MaxSize);
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
    for (unsigned int i = 0; i < infix.length(); i++)
    {
        //--1--
        if ((infix[i] != '(') && (infix[i] != ')') && (infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/'))
        {
            result[result_pos] = infix[i];
            result_pos++;
            result[result_pos] = '\0';
        }
        //--2--
        if (infix[i] == '(') stack_op.Push(infix[i]);
        //--3--                                            
        if (infix[i] == ')')
        {
            while (stack_op.Top() != '(')//пока
            {
                result[result_pos] = stack_op.Pop();
                result_pos++;
                result[result_pos] = '\0';
            }
            stack_op.Pop();
        }
        //-----
        if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/'))
        {
            //--a--
            if (stack_op.IsEmpty() || stack_op.Top() == '(') stack_op.Push(infix[i]);
            //--b--
            else if ( Priority(infix[i]) > Priority(stack_op.Top()) ) stack_op.Push(infix[i]);
            //--c--
            else
            {
                while (!stack_op.IsEmpty() && Priority(infix[i]) <= Priority(stack_op.Top()))
                {
                    result[result_pos] = stack_op.Pop();
                    result_pos++;
                    result[result_pos] = '\0';
                }
                stack_op.Push(infix[i]);
            //-----
            }
        }

    }
    //--4--
    while (stack_op.IsEmpty() == 0)//пока
    {
        result[result_pos] = stack_op.Pop();
        result_pos++;
        result[result_pos] = '\0';
    }
    //-----
    postfix = result;
    return postfix;
}

double TPostfix::Calculate()
{
    //not implemented
    return 0;
}