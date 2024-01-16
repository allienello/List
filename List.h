/**************************************
 * Header - List.h
 * Written by Allie Ianello
 **************************************/
#include "Node.h"
//#define LIST_MAX 

class list
{
public:
	list();
	~list();
	void insert(string f, string l, int a);
	node* find(string f, string l);
	bool remove(string f, string l);
	void forwards(ostream & out);
	void backwards(ostream & out);
	int length();
private:
	node* head;
	int len;

};