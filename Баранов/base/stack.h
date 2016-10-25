#ifndef __STACK_H__
#define __STACK_H__
const int MaxSize = 100;
template <class T>
class TStack
{
protected:
	T *pMem;
	int size;
	int count;
public:
	TStack(int len);
	~TStack();
	bool isEmpty();
	bool isFull();
	void Push(const T &val);//add
	T Pop();//взять верхний и удалить
	T Top();//view
};
//-----------------------------------
template <class ValType>
TStack<T>::TStack(int len) {
	if ((len<1) || (len>MaxSize)) throw (len);
	size = len;
	count = 0;
	pMem = new T[size];
}

template <class T>
TStack<T>::~TStack() {
	delete[]pMem;
	pMem = NULL;
}

template <class T>
bool TStack<T>::IsEmpty() {
	return(count == MaxSize);
}

template <class T>
bool TStack<T>::isFull() {
	return (count == 0);
}

template <class T>
void TStack<T>::Push(const T &val) {
	if (isFull())  throw (count);
	return pMem[count++] = val; }

template <class T>
T TStack<T>::Pop() {
	if (IsEmpty) throw (count);
	return pMem[(count--) - 1]; }

template <class T>
T TStack<T>::Top() {
	if (IsEmpty) throw (count);
	return pMem[count - 1]; }
#endif
