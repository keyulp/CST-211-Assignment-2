/**************************************************************
*	Author: Keyul Patel
* Date Created:			10/09/15
* Last Modification Date:	10/12/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Exception.h
*
*
*			Overview: Header for the Functions used in the Exception.cpp file
*
*			Input: A string
*
*			Output: None
****************************************************************/

#include <iostream>

using namespace std;

class Exception
{
	friend ostream &operator<<(ostream &out, const Exception &thing);

public:
	Exception();
	Exception(const char *msg);
	~Exception();

	Exception &operator=(const Exception &rhs);

	char getMessage() const;
	void setMessage(const char *msg);
	

private:
	char *m_msg;
};

