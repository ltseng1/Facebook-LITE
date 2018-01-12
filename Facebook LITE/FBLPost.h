#include "FBLCommentLL.h"

class FBLPost {
	public:
		FBLPost *next;
		FBLCommentLL *commentList = new FBLCommentLL();
		void setText(string t);
		void setLikes(int l);
		int getLikes();
		string getText();
	private:
		int likes;
		string text;
		
};

