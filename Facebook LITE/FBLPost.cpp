#include "FBLPost.h"

void FBLPost::setText(string t) {
	text = t;
}
void FBLPost::setLikes(int l) {
	likes += l;
}
int FBLPost::getLikes() {
	return likes;
}
string FBLPost::getText() {
	return text;
}
