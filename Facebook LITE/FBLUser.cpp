#include "FBLUser.h"
FBLUser::FBLUser() {

}
FBLUser::FBLUser(string user, string pass, string first, string last) {
	userID = user;
	password = pass;
	firstName = first;
	lastName = last;
}
FBLUser::FBLUser(const FBLUser &fblu) {
	this->userID = fblu.userID;
	this->password = fblu.password;
	this->firstName = fblu.firstName;
	this->lastName = fblu.lastName;

	this->next = fblu.next;
	this->userPosts = fblu.userPosts;
	this->friends = fblu.friends;
	this->feed = fblu.feed;
}
void FBLUser::setUserID(string u){
	userID = u;
}
void FBLUser::setPassword(string p){
	password = p;
}
void FBLUser::setFirstName(string f){
	firstName = f;
}
void FBLUser::setLastName(string l){
	lastName = l;
}
string FBLUser::getUserID() {
	return userID;
}
string FBLUser::getPassword() {
	return password;
}
string FBLUser::getFirstName() {
	return firstName;
}
string FBLUser::getLastName() {
	return lastName;
}

