#include "LinkedList.h"
#include <iostream>

/*
* @brief 输出图书信息
*/
void outputBookLink(LinkedList& books)
{
	LinkedList iter = books;
	int count = 0;
	while (iter != nullptr)
	{
		std::cout << ++count << iter->book.ID << " " << iter->book.name << " " << iter->book.price << std::endl;
		iter = iter->next;
	}
}
/*
*@brief 查找最贵图书
*/
void max(LinkedList& books)
{
	LinkedList iter = books;
	double max = 0;
	Book maxBook;
	while (iter != nullptr)
	{
		if (iter->book.price > max)
		{
			max = iter->book.price;
			maxBook = iter->book;
		}
		iter = iter->next;
	}
	std::cout << "最贵的图书是："<<maxBook.name << "价值为："<< max <<"元"<< std::endl;
}
/*
*@brief 入库操作
*/
void insertBook(LinkedList& books){

	Book book;
	int count;
	std::cin >>count;
	std::cout << "请输入图书ID,图书名称,图书价格,中间以空格相隔" << std::endl;
	LinkedList iter = books;
	for(int i=0;i<count;i++){
		std::cin >> book.ID >> book.name >> book.price>>std::endl;
		iter->book = book;
		iter=iter->next;
	}
	std::cout << "输入插入位置" << std::endl;
	std::cin>>count;
	for (int i = 0; i < count; i++){
		iter=iter->next;
	}
}
