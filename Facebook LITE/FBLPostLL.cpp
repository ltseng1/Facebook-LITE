#include "FBLPostLL.h"

bool FBLPostLL::insert(FBLPost val) {
	FBLPostLLNode *newNode = new FBLPostLLNode(val);
	if (newNode == nullptr) {
		return false;
	}
	newNode->next = first;
	first = newNode;
	return true;
};
bool FBLPostLL::remove() {
	if (first == nullptr) {
		return false;
	}
	FBLPostLLNode *tmp = first;
	first = first->next;
	delete tmp;
	return true;	
}

/*FBLPostLL::~FBLPostLL() {
	cout << "Now entering FBLPostLL destructor" << endl;

	while (first != NULL) {
		FBLPostLLNode *next;
		FBLPostLLNode * tmp = first;
		if (tmp != NULL) {
			next = tmp->next;
			delete tmp;
			tmp = next;
		}
		first = next;
	}

        FBLPostLLNode * curr_node = first;
        while(curr_node != NULL)
        {
          FBLPostLLNode * tmp = curr_node -> next;
          delete curr_node;
          curr_node = tmp;
        }

	cout << "Now leaving FBLPostLL destructor" << endl;
}*/
