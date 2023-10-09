#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Book.h"

typedef struct linkedlist {
public:
	Book book;
	Book* next;
}LinkedNode, *LinkedList;

//���ͼ����Ϣ��
void outputBookLink(LinkedList& books);

//����
void sortBookLink(LinkedList& books);

//�޸�ͼ����Ϣ
bool changeBook(LinkedList& books);

//����洢
LinkedList&& reverseBookLink(LinkedList& books);

//�������ͼ��
void max(LinkedList& books);

//���
void insertBook(LinkedList& books);

//����
void popBook(LinkedList& books);

# endif