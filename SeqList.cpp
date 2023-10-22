#include "SeqList.h"
#include <iostream>
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

/*
* @brief 输出图书信息
* @param books图书信息表
* @return 无
*/
void outputBookArray(BookArray books)
{
	Book* book = books.books;
	for (size_t i = 0; i < books.size; i++)
	{
		std::cout << i + 1 << " " << book[i].ID << " " << book[i].name << " " << book[i].price << std::endl;
	}
}

/*
* @brief 图书按价格降序排序（不改变原数组顺序）
* @param books 图书信息表
* @return 排序后的数组
*/
BookArray* sortBook(BookArray books)
{
	Book* book = books.books;
	for (size_t i = 0; i < books.size; i++)
	{
		for (size_t j = 0; j < books.size - i; j++)
		{
			
		}
	}
}

/*
* @brief 图书逆序（不改变原数组）
* @param books 图书信息表
* @return 逆序后的数组
*/
BookArray* reverse(BookArray books);

/*
* @brief 查找最贵图书
* @param books 图书信息表
* @return 查找到的最贵图书
*/
Book maxPriceBook(BookArray books);

/*
* @brief 入库
* @param books 图书信息表
* @return 无
*/
void insertBook(BookArray& books);

/*
* @brief 出库
* @param books 图书信息表
* @return 无
*/
void popBook(BookArray& books);