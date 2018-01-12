#ifndef H_FBLCommentNode_H
#define H_FBLCommentNode_H
#include "FBLCommentNode.h"

class FBLCommentLL {
	public:
		FBLCommentNode *first = NULL;
		bool insert(FBLComment val);
		bool remove();
		~FBLCommentLL();
	private:

};
#endif

