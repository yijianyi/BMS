#include "LinkedList.h"
#include <iostream>

void outputBookLink(LinkedList& books)
{
	LinkedList iter = books;
	while (iter != nullptr)
	{
		
		iter = iter->next;
	}
}