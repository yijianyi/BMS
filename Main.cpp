#include <iostream>
#include "LinkedList.h"
#include "SeqList.h"

void LinkedInit(LinkedList& head)
{
	LinkedList iter;
	iter = new LinkedNode("L001", "高等数学上", 45);
	head = iter;
	iter->next = new LinkedNode("L002", "高等数学下", 20);
	iter = iter->next;
	iter->next = new LinkedNode("L003", "线性代数", 28);
	iter = iter->next;
	iter->next = new LinkedNode("L004", "数据结构", 35);
}

void SeqInit(BookArray& books)
{
	createBookArray(books);

	books.books[0].ID = "S001";
	books.books[0].name = "高等数学上";
	books.books[0].price = 45;
	books.size += 1;

	books.books[1].ID = "S002";
	books.books[1].name = "高等数学下";
	books.books[1].price = 20;
	books.size += 1;

	books.books[2].ID = "S003";
	books.books[2].name = "线性代数";
	books.books[2].price = 28;
	books.size += 1;
	
	books.books[3].ID = "S004";
	books.books[3].name = "数据结构";
	books.books[3].price = 35;
	books.size += 1;
}

int main() {
	LinkedNode *head = nullptr;
	LinkedInit(head);
	outputBookLink(head);
	
	BookArray books;
	SeqInit(books);
	outputBookArray(books);

	//主界面
	while (1) {
		int n;
		std::cout << "测试用" << std::endl;
		std::cout << "1.顺序表  2.链表 3.退出" << std::endl;
		std::cin >> n ;


		if (n == 1) {
			int n1;
			while (1) {
				std::cout <<
				          "1.遍历输出动态数组 2.排序 3.逆序存储 4.查找最贵图书 5.插入新图书  6.删除旧图书 7.退出"
				          << std::endl;
				std::cin >> n1;
				if (n1 == 1)
					outputBookArray(books);
				else if (n1 == 2)
				{
					BookArray newBooks = sortBook(books);
					outputBookArray(newBooks);
				}
				else if (n1 == 3)
				{
					BookArray newBooks = reverse(books);
					outputBookArray(newBooks);
				}
				else if (n1 == 4)
				{
					Book book = maxPriceBook(books);
					std::cout << book.ID << " " << book.name << " " << book.price << std::endl;
				}
				else if (n1 == 5)
				{
					insertBook(books);
					outputBookArray(books);
				}
				else if (n1 == 6)
				{
					popBook(books);
					outputBookArray(books);
				}
				else if (n1 == 7)
					break;
			}
		}
		else if (n == 2) {
			int n2;
			while (1) {
				std::cout << "1.输出排序信息 2.排序 3.修改图书信息 4.逆序储存 5.查找最贵图书 6.入库 7.出库 8.退出" << std::endl;
				std::cin >> n2;
				if (n2 == 1)
					outputBookLink(head);
				else if (n2 == 2)
				{
					sortBookLink(head);
					outputBookLink(head);
				}
				else if (n2 == 3)
				{
					changeBook(head);
					outputBookLink(head);
				}
				else if (n2 == 4)
				{
					reverseBookLink(head);
					outputBookLink(head);
				}
				else if (n2 == 5)
					max(head);
				else if (n2 == 6) {
					insertBook(head);
					outputBookLink(head);
				}
				else if (n2 == 7)
				{
					popBook(head);
					outputBookLink(head);
				}
				else if (n2 == 8)
					break;
			}
		}
		else if (n == 3)
			break;
	}

	return 0;
}
