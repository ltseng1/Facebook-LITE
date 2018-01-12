#include "FBLUserLL.h"

bool FBLUserLL::insert(FBLUser val) {
	FBLUserLLNode *newNode = new FBLUserLLNode(val);
	if (newNode == nullptr) {
		return false;
	}
	newNode->next = first;
	first = newNode;
	return true;
};
bool FBLUserLL::remove() {
	if (first == nullptr) {
		return false;
	}
	FBLUserLLNode *tmp = first;
	first = first->next;
	delete tmp;
	return true;	
}
bool FBLUserLL::userExists(string u) {
	for (FBLUserLLNode *pos = first; pos != NULL; pos = pos->next) {
		
		if (pos->data.getUserID() == u) {
			return true;
		}
		
		else {
			
			
		}		
	}
	return false;
}
bool FBLUserLL::authenticateUser(string user, string pass) {
	FBLUserLLNode *pos = first;
	while (pos != NULL) {
		
		if (pos->data.getUserID() == user && pos->data.getPassword() == pass) {
			return true;
		}
		pos = pos->next;
	}
}

void FBLUserLL::sort() {
	FBLUserLLNode *i;
	FBLUserLLNode *j;
	FBLUserLLNode *min;
	FBLUser temp;
	if (first) {
		for (i = first; i->next != NULL; i = i->next) {
			min = i;
			for (j = min->next; j->next != NULL; j = j->next) {
				if (j->data.getLastName() < min->data.getLastName()) {
					min = j;
				}
			}
			temp = min->data;
			min->data = i->data;
			i->data = temp;
			
		}
	}
}
/*FBLUserLL::~FBLUserLL() {
	cout << "Now entering FBLUserLL destructor" << endl;

	while (first != NULL) {
		FBLUserLLNode *next;
		FBLUserLLNode * tmp = first;
		if (tmp != NULL) {
			next = tmp->next;
			delete tmp;
			tmp = next;
			
		}
		first = next;
	}

        FBLUserLLNode *curr_node = first;
        while(curr_node != NULL)
        {
          FBLUserLLNode *tmp = curr_node -> next;
          delete curr_node;
          curr_node = tmp;
        }
       
	cout << "Now leaving FBLUserLL destructor" << endl;
}*/
