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
	std::cin >>count;
	std::cout << "������ͼ��ID,ͼ������,ͼ��۸�,�м��Կո����" << std::endl;
	LinkedList iter = books;
	for(int i=0;i<count;i++){
		std::cin >> book.ID >> book.name >> book.price;
		/*iter->book = book;
		iter=iter->next;*/
		LinkedNode *s =new LinkedNode;
		s->book=book;
		s->next=iter->next;
		iter->next=s;
		iter=iter->next;
	}
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
	int j=0;
	
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
   while (iter != nullptr && (count-1))
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

   //��ѯ������
   int length = 0;
	LinkedList iter1 = books;
	while (iter1 != nullptr)
	{
		length++;
		iter1 = iter1->next;
	}

   if(length<2)
      std::cout << "ֻ��һ��Ԫ�أ����򴢴�Ƿ�" << std::endl;
	  else{
	  LinkedList iter = books;
	  LinkedList iter1 = books;
	  LinkedList iter2 = books;
	  iter2=iter2->next;
	  iter1=iter1->next;
	  iter2=iter2->next;
	  iter1->next=nullptr;
	  while (iter2 != nullptr)
	  {
		iter1->next=iter2;
		iter1=iter1->next;
		iter2=iter2->next;
	  }
	  iter1->next=iter;
	  books=iter1;
	  


	  }


}

