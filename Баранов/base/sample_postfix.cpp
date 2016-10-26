#include <iostream>
#include <string>
#include "postfix.h"
//in my opinion, sample is not correct
using namespace std;

int main()
{
	string expression; 
	//TPostfix postfix;       in my opinion, it is not correct
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "Введите арифметическое выражение: ";
	cin >> expression;
	cout << expression << endl;
	/*?*/
	TPostfix postfix(expression);   //in my opinion, it is  correct
	/*?*/
	cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
	postfix.ToPostfix();
	cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
	res = postfix.Calculate();
	cout << res << endl;
	return 0;
}