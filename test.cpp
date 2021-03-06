#pragma once
#include"BinaryThreading.h"

void TestBinaryTreeThd_In()
{
	int array1[20] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> tree1(array1, 10);

	tree1.InOrderThreading();
	tree1.InThreadOrder();

	int array2[20] = { 1, 2, 3, '#', '#', '#', 5, 6 };
	BinaryTreeThd<int> tree2(array2, 8);

	tree2.InOrderThreading();
	tree2.InThreadOrder();
}

// Ç°Ðò
void TestBinaryTreeThd_Prev()
{
	int array[20] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> tree1(array, 10);

	tree1.PrevOrderThreading();
}


int main()
{
	TestBinaryTreeThd_In();

	TestBinaryTreeThd_Prev();

	return 0;
}
