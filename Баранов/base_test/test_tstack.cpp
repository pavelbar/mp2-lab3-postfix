#include "stack.h"
#include <gtest.h>
//кодировка
TEST(TStack, can_create_stack_with_positive_length)//стек с положительной длиной
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, throws_when_create_vector_with_negative_length)//стек с отрицательной длиной
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(TStack, can_create_vector_with_equal_length) //стек с нулевой длиной
{
	ASSERT_ANY_THROW(TStack<int> v(0));
}

TEST(TStack, cant_create_too_large_vector) //стек большой длины 
{
	ASSERT_ANY_THROW(TStack<int> v(MaxSize + 1));
}

TEST(TStack, Push_and_full_stack) //добавить в полный стек
{
	TStack<int> v(2);
	v.Push(1);
	v.Push(2);
	ASSERT_ANY_THROW(v.Push(4));
}

TEST(TStack, Pop_and_clear_stack) //показать и удалить из пустого стека
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Pop());
}

TEST(TStack, Top_and_clear_stack) //показать из пустого стека
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Top());
}


TEST(TStack, Push_and_Top_one)//добавить в стек и показать верх
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, Push_and_Top_two)//добавить в стек и показать верх
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Top());
}

TEST(TStack, Push_and_Top_free)//добавить в стек и показать верх
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Top());
}

TEST(TStack, Push_and_Pop) //добавить в стек и показать, показать и удалить, показать
{
	TStack<int> v(5);
	v.Push(4);//нижний
	v.Push(5);//верхний
	EXPECT_EQ(5, v.Pop());
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, isEmpty_false_full_stack) //полный стек - не пуст
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	
	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isEmpty_true_clear_stack) //пустой стек - пуст
{
	TStack<int> v(2);
	EXPECT_EQ(1, v.IsEmpty());
}

TEST(TStack, isEmpty_false_any_stack) //не пустой стек - не пуст
{
	TStack<int> v(2);
	v.Push(4);
	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isFull_true_full_stack_) //полный стек - полон
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	EXPECT_EQ(1, v.isFull());
}

TEST(TStack, isFull_false_clear_stack)  //пустой стек - не полон
{
	TStack<int> v(2);
	EXPECT_EQ(0, v.isFull());
}

TEST(TStack, isFull_false_any_stack)  //не пустой стек - не полон
{
	TStack<int> v(2);
	v.Push(4);
	EXPECT_EQ(0, v.isFull());
}