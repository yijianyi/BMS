#include "SeqList.h"
#include <stdio.h>
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
