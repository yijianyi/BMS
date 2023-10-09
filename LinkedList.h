#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Book.h"

typedef struct linkedlist {
public:
	Book book;
	Book* next;
}LinkedNode, *LinkedList;

//输出图书信息表
void outputBookLink(LinkedList& books);

//排序
void sortBookLink(LinkedList& books);

//修改图书信息
bool changeBook(LinkedList& books);

//逆序存储
LinkedList&& reverseBookLink(LinkedList& books);

//查找最贵图书
void max(LinkedList& books);

//入库
void insertBook(LinkedList& books);

//出库
void popBook(LinkedList& books);

# endif