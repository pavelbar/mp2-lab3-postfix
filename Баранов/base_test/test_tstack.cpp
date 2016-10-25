#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)//���� � ������������� ������
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, throws_when_create_vector_with_negative_length)//���� � ������������� ������
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(TStack, can_create_vector_with_equal_length) //���� � ������� ������
{
	ASSERT_ANY_THROW(TStack<int> v(0));
}

TEST(TStack, cant_create_too_large_vector) //���� ������� ����� 
{
	ASSERT_ANY_THROW(TStack<int> v(MaxSize + 1));
}

TEST(TStack, Push_and_full_stack) //�������� � ������ ����
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	ASSERT_ANY_THROW(v.Push(4));
}

TEST(TStack, Pop_and_clear_stack) //�������� � ������� �� ������� �����
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Pop());
}

TEST(TStack, Top_and_clear_stack) //�������� �� ������� �����
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Top());
}


TEST(TStack, Push_and_Top)//�������� � ���� � ��������
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, Push_and_Pop) //�������� � ���� � ��������, �������� � �������, ��������
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(5);
	EXPECT_EQ(5, v.Pop());
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, isEmpty_false) //������ ���� - �� ����
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	EXPECT_EQ(0, v.IsEmpty());
}

TEST(TStack, isEmpty_trye) //������ ���� - ����
{
	TStack<int> v(2);
	EXPECT_EQ(1, v.IsEmpty());
}

TEST(TStack, isFull_try) //������ ���� - �����
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	EXPECT_EQ(1, v.isFull());
}

TEST(TStack, isFull_false)  //������ ���� - �� �����
{
	TStack<int> v(2);
	EXPECT_EQ(0, v.isFull());
}
