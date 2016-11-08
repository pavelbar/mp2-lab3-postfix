#include "postfix.h"
#include "stack.h"
#include <iostream>
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi (преобразовать символы к типу int)
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
            else if (Priority(infix[i]) > Priority(stack_op.Top())) stack_op.Push(infix[i]);
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
    //https://ru.wikipedia.org/wiki/%D0%9E%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F_%D0%BF%D0%BE%D0%BB%D1%8C%D1%81%D0%BA%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C#.D0.9E.D0.B1.D1.89.D0.B8.D0.B9_.D0.BF.D0.BE.D1.80.D1.8F.D0.B4.D0.BE.D0.BA  
    //Алгоритм:
    //1. Обработка входного символа
    //    a) Если на вход подан операнд, он помещается на вершину стека.
    //    b) Если на вход подан знак операции, то соответствующая операция выполняется над требуемым количеством значений, 
    //    извлечённых из стека, взятых в порядке добавления.Результат выполненной операции кладётся на вершину стека.
    //2. Если входной набор символов обработан не полностью, перейти к шагу 1.
    //3. После полной обработки входного набора символов результат вычисления выражения лежит на вершине стека.
    TStack<double> stack(MaxSize);
    for (unsigned int i = 0; i < postfix.length(); i++)
    {
        //--a--
        if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
        {
            char tmp[MaxSize];
            tmp[0] = postfix[i];
            stack.Push(atoi(tmp));
        }
        else
            //--b--
        {
            if (postfix[i] == '+')
            {
                double tmp1 = stack.Pop();
                double tmp11 = stack.Pop();
                stack.Push(tmp11 + tmp1);
            }
            if (postfix[i] == '-')
            {
                double tmp1 = stack.Pop();
                double tmp11 = stack.Pop();
                stack.Push(tmp11 - tmp1);
            }
            if (postfix[i] == '/')
            {
                double tmp1 = stack.Pop();
                double tmp11 = stack.Pop();
                stack.Push(tmp11 / tmp1);
            }
            if (postfix[i] == '*')
            {
                double tmp1 = stack.Pop();
                double tmp11 = stack.Pop();
                stack.Push(tmp11 * tmp1);
            }
        }

    }
    return stack.Pop();;
}