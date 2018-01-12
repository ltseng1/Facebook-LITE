#include "FBLCommentNode.h"

FBLCommentNode::FBLCommentNode() {
	next = nullptr;
	prev = nullptr;
}

FBLCommentNode::FBLCommentNode(FBLComment val) {
	data = val;
	prev = nullptr;	
	next = nullptr;
}
