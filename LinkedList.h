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

//输出图书信息表
void outputBookLink(LinkedList& books);

//排序
void sortBookLink(LinkedList& books);

//修改图书信息
bool changeBook(LinkedList& books);

//逆序存储
void reverseBookLink(LinkedList& books);

//查找最贵图书
void max(LinkedList& books);

//入库
void insertBook(LinkedList& books);

//出库
void popBook(LinkedList& books);

# endif
