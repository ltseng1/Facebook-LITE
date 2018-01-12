#include "FBLUser.h"
#include "FBLUserLL.h"
#include "FBLPostLL.h"
#include "FBLCommentLL.h"
#include "FBLComment.h"



int main(int argc, char *argv[]) {
	string cmd;
	string userIn;
	string friendIn;
	string passwordIn;
	string firstIn;
	string lastIn;
	string text;
	string comment;
	FBLUser user;
	FBLUserLL* userList = new FBLUserLL();

	bool inFirstMenu = true;
	while (inFirstMenu == true) {
		cout << endl;
		cout << "Enter a command from: " << endl;
		cout << "CREATE <Userid> <Password> <First> <Last>" << endl;
		cout << "USERS" << endl;
		cout << "SORTUSERS" << endl;
		cout << "LOGIN <Userid> <Password>" << endl;
		cout << "QUIT" << endl; 
		getline(cin, cmd);
		stringstream str(cmd);
		str >> cmd;
		if (cmd == "CREATE") {
			str >> userIn;
			if (userList->userExists(userIn) == false) {
				FBLUser *tmp = new FBLUser();
				str >> passwordIn;
				str >> firstIn;
				str >> lastIn;
				tmp->setUserID(userIn);
				tmp->setPassword(passwordIn);
				tmp->setFirstName(firstIn);
				tmp->setLastName(lastIn);
				userList->insert(*tmp);
				delete tmp;
			}
			else {
				cout << "User already exists" << endl;
			}
		}
		else if (cmd == "LOGIN") {
			str >> userIn;
			str >> passwordIn;
			
			if (userList->authenticateUser(userIn, passwordIn) == true) {
				FBLUserLLNode *pos = userList->first;
				while (pos != NULL) {
					if (pos->data.getUserID() == userIn) {
						cout << "LOGGED IN TO " << pos->data.getUserID() << endl;
						user = pos->data;
						break;
					}
					pos = pos->next;
				}
				bool inSecondMenu = true;
				while (inSecondMenu == true) {
					cout << endl;
					cout << "Enter a command from: " << endl;
					cout << "LOGOUT" << endl;
					cout << "POST <text>" << endl;
					cout << "READ" << endl;
					cout << "FRIEND <userid>" << endl;
					cout << "MYFEED" << endl;
					cout << "MYWALL" << endl;
					getline(cin, cmd);
					stringstream str(cmd);
					str >> cmd;
					if (cmd == "LOGOUT") {
						inSecondMenu = false;
					}
					else if (cmd == "POST") {
						getline(str, text);
						FBLPost post;
						post.setText(text);
						
						for (FBLUserLLNode *pos = userList->first; pos != NULL; pos = pos->next) {
							if (pos->data.getUserID() == user.getUserID()) {
								pos->data.userPosts->insert(post);
								pos->data.wall.push_back(post);
								for (int i = 0; i < pos->data.friends.size(); i++) {
									pos->data.friends[i]->feed.push_back(post);
									
								}
								break;
							}
		
							else {
								
							}		
						}
						
					}
					else if (cmd == "READ") {
						
						for (FBLUserLLNode *pos = userList->first; pos != NULL; pos = pos->next) {
							if (pos->data.getUserID() == user.getUserID()) {
								//FBLPostLLNode *postPos = pos->data.userPosts->first;
								if (pos->data.feed.size() != 0) {
									//cout << postPos->data.getText() << endl;
									cout << pos->data.feed[pos->data.feed.size() - 1].getText() << endl;
									bool inThirdMenu = true;
									while (inThirdMenu == true) {
										cout << endl;
										cout << "Enter a command from: " << endl;
										cout << "LIKE" << endl;
										cout << "COMMENT <text>" << endl;
										cout << "READ_AZ" << endl;
										cout << "READ_ZA" << endl;
										cout << "DONE" << endl;
										getline(cin, cmd);
										stringstream str(cmd);
										str >> cmd;
										if (cmd == "LIKE") {
											/*pos->data.userPosts->first->data.giveLike();
											for (int i = 0; i < pos->data.wall.size(); i++) {
												if (pos->data.wall[i].getText() == pos->data.userPosts->first->data.getText()) {
													pos->data.wall[i].giveLike();
													break;
												}
											}*/
											for (FBLUserLLNode *posAuthor = userList->first; posAuthor != NULL; posAuthor = posAuthor->next) {
												for (int i = 0; i < posAuthor->data.wall.size(); i++) {
													if (posAuthor->data.wall[i].getText() == pos->data.feed[pos->data.feed.size() - 1].getText()) {
														posAuthor->data.wall[i].setLikes(1);
														break;
													}
												}
											}
											//pos->data.feed[pos->data.feed.size() - 1].setLikes(1);
															
										}
										if (cmd == "COMMENT") {
											getline(str, comment);
											FBLComment userComment;
											userComment.setComment(comment);
											for (FBLUserLLNode *posAuthor = userList->first; posAuthor != NULL; posAuthor = posAuthor->next) {
												for (int i = 0; i < posAuthor->data.wall.size(); i++) {
													if (posAuthor->data.wall[i].getText() == pos->data.feed[pos->data.feed.size() - 1].getText()) {
														posAuthor->data.wall[i].commentList->insert(userComment);
														break;
													}
												}
											}
											//pos->data.userPosts->first->data.commentList->insert(userComment);
											//pos->data.feed[pos->data.feed.size() - 1].commentList->insert(userComment);
											//cout << pos->data.feed[pos->data.feed.size() - 1].commentList->first->data.getComment();
										}
										if (cmd == "READ_AZ") {
											FBLCommentNode *lastPos = pos->data.feed[pos->data.feed.size()-1].commentList->first;
											while (lastPos->next != NULL) {
												lastPos = lastPos->next;
											}
											
											for (FBLCommentNode *comPos = lastPos; comPos != NULL; comPos = comPos->prev) {
												cout << comPos->data.getComment() << endl;
											}
										}
										if (cmd == "READ_ZA") {
											for (FBLCommentNode *comPos = pos->data.feed[pos->data.feed.size()-1].commentList->first; comPos != NULL; comPos = comPos->next) {
												cout << comPos->data.getComment() << endl;
											}
										}
										if (cmd == "DONE") {
											
											break;
										}
									}
									// Remove post from feed
									/*FBLUserLLNode *posFriends = userList->first;
									while (posFriends != NULL) {
							
										for (int i = 0; i < pos->data.friends.size(); i++) {
											if (posFriends->data.getUserID() == pos->data.friends[i]->getUserID()) {
												if (pos->data.friends[i]->feed.size() != 0) {
													pos->data.friends[i]->feed.pop_back();
													
												}
											}
										}
										posFriends = posFriends->next;
									}*/
									pos->data.feed.pop_back();
									//pos->data.userPosts->remove();
									//postPos = postPos->next;
								}
								else {
									cout << "Nothing to READ" << endl;
								
								}
							
							}
							else {
								
							}
									
						}
						
						
					}
					else if (cmd == "FRIEND") {
						str >> friendIn;
						if (userList->userExists(friendIn) == true) {
							if (user.friends.size() != 0) {
								for (int i = 0; i < user.friends.size(); i++) {
									
									if (friendIn == user.getUserID() || friendIn == user.friends[i]->getUserID()) {
										cout << friendIn << " is already friends with you / you cannnot add yourself" << endl;
										break;
									}
									else {
										FBLUserLLNode *pos = userList->first;
										while (pos != NULL) {
											if (pos->data.getUserID() == friendIn) {
												FBLUserLLNode *posUser = userList->first;
												while (posUser != NULL) {
													if (posUser->data.getUserID() == user.getUserID()) {
														FBLUser *tmp = &(pos->data);
														posUser->data.friends.push_back(&(pos->data));
														tmp->friends.push_back(&(posUser->data));
														/*user.friends.push_back(new FBLUser(pos->data));
														pos->data.friends.push_back(new FBLUser(user));*/
														cout << "Added friend!" << endl;
														cout << "You now have this many friends: " << posUser->data.friends.size() << endl;
														break;
													}
													posUser = posUser->next;
												}
											}
								
											pos = pos->next;
										}
									}
								}
							}
							else {
								FBLUserLLNode *pos = userList->first;
								while (pos != NULL) {
									if (pos->data.getUserID() == friendIn) {
										FBLUserLLNode *posUser = userList->first;
										while (pos != NULL) {
											if (posUser->data.getUserID() == user.getUserID()) {
												FBLUser *tmp = &(pos->data);
												posUser->data.friends.push_back(&(pos->data));
												tmp->friends.push_back(&(posUser->data));
												/*user.friends.push_back(new FBLUser(pos->data));
												pos->data.friends.push_back(new FBLUser(user));*/
												cout << "Added friend!" << endl;
												cout << "You now have this many friends: " << posUser->data.friends.size() << endl;
												break;
											}
											posUser = posUser->next;
										}
							
									}
						
									pos = pos->next;
								}
							}
						}
						
						else {
							cout << "User does not exist" << endl;
						}
					}
					else if (cmd == "MYFRIENDS") {
						FBLUserLLNode *pos = userList->first;
						while (pos != NULL) {
							if (pos->data.getUserID() == user.getUserID()) {
								if (pos->data.friends.size() != 0) {
									for (int i = 0; i < pos->data.friends.size(); i++) {
							
										cout << pos->data.friends[i]->getFirstName() << " " << pos->data.friends[i]->getLastName() << endl;
									}
								}
								else {
									cout << "You have no friends" << endl;
								}
							}
							pos = pos->next;
						}
					

					}
					else if (cmd == "MYFEED") {
						
						FBLUserLLNode *pos = userList->first;
						while(pos != NULL) {
							
							if (pos->data.getUserID() == user.getUserID()) {
								
								for (int i = 0; i < pos->data.feed.size(); i++) {
								
									cout << pos->data.feed[i].getText() << endl;
								}
								cout << "End of feed" << endl;
								
							}
							pos = pos->next;		
						}
						
					}
					else if (cmd == "MYWALL") {
						FBLUserLLNode *pos = userList->first;
						while (pos != NULL) {
							if (pos->data.getUserID() == user.getUserID()) {
								for (int i = 0; i < pos->data.wall.size(); i++) {
									cout << "Likes: " << pos->data.wall[i].getLikes() << pos->data.wall[i].getText() << endl;
								}
								/*FBLPostLLNode *postPos = pos->data.userPosts->first;
								while (postPos != NULL) {
									cout << postPos->data.getText() << endl;
									postPos = postPos->next;
								}*/
							}
							pos = pos->next;
						}
						
					}
					else {
						cout << "Please enter a valid command" << endl;
					}
				}
			}
			else {
				cout << "User not found/Password is wrong" << endl;
			}
		
		}
		else if (cmd == "USERS") {
			for (FBLUserLLNode *pos = userList->first; pos != NULL; pos = pos->next) {
				cout << pos->data.getLastName() << ", " << pos->data.getFirstName() << " <" << pos->data.getUserID() << ">" << endl;
			}
		}
		else if (cmd == "SORTUSERS") {
			int listSize = 0;
			for (FBLUserLLNode *pos = userList->first; pos != NULL; pos = pos->next) {
				listSize++;
			}
			if (listSize == 0) {
				cout << "No users in list to sort" << endl;
				
			}
			else {
				userList->sort();
			}
		}
		else if (cmd == "QUIT") {
			/*delete userList;*/
			break;
		}
		else {
			cout << "Enter a valid command" << endl;
		}
	}
	
	
}
