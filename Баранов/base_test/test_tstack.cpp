#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)//стек с положительной длиной
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, cant_create_stack_with_negative_length)//стек с отрицательной длиной
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(TStack, cant_create_stack_with_zero_length) //стек с нулевой длиной
{
	ASSERT_ANY_THROW(TStack<int> v(0));
}

TEST(TStack, cant_create_too_large_stack) //стек большой длины 
{
	ASSERT_ANY_THROW(TStack<int> v(MaxSize + 1));
}

TEST(TStack, cant_push_to_full_stack) //добавить в полный стек
{
	TStack<int> v(2);
	v.Push(1);
	v.Push(2);
	ASSERT_ANY_THROW(v.Push(4));
}

TEST(TStack, cant_pop_of_clear_stack) //показать и удалить из пустого стека
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Pop());
}

TEST(TStack, cant_top_of_clear_stack) //показать из пустого стека
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Top());
}


TEST(TStack, can_top_of_stack_about_one)//добавить в стек и показать верх 1
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, can_top_of_stack_about_two)//добавить в стек и показать верх 2
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Top());
}

TEST(TStack, can_top_of_stack_about_three)//добавить в стек и показать верх 3
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Top());
}

TEST(TStack, can_pop_of_stack_about_one)//добавить в стек и показать и удалить верх 1
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Pop());
}

TEST(TStack, can_pop_of_stack_about_two)//добавить в стек и показать и удалить верх 2
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Pop());
}

TEST(TStack, can_pop_of_stack_about_three)//добавить в стек и показать и удалить верх 3
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Pop());
}

TEST(TStack, can_push_and_pop) //добавить в стек и показать, показать и удалить, показать
{
	TStack<int> v(5);
	v.Push(4);//нижний
	v.Push(5);//верхний
	EXPECT_EQ(5, v.Pop());
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, isEmpty_false_of_full_stack) //полный стек - не пуст
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	
	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isEmpty_true_of_clear_stack) //пустой стек - пуст
{
	TStack<int> v(2);
	EXPECT_EQ(1, v.IsEmpty());
}

TEST(TStack, isEmpty_false_of_any_stack) //не пустой стек - не пуст
{
	TStack<int> v(2);
	v.Push(4);
	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isFull_true_of_full_stack) //полный стек - полон
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	EXPECT_EQ(1, v.isFull());
}

TEST(TStack, isFull_false_of_clear_stack)  //пустой стек - не полон
{
	TStack<int> v(2);
	EXPECT_EQ(0, v.isFull());
}

TEST(TStack, isFull_false_of_any_stack)  //не пустой стек - не полон
{
	TStack<int> v(2);
	v.Push(4);
	EXPECT_EQ(0, v.isFull());
}