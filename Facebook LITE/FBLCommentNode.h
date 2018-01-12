#ifndef H_FBLCOMMENT_H
#define H_FBLCOMMENT_H
#include "FBLComment.h"

class FBLCommentNode {
	public:
		FBLComment data;
		FBLCommentNode *next;
		FBLCommentNode *prev;

		FBLCommentNode();
		FBLCommentNode(FBLComment val);
	private:
};
#endif
