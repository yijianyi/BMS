#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Book.h"
#include <cstddef>


typedef struct linkedlist {
public:
	Book book;
	linkedlist* next;
	
	linkedlist() {
		this->next = nullptr;
	}
	linkedlist(Book book) {
		this->book = book;
		this->next = nullptr;
	}
	linkedlist(std::string ID, std::string name, double price) {
		this->book.ID = ID;
		this->book.name = name;
		this->book.price = price;
		this->next = nullptr;
	}
}LinkedNode, *LinkedList;

//���ͼ����Ϣ��
void outputBookLink(LinkedList& books);

//����
void sortBookLink(LinkedList& books);

//�޸�ͼ����Ϣ
bool changeBook(LinkedList& books);

//����洢
void reverseBookLink(LinkedList& books);

//�������ͼ��
void max(LinkedList& books);

//���
void insertBook(LinkedList& books);

//����
void popBook(LinkedList& books);

# endif
