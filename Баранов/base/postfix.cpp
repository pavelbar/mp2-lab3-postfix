#include "postfix.h"
#include "stack.h"
#include <iostream>
using namespace std;

string TPostfix::ToPostfix()
{
    char result[100];
    int result_pos = 0;
    TStack<char> stack_op(100);
    //---приоритеты----
    int arg_stack_priority;
    int arg_priority;
    char tmp_char;
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
    for (unsigned int i = 0; i<infix.length(); i++)
    {
        tmp_char = infix[i];
        if ((tmp_char == '+') || (tmp_char == '-') || (tmp_char == '*') || (tmp_char == '/'))
        {
            if ((stack_op.IsEmpty() == 0) && (stack_op.Top() == '(')) stack_op.Push(tmp_char);//(a)
            //-----(b)-----
            if ((stack_op.IsEmpty() == 0))
            {
                arg_stack_priority = Priority(stack_op.Top());
                arg_priority = Priority(tmp_char);
            }
            if ((stack_op.IsEmpty() == 0) && (arg_priority > arg_stack_priority)) stack_op.Push(tmp_char);
            //-------------
            else
                //-----(c)-----
            {
                if (stack_op.IsEmpty() == 0)
                    while ((stack_op.IsEmpty() == 0) && ((stack_op.Top() != '(') || (arg_priority < Priority(stack_op.Top()))))  //пока
                    {


                        result[result_pos] = stack_op.Pop();
                        result_pos++;
                        result[result_pos] = NULL;

                    }
                stack_op.Push(tmp_char);
                //-------------
            }

            if (tmp_char == '(') stack_op.Push(tmp_char);//(2)
            //-----(3)-----
            if ((stack_op.IsEmpty() == 0) && (tmp_char == ')'))
            {
                while ((stack_op.IsEmpty() == 0) && (stack_op.Top() != '('))//пока
                {
                    result[result_pos] = stack_op.Pop();
                    result_pos++;
                    result[result_pos] = '\0';
                }
                if (stack_op.IsEmpty() == 0)
                    stack_op.Pop();
            }
            //-------------
        }
        else
        {
            result[result_pos] = tmp_char;//(1)
            result_pos++;
            result[result_pos] = '\0';
        }
    }
    //-----(4)-----
    while (stack_op.IsEmpty() == 0)//пока
    {
        if (stack_op.IsEmpty() == 0)
            result[result_pos] = stack_op.Pop();
        result_pos++;
        result[result_pos] = '\0';
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