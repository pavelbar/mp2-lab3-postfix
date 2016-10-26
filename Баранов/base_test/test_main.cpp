#include <gtest.h>
#include <windows.h>
#include "stack.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	//--DEBUG SEGMENT--
	//TStack <int> v(5);
	//v.Push(4);
	//v.Push(7);
	//cout << "Pop" << v.Pop()<<endl;           //взять верхний и удалить
	//cout << "Top" <<  v.Top()<<endl;          //взять
	//cout << "IsEmpty  =" << v.IsEmpty()<<endl;
	//cout << "isFull  =" << v.isFull()<<endl;
	//-----------------
	system("pause");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
