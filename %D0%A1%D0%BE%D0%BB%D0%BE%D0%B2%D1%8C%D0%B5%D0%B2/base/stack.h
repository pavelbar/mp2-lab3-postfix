#ifndef __STACK_H__
#define __STACK_H__

const int MAX_SIZE_STACK = 100;

template <class ValType>
class TStack
{
	ValType *pMem;
	int count;
public:
	TStack(int len);
	bool IsEmpty();
	bool IsFull();
	void Push(ValType val); // положить элемент 
	ValType Pop(); //взять элемент
	ValType Top(); // посмотреть элемент
};

template <class ValType>
TStack<ValType>::TStack(int len)
{
	count=0;
	if((len<1) || (len>MAX_SIZE_STACK)) throw (len);
	pMem=new ValType[len];
}

template <class ValType>
bool TStack<ValType>::IsEmpty()
{
	return (count==0);
}

template<class ValType>
bool TStack<ValType>::IsFull()
{
	return(count==MAX_SIZE_STACK);
}

template<class ValType>
void TStack<ValType>::Push(ValType val)
{
	if(IsFuLL()!=true)
		return pMem[count++]=val;
}

template <class ValType>
ValType TStack<ValType> ::Pop()
{
	if(IsEmpty==true) throw();
	if(IsEmpty!=true)
	{
		return pMem[(count--)-1];
	}

	template <class ValType>
	ValType TStack<ValType>::Top()
	{
		if(IsEmpty==true) throw();
		if(IsEmpty!=true)
		{
			return pMem[(count)-1];
		}
	}
}

#endif
