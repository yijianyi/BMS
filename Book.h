#ifndef __BOOK_H__
#define __BOOK_H__
#include <string>

typedef struct book {
public:
	std::string ID;
	std::string name;
	double price;

	book(){}
	book(std::string ID, std::string name, double price)
	{
		this->ID = ID;
		this->name = name;
		this->price = price;
	}
}Book;
/*111111*/
#endif 
