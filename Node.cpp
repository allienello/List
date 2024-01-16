/**********************************************
 * Node.cpp
 **********************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Node.h"

/**********************************************
 * Constructor
 **********************************************/
node::node(string argf, string argl, int arga)
{
	first = argf;
	last = argl;
	age = arga;
	next = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
node::~node()
{
	if (next != NULL) delete next;
}

/*****************************
 * Put
 *****************************/
void node::put(ostream& out)
{
	out << left;
	out << setw(16) << last << setw(10) << first << setw(2) << age << endl;
}

/*****************************
 * Forwards
 *****************************/
void node::fore(ostream& out)
{
	put(out);

	if (next != NULL) next->fore(out);
}

/*****************************
 * Backwards
 *****************************/
void node::back(ostream& out)
{
	if (next != NULL) next->back(out);

	put(out);
}

 /*****************************
  * Equals
  *****************************/
bool node::operator == (const node& b)
{
	if (first == b.first && last == b.last)
		return true;
	else
		return false;
}

/*****************************
 * Lesser
 ******************************/
bool node::operator < (const node& b)
{
	if (last < b.last)
		return true;
	if (last == b.last)
	{
		if (first < b.first)
			return true;
		if (first == b.first)
		{
			if (age < b.age)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

/*****************************
 * Greater
 ******************************/
bool node::operator > (const node& b)
{
	if (last > b.last)
		return true;
	if (last == b.last)
	{
		if (first > b.first)
			return true;
		if (first == b.first)
		{
			if (age > b.age)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

