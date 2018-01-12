#ifndef H_FBLComment_H
#define H_FBLComment_H
#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;
class FBLComment {
	public:
		FBLComment *next;
		void setComment(string t);
		string getComment();
		string getFirstName();
		string getLastName();
		void setFirstName(string f);
		void setLastName(string l);
	private:
		string text;
		string firstName;
		string lastName;
};
#endif
