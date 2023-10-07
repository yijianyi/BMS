#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include "Book.h"

/*
* ˵��
* ���ö�̬����Ĵ洢��ʽ
* Ϊ����鿴ͼ��������½�һ����
*/

/*
* books		�����׵�ַ
* size		��ǰ�洢��������
* capacity	�������
*/
typedef struct bookarray {
public:
	Book* books;
	int size;
	int capacity;
}BookArray;

const int initSize = 20;

//������̬����
void createBookArray(BookArray* books);
//����
void inflateArray(BookArray* books);

//����ͼ��
Book findBook(BookArray books);

//���������̬����
void outputBookArray(BookArray books);

//����
BookArray* sortBook(BookArray books);

//����洢
BookArray* reverse(BookArray books);

//�������ͼ��
Book maxPriceBook(BookArray books);

//������ͼ�飨��⣩
void insertBook(BookArray* books);

//ɾ����ͼ�飨���⣩
void deleteBook(BookArray* books);

#endif