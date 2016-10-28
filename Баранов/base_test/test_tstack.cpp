#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)//ñòåê ñ ïîëîæèòåëüíîé äëèíîé
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, cant_create_stack_with_negative_length)//ñòåê ñ îòðèöàòåëüíîé äëèíîé
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(TStack, cant_create_stack_with_zero_length) //ñòåê ñ íóëåâîé äëèíîé
{
	ASSERT_ANY_THROW(TStack<int> v(0));
}

TEST(TStack, cant_create_too_large_stack) //ñòåê áîëüøîé äëèíû 
{
	ASSERT_ANY_THROW(TStack<int> v(MaxSize + 1));
}

TEST(TStack, cant_push_to_full_stack) //äîáàâèòü â ïîëíûé ñòåê
{
	TStack<int> v(2);
	v.Push(1);
	v.Push(2);
	ASSERT_ANY_THROW(v.Push(4));
}

TEST(TStack, cant_pop_of_clear_stack) //ïîêàçàòü è óäàëèòü èç ïóñòîãî ñòåêà
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Pop());
}

TEST(TStack, cant_top_of_clear_stack) //ïîêàçàòü èç ïóñòîãî ñòåêà
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Top());
}


TEST(TStack, can_top_of_stack_about_one)//äîáàâèòü â ñòåê è ïîêàçàòü âåðõ 1
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, can_top_of_stack_about_two)//äîáàâèòü â ñòåê è ïîêàçàòü âåðõ 2
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Top());
}

TEST(TStack, can_top_of_stack_about_three)//äîáàâèòü â ñòåê è ïîêàçàòü âåðõ 3
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Top());
}

TEST(TStack, can_pop_of_stack_about_one)//äîáàâèòü â ñòåê è ïîêàçàòü è óäàëèòü âåðõ 1
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Pop());
}

TEST(TStack, can_pop_of_stack_about_two)//äîáàâèòü â ñòåê è ïîêàçàòü è óäàëèòü âåðõ 2
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Pop());
}

TEST(TStack, can_pop_of_stack_about_three)//äîáàâèòü â ñòåê è ïîêàçàòü è óäàëèòü âåðõ 3
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Pop());
}

TEST(TStack, can_push_and_pop) //äîáàâèòü â ñòåê è ïîêàçàòü, ïîêàçàòü è óäàëèòü, ïîêàçàòü
{
	TStack<int> v(5);
	v.Push(4);//íèæíèé
	v.Push(5);//âåðõíèé
	EXPECT_EQ(5, v.Pop());
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, isEmpty_false_of_full_stack) //ïîëíûé ñòåê - íå ïóñò
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);

	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isEmpty_true_of_clear_stack) //ïóñòîé ñòåê - ïóñò
{
	TStack<int> v(2);
	EXPECT_EQ(1, v.IsEmpty());
}

TEST(TStack, isEmpty_false_of_any_stack) //íå ïóñòîé ñòåê - íå ïóñò
{
	TStack<int> v(2);
	v.Push(4);
	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isFull_true_of_full_stack) //ïîëíûé ñòåê - ïîëîí
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	EXPECT_EQ(1, v.isFull());
}

TEST(TStack, isFull_false_of_clear_stack)  //ïóñòîé ñòåê - íå ïîëîí
{
	TStack<int> v(2);
	EXPECT_EQ(0, v.isFull());
}

TEST(TStack, isFull_false_of_any_stack)  //íå ïóñòîé ñòåê - íå ïîëîí
{
	TStack<int> v(2);
	v.Push(4);
	EXPECT_EQ(0, v.isFull());
}