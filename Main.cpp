#include <iostream>
#include "LinkedList.cpp"
#include "SeqList.h"


int main() {
	LinkedNode *head;
	head = (LinkedNode *)malloc(sizeof(LinkedNode));
	if (head == NULL) {
		printf("内存分配失败");
		exit(0);
	}
	head->next = NULL;


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
				          "1.创建动态数组 2.扩容  3.查找图书 4.遍历输出动态数组 5.排序 6.逆序存储 7.查找最贵图书 8.插入新图书  9.删除旧图书 10.退出"
				          << std::endl;
				std::cin >> n1;
				if (n1 == 1)

					if (n1 == 2)

						if (n1 == 3)

							if (n1 == 4)

								if (n1 == 5)

									if (n1 == 6)

										if (n1 == 7)

											if (n1 == 8)

												if (n1 == 9)

													if (n1 == 10)
														break;
			}
		}


		if (n == 2) {
			int n2;
			while (1) {
				std::cout << "1.输出排序信息 2.排序 3.修改图书信息 4.逆序储存 5.查找最贵图书 6.入库 7.出库 8.退出" << std::endl;
				std::cin >> n2;
				if (n2 == 1)
					std::cout << "123";
				else if (n2 == 2)
					std::cout << "123";
				else if (n2 == 3)
					std::cout << "123";
				else if (n2 == 4)
					std::cout << "123";
				else if (n2 == 5)
					std::cout << "123";
				else if (n2 == 6) {
					insertBook(head);
					std::cout << "输入插入位置4" << std::endl;
					outputBookLink(head);
				} else if (n2 == 7)
					std::cout << "123";
				else if (n2 == 8)
					break;
			}
		}

		if (n == 3)
			break;
	}

	return 0;
}
