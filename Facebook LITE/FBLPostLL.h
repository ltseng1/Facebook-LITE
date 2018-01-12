#ifndef H_FBLPostLL_H
#define H_FBLPostLL_H
#include "FBLPostLLNode.h"


class FBLPostLL {
	public:
		FBLPostLLNode *first;
		FBLPostLLNode *last;
		bool insert(FBLPost val);
		bool remove();
		~FBLPostLL();
	private:

};
#endif

