/**********************************************
 * List.cpp
 **********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "List.h"

/**********************************************
 * Constructor
 **********************************************/
list::list()
{
	head = NULL;
	len = 0;
}

/**********************************************
* Destructor
**********************************************/
list::~list()
{
	if (head != NULL) delete head;
}

/**********************************************
* Insert
**********************************************/
void list::insert(string f, string l, int a)
{
	node* temp = new node();
	temp->first = f;
	temp->last = l;
	temp->age = a;
	temp->next = NULL;

	node* temp2 = head;
	node* temp3 = NULL;

	while (temp2 != NULL && *temp > *temp2)
	{
		temp3 = temp2;
		temp2 = temp2->next;
	}

	if (temp2 == head)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		temp->next = temp2;
		temp3->next = temp;
	}

	len ++;
}

/**********************************************
* Find
**********************************************/
node* list::find(string f, string l)
{
	node* current = head;
	while (current != NULL)
	{
		if (current->first == f && current->last == l)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

/**********************************************
* Remove
**********************************************/
bool list::remove(string f, string l)
{

	if (head == NULL) return false;
	else
	{
		node* temp = head;
		node* next = temp->next;
		len--;
		if (temp != NULL &&(temp->first == f && temp->last == l))
		{
			head = temp->next;
			temp->next = NULL;

			return true;
		}
		
		while (next != NULL)
		{
			if (next->first == f && next->last == l)
			{
				temp->next = next->next;
				next->next = NULL;
				return true;
			}
			temp = next;
			next = next->next;

		}

		return false;
	}
}

/**********************************************
* Forwards
**********************************************/
void list::forwards(ostream& out)
{
	if (head != NULL) head->fore(out);
}

/**********************************************
* Backwards
**********************************************/
void list::backwards(ostream& out)
{
	if (head != NULL) head->back(out);
}

/**********************************************
* Length
**********************************************/
int list::length()
{
	return len;
}