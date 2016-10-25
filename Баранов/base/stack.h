#ifndef __STACK_H__
#define __STACK_H__
#include <cstddef>

const int MaxSize = 100;
template <class ValType>
class TStack
{
protected:
	ValType *pMem;
	int size;
	int count;
public:
	TStack(int len);
	~TStack();
	bool IsEmpty();
	bool isFull();
	void Push(const ValType &val);//add
	ValType Pop();//взять верхний и удалить
	ValType Top();//view
};
//-----------------------------------
template <class ValType>
TStack<ValType>::TStack(int len) {
	if ((len<1) || (len>MaxSize)) throw (len);
	size = len;
	count = 0;
	pMem = new ValType[size];
}

template <class ValType>
TStack<ValType>::~TStack() {
	delete[]pMem;
	pMem = NULL;
}

template <class ValType>
bool TStack<ValType>::IsEmpty() {
	return(count == MaxSize);
}

template <class ValType>
bool TStack<ValType>::isFull() {
	return (count == 0);
}

template <class ValType>
void TStack<ValType>::Push(const ValType &val) {
	if (isFull())  throw (count);
	pMem[count++] = val; }

template <class ValType>
ValType TStack<ValType>::Pop() {
	if (IsEmpty()) throw (count);
	return pMem[(count--) - 1]; }

template <class ValType>
ValType TStack<ValType>::Top() {
	if (IsEmpty()) throw (count);
	return pMem[count - 1]; }
#endif
