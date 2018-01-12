#ifndef H_FBLUser_H
#define H_FBLUser_H
#include "FBLPostLL.h"
#include <vector>


class FBLUser {
	public:
		FBLUser* next;
		FBLPostLL* userPosts = new FBLPostLL();
		void setUserID(string u);
		void setPassword(string p);
		void setFirstName(string f);
		void setLastName(string l);
		string getUserID();
		string getPassword();
		string getFirstName();
		string getLastName();
		vector<FBLUser*> friends;
		vector<FBLPost> feed;
		vector<FBLPost> wall;
		/*~FBLUser() {
                  std::cout << "Now entering FBLUserPostLL destructor" << std::endl;
                  delete userPosts;
                  std::cout << "Now leaving FBLUserPostLL destructor" << std::endl;};*/
		//Constructors
		FBLUser();
		FBLUser(string user, string pass, string first, string last);
		FBLUser(const FBLUser &fblu);
	private:
		
		string userID;
		string password;
		string firstName;
		string lastName;
		
};

#endif
