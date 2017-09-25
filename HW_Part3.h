

#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

template <class Temp>
class Collection{

public:
	Collection(int size);
	bool isEmpty();
	void makeEmpty();
	void insert(Temp const& x);
	void remove(Temp x);
	void removeRandom();
	bool notContained(Temp x);
	void setSize(int x);
	void printArray();
private:
	Temp  * arrayObj;
	int CollSize = 0;


};
#endif;

