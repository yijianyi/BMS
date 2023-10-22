#include "LinkedList.h"
#include <iostream>

/*
* @brief ���ͼ����Ϣ
*/
void outputBookLink(LinkedList& books)
{
	LinkedList iter = books;
	int count = 0;
	while (iter != nullptr)
	{
		std::cout << ++count<< " " << iter->book.ID << " " << iter->book.name << " " << iter->book.price << std::endl;
		iter = iter->next;
	}
}

/*
* @brief ����ͼ��۸��������޸�����˳��
* @param books ����ͷ���
* @retval ��
*/
void sortBookLink(LinkedList& books)
{
	LinkedList head = books;
	LinkedNode* dummy = new LinkedNode();
	dummy->next = head;
	LinkedNode* tail = nullptr; // ά�������յ�
	// ���ϰѴ��ֵ����ת�ƣ������յ������ܱ�����ֵ���ٸ��±����յ�
	while (tail != head) {
		LinkedNode* pre = dummy;
		LinkedNode* cur = pre->next;
		LinkedNode* nxt = cur->next;
		while (nxt != tail) {
			if (nxt->book.price > cur->book.price) { // �������߽����ڵ�
				pre->next = nxt;
				cur->next = nxt->next;
				nxt->next = cur;

			}
			else {
				cur = cur->next;
			}
			pre = pre->next;
			nxt = cur->next;
		}
		tail = cur;
	}
	head = dummy->next;
	dummy = nullptr;
	delete dummy;
	books = head;
}

/*
* brief �޸�ͼ����Ϣ��������ƽ���۸�ͼ��۸����20%�����ڵ���ͼ��۸����10%
* param books ����ͷ���
* retval ��
*/
void changeBook(LinkedList& books)
{
	LinkedList iter = books;
	//����ƽ��ֵ
	double priceSum = 0,priceAVE;
	int count = 0;
	while (iter != nullptr)
	{
		priceSum += iter->book.price;
		count++;
		iter = iter->next;
	}
	if(count!=0)
		priceAVE = priceSum / count;

	//�޸�
	iter = books;
	while (iter != nullptr)
	{
		if (iter->book.price >= priceAVE)
		{
			iter->book.price *= 1.1;
		}
		else
		{
			iter->book.price *= 1.2;
		}
		iter = iter->next;
	}
}

/*
*@brief �������ͼ��
*/
void max(LinkedList& books)
{
	LinkedList iter = books;
	double max = 0;
	Book maxBook;
	while (iter != nullptr)
	{
		if (iter->book.price > max)
		{
			max = iter->book.price;
			maxBook = iter->book;
		}
		iter = iter->next;
	}
	std::cout << "����ͼ���ǣ�"<<maxBook.name << "��ֵΪ��"<< max <<"Ԫ"<< std::endl;
}
/*
*@brief ������
*/
void insertBook(LinkedList& books){
	Book book;
	int count;
	LinkedList iter = books;
	/*std::cin >> count;
	std::cout << "������ͼ��ID,ͼ������,ͼ��۸�,�м��Կո����" << std::endl;
	
	for(int i=0;i<count;i++){
		std::cin >> book.ID >> book.name >> book.price;
		//iter->book = book;
		//iter=iter->next;
		LinkedNode *s =new LinkedNode;
		s->book=book;
		s->next=iter->next;
		iter->next=s;
		iter=iter->next;
	}*/
	//��ѯ������
	int length = 0;
	LinkedList iter1 = books;
	while (iter1 != nullptr)
	{
		length++;
		iter1 = iter1->next;
	}


	std::cout << "�������λ��" << std::endl;
	std::cin>>count;
	if(length<count)
	   std::cout << "���λ�÷Ƿ�" << std::endl;
	else{
	std::cout << "������ͼ��ID,ͼ������,ͼ��۸�,�м��Կո����" << std::endl;
	std::cin >> book.ID >> book.name >> book.price;
	int j=1;
	
	iter = books;
	//��book���뵽ָ��λ��	
	 while (iter != nullptr && (j<count-1))
	 {
		iter=iter->next;
		j++;
	 }
	
	LinkedNode *s =new LinkedNode;
	s->book=book;	
	s->next=iter->next;
	iter->next=s;
	//�������������book������
	}
}


/*
*@brief �������
*/
void popBook(LinkedList& books){
   int count;
   std::cout << "����ɾ��λ��" << std::endl;
   std::cin>>count;
   LinkedList iter = books;

   //��ѯ������
   int length = 0;
	LinkedList iter1 = books;
	while (iter1 != nullptr)
	{
		length++;
		iter1 = iter1->next;
	}
   
   if(length<count)
      std::cout << "����λ�÷Ƿ�" << std::endl;
   else{
   
   //��ָ��λ�õ�bookɾ��	
   while (iter != nullptr && (count-2))
          {
			iter=iter->next;
			count--;
		  }
		  LinkedNode *s = iter->next;
		  iter->next=iter->next->next;
		  delete s;
        
	  }
}

/*
*@brief ���򴢴�
*/
void reverseBookLink(LinkedList& books){

	if (books == nullptr || books->next == nullptr) {
		return;
	}

	LinkedNode* prev = nullptr;   // ǰһ���ڵ�ָ��
	LinkedNode* curr = books;      // ��ǰ�ڵ�ָ��
	LinkedNode* next = nullptr;   // ��һ���ڵ�ָ��

	while (curr != nullptr) {
		next = curr->next;  // ���浱ǰ�ڵ����һ���ڵ�

		// ��ת��ǰ�ڵ�ָ��ָ��ǰһ���ڵ�
		curr->next = prev;

		// ����ָ��λ��
		prev = curr;
		curr = next;
	}

	books = prev;
}

