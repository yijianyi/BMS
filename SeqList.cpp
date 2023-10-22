#include "SeqList.h"
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

/*
* @brief ������̬����
* @param books BookArray���͵�����
* @retval ��
*/
void createBookArray(BookArray& books)
{
	books.books = (Book*)malloc(sizeof(Book) * initSize);
	books.capacity = initSize;
	books.size = 0;
}

/*
* @brief ��̬��������
* @param books BookArray���͵�����
* @param inflateSize ��չ��������Ҫ��չ���λ�þ�Ϊ5
* @retval �����Ƿ����ݳɹ����ɹ�Ϊtrue��ʧ��Ϊfalse
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
* @brief ���ͼ����Ϣ
* @param booksͼ����Ϣ��
* @return ��
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
* @brief ͼ�鰴�۸������򣨲��ı�ԭ����˳��
* @param books ͼ����Ϣ��
* @return ����������
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
* @brief ͼ�����򣨲��ı�ԭ���飩
* @param books ͼ����Ϣ��
* @return ����������
*/
BookArray* reverse(BookArray books);

/*
* @brief �������ͼ��
* @param books ͼ����Ϣ��
* @return ���ҵ������ͼ��
*/
Book maxPriceBook(BookArray books);

/*
* @brief ���
* @param books ͼ����Ϣ��
* @return ��
*/
void insertBook(BookArray& books);

/*
* @brief ����
* @param books ͼ����Ϣ��
* @return ��
*/
void popBook(BookArray& books);