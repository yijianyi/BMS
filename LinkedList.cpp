#include "LinkedList.h"
#include <iostream>

/*
* @brief ���ͼ����Ϣ
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
*@brief �������ͼ��
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
	std::cout << "����ͼ���ǣ�"<<maxBook.name << "��ֵΪ��"<< max <<"Ԫ"<< std::endl;
}
/*
*@brief ������
*/
void insertBook(LinkedList& books){

	Book book;
	int count;
	std::cin >>count;
	std::cout << "������ͼ��ID,ͼ������,ͼ��۸�,�м��Կո����" << std::endl;
	LinkedList iter = books;
	for(int i=0;i<count;i++){
		std::cin >> book.ID >> book.name >> book.price>>std::endl;
		iter->book = book;
		iter=iter->next;
	}
	std::cout << "�������λ��" << std::endl;
	std::cin>>count;
	for (int i = 0; i < count; i++){
		iter=iter->next;
	}
}
