#ifndef H_FBLPOST_H
#define H_FBLPOST_H
#include "FBLPost.h"

class FBLPostLLNode {
	public:
		FBLPost data;
		FBLPostLLNode *next;
		//Constructors
		FBLPostLLNode();
		FBLPostLLNode(FBLPost val);
	private:
		

};
#endif
