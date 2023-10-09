#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* @brief 创建动态数组
* @param books BookArray类型的引用
* @retval 无
*/
void createBookArray(BookArray& books)
{
	books.books = (Book*)malloc(sizeof(Book) * initSize);
	books.capacity = initSize;
	books.size = 0;
}

/*
* @brief 动态数组扩容
* @param books BookArray类型的引用
* @param inflateSize 扩展的容量，要扩展五个位置就为5
* @retval 返回是否扩容成功，成功为true，失败为false
*/
bool inflateArray(BookArray& books, size_t inflateSize)
{
	Book* temp = (Book*)realloc(books.books, (books.capacity + inflateSize) * sizeof(Book));
	if (temp)
	{
		books.books = temp;
		books.capacity += inflateSize;
		return true;
	}
	else
	{
		return false;
	}
}
