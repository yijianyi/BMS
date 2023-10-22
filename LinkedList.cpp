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
* @brief 根据图书价格降序排序（修改链表顺序）
* @param books 链表头结点
* @retval 无
*/
void sortBookLink(LinkedList& books)
{
	LinkedList head = books;
	LinkedNode* dummy = new LinkedNode();
	dummy->next = head;
	LinkedNode* tail = nullptr; // 维护遍历终点
	// 不断把大的值往右转移，遍历终点总是能变成最大值，再更新遍历终点
	while (tail != head) {
		LinkedNode* pre = dummy;
		LinkedNode* cur = pre->next;
		LinkedNode* nxt = cur->next;
		while (nxt != tail) {
			if (nxt->book.price > cur->book.price) { // 穿针引线交换节点
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
* brief 修改图书信息，将低于平均价格图书价格提高20%，大于等于图书价格提高10%
* param books 链表头结点
* retval 无
*/
void changeBook(LinkedList& books)
{
	LinkedList iter = books;
	//计算平均值
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

	//修改
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
	LinkedList iter = books;
	/*std::cin >> count;
	std::cout << "请输入图书ID,图书名称,图书价格,中间以空格相隔" << std::endl;
	
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
	int j=1;
	
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
*@brief 逆序储存
*/
void reverseBookLink(LinkedList& books){

	if (books == nullptr || books->next == nullptr) {
		return;
	}

	LinkedNode* prev = nullptr;   // 前一个节点指针
	LinkedNode* curr = books;      // 当前节点指针
	LinkedNode* next = nullptr;   // 下一个节点指针

	while (curr != nullptr) {
		next = curr->next;  // 保存当前节点的下一个节点

		// 反转当前节点指针指向前一个节点
		curr->next = prev;

		// 更新指针位置
		prev = curr;
		curr = next;
	}

	books = prev;
}

