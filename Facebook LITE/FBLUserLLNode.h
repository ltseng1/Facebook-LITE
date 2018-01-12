#ifndef H_FBLUSER_H
#define H_FBLUSER_H
#include "FBLUser.h"
#include <iostream>

class FBLUserLLNode {
	public:
		FBLUser data;
		FBLUserLLNode *next;
		//Constructors
		FBLUserLLNode();
		FBLUserLLNode(FBLUser val);
	private:
		

};
#endif
