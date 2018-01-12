
#include "FBLCommentLL.h"

bool FBLCommentLL::insert(FBLComment val) {
	FBLCommentNode *newNode = new FBLCommentNode(val);
	if (newNode == nullptr) {
		return false;
	}
	if (first == NULL) {
		first = newNode;
		first->prev = NULL;
		first->next = NULL;
	}
	else {
		newNode->prev = NULL;
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	return true;
}

bool FBLCommentLL::remove() {

}


