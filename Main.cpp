#include <iostream>
#include "LinkedList.h"
#include "SeqList.h"


int main() {
	LinkedNode *head;
	//head = (LinkedNode *)malloc(sizeof(LinkedNode));
	head = new LinkedNode("001", "aaa", 22);
	head->next = new LinkedNode("002", "bbb", 33);
	//outputBookLink(head);
	if (head == NULL) {
		printf("�ڴ����ʧ��");
		exit(0);
	}
	head->next = NULL;


	//������
	while (1) {
		int n;
		std::cout << "������" << std::endl;
		std::cout << "1.˳���  2.���� 3.�˳�" << std::endl;
		std::cin >> n ;


		if (n == 1) {
			int n1;
			while (1) {
				std::cout <<"1.������̬���� 2.����  3.����ͼ�� 4.���������̬���� 5.���� 6.����洢 7.�������ͼ�� 8.������ͼ��  9.ɾ����ͼ�� 10.�˳�"<< std::endl;
				std::cin >> n1;
				if (n1 == 1)
					      std::cout << "123";
				else if (n1 == 2)
					       std::cout << "123";
				else if (n1 == 3)
							std::cout << "123";
				else if (n1 == 4)
							std::cout << "123";
				else if (n1 == 5)
							std::cout << "123";
				else if (n1 == 6)
							std::cout << "123";
				else if (n1 == 7)
							std::cout << "123";
				else if (n1 == 8)
							std::cout << "123";
				else if (n1 == 9)
							std::cout << "123";
				else if (n1 == 10)
						break;
			}
		}


		if (n == 2) {
			int n2;
			while (1) {
				std::cout << "1.���������Ϣ 2.���� 3.�޸�ͼ����Ϣ 4.���򴢴� 5.�������ͼ�� 6.��� 7.���� 8.�˳�" << std::endl;
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

		if (n == 3)
			break;
	}

	return 0;
}
