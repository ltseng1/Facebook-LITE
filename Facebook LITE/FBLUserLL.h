#include "FBLUser.h"
#include "FBLUserLLNode.h"
class FBLUserLL {
	public:
		FBLUserLLNode *first;
		bool insert(FBLUser val);
		bool remove();
		bool userExists(string u);
		bool authenticateUser(string user, string pass);
		void sort();
		/*~FBLUserLL();*/
	private:
		
};

