#include "LinkedList.h"
#include <iostream>

/*
* @brief 输出图书信息
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
*@brief 查找最贵图书
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
	std::cout << "最贵的图书是："<<maxBook.name << "价值为："<< max <<"元"<< std::endl;
}
/*
*@brief 入库操作
*/
void insertBook(LinkedList& books){

	Book book;
	int count;
	std::cin >>count;
	std::cout << "请输入图书ID,图书名称,图书价格,中间以空格相隔" << std::endl;
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
	//查询链表长度
	int length = 0;
	LinkedList iter1 = books;
	while (iter1 != nullptr)
	{
		length++;
		iter1 = iter1->next;
	}


	std::cout << "输入插入位置" << std::endl;
	std::cin>>count;
	if(length<count)
	   std::cout << "入库位置非法" << std::endl;
	else{
	std::cout << "请输入图书ID,图书名称,图书价格,中间以空格相隔" << std::endl;
	std::cin >> book.ID >> book.name >> book.price;
	int j=0;
	
	iter = books;
	//将book插入到指定位置	
	 while (iter != nullptr && (j<count-1))
	 {
		iter=iter->next;
		j++;
	 }
	
	LinkedNode *s =new LinkedNode;
	s->book=book;	
	s->next=iter->next;
	iter->next=s;
	//输出整个链表中book的内容
	}
}


/*
*@brief 出库操作
*/
void popBook(LinkedList& books){
   int count;
   std::cout << "输入删除位置" << std::endl;
   std::cin>>count;
   LinkedList iter = books;

   //查询链表长度
   int length = 0;
	LinkedList iter1 = books;
	while (iter1 != nullptr)
	{
		length++;
		iter1 = iter1->next;
	}
   
   if(length<count)
      std::cout << "出库位置非法" << std::endl;
   else{
   
   //将指定位置的book删除	
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
*@brief 逆序储存
*/
void reverseBookLink(LinkedList& books){

   //查询链表长度
   int length = 0;
	LinkedList iter1 = books;
	while (iter1 != nullptr)
	{
		length++;
		iter1 = iter1->next;
	}

   if(length<2)
      std::cout << "只有一个元素，逆序储存非法" << std::endl;
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

