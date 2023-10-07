#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void createBookArray(BookArray& books)
{
	books.books = (Book*)malloc(sizeof(Book) * initSize);
	books.capacity = initSize;
	books.size = 0;
}

bool inflateArray(BookArray& books, size_t inflateSize)
{
	Book* temp = (Book*)realloc(books.books, (books.capacity + inflateSize) * sizeof(Book));
	if (temp)
	{
		books.books = temp;
		books.capacity += inflateSize;
		return true;
	}
	else
	{
		printf("ø’º‰≤ª◊„£¨∑÷≈‰ ß∞‹");
		return false;
	}
}
