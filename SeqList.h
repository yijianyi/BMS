#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include "Book.h"

/*
* 说明
* 采用动态数组的存储方式
* 为方便查看图书个数，新建一个类
*/

/*
* books		数组首地址
* size		当前存储的数据量
* capacity	最大容量
*/
typedef struct bookarray {
public:
	Book* books;
	int size;
	int capacity;
}BookArray;

const int initSize = 20;

//创建动态数组
void createBookArray(BookArray* books);
//扩容
void inflateArray(BookArray* books);

//查找图书
Book findBook(BookArray books);

//遍历输出动态数组
void outputBookArray(BookArray books);

//排序
BookArray* sortBook(BookArray books);

//逆序存储
BookArray* reverse(BookArray books);

//查找最贵图书
Book maxPriceBook(BookArray books);

//插入新图书（入库）
void insertBook(BookArray* books);

//删除旧图书（出库）
void deleteBook(BookArray* books);

#endif