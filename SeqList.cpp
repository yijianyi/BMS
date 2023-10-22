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
BookArray sortBook(BookArray books)
{
	Book* book = books.books;
	for (size_t i = 0; i < books.size-1; i++)
	{
		for (size_t j = 0; j < books.size -1- i; j++)
		{
			if (book[j].price < book[j + 1].price)
			{
				Book temp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = temp;
			}
		}
	}
	return books;
}

/*
* @brief 图书逆序（不改变原数组）
* @param books 图书信息表
* @return 逆序后的数组
*/
BookArray reverse(BookArray books)
{
	Book* book = books.books;
	for (size_t i = 0; i < books.size/2; i++)
	{
		Book temp = book[i];
		book[i] = book[books.size - 1 - i];
		book[books.size - 1 - i] = temp;
	}
	return books;
}

/*
* @brief 查找最贵图书
* @param books 图书信息表
* @return 查找到的最贵图书
*/
Book maxPriceBook(BookArray books)
{
	Book* book = books.books;
	Book maxBook = book[0];
	for (size_t i = 1; i < books.size; i++)
	{
		if (book[i].price > maxBook.price)
		{
			maxBook = book[i];
		}
	}
	return maxBook;
}

/*
* @brief 入库
* @param books 图书信息表
* @return 无
*/
void insertBook(BookArray& books)
{
	outputBookArray(books);
	int count;
	std::cout << "请输入插入位置：";
	std::cin >> count;
	if (count > books.size+1)
	{
		std::cout << "插入位置无效" << std::endl;
		return;
	}

	Book book;
	std::cout << "请输入图书ID,图书名称,图书价格,中间以空格相隔" << std::endl;
	std::cin >> book.ID >> book.name >> book.price;

	if (books.size == books.capacity)
		if (!inflateArray(books, 5))
		{
			std::cout << "空间不足" << std::endl;
			return;
		}
			

	if (count-1 == books.size)
	{
		books.books[count-1] = book;
		books.size += 1;
	}
	else
	{
		for (size_t i = books.size-1; i >= count-1; i--)
		{
			books.books[i + 1] = books.books[i];
		}
		books.books[count - 1] = book;
	}
}

/*
* @brief 出库
* @param books 图书信息表
* @return 无
*/
void popBook(BookArray& books)
{
	outputBookArray(books);
	int count;
	std::cout << "请输入删除位置：";
	std::cin >> count;
	if (count > books.size)
	{
		std::cout << "删除位置无效" << std::endl;
		return;
	}


	if (count - 1 == books.size)
	{
		books.books[count - 1] = nullptr;
		books.size -= 1;
	}
	else
	{
		for (size_t i = count - 1; i < books.size; i++)
		{
			books.books[i] = books.books[i+1];
		}
	}
}