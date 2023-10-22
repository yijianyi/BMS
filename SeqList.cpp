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
* @brief ͼ�����򣨲��ı�ԭ���飩
* @param books ͼ����Ϣ��
* @return ����������
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
* @brief �������ͼ��
* @param books ͼ����Ϣ��
* @return ���ҵ������ͼ��
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
* @brief ���
* @param books ͼ����Ϣ��
* @return ��
*/
void insertBook(BookArray& books)
{
	outputBookArray(books);
	int count;
	std::cout << "���������λ�ã�";
	std::cin >> count;
	if (count > books.size+1)
	{
		std::cout << "����λ����Ч" << std::endl;
		return;
	}

	Book book;
	std::cout << "������ͼ��ID,ͼ������,ͼ��۸�,�м��Կո����" << std::endl;
	std::cin >> book.ID >> book.name >> book.price;

	if (books.size == books.capacity)
		if (!inflateArray(books, 5))
		{
			std::cout << "�ռ䲻��" << std::endl;
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
* @brief ����
* @param books ͼ����Ϣ��
* @return ��
*/
void popBook(BookArray& books)
{
	outputBookArray(books);
	int count;
	std::cout << "������ɾ��λ�ã�";
	std::cin >> count;
	if (count > books.size)
	{
		std::cout << "ɾ��λ����Ч" << std::endl;
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