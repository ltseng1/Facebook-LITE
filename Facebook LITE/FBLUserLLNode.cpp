#include "FBLUserLLNode.h"

FBLUserLLNode::FBLUserLLNode() {
	next = nullptr;
}

FBLUserLLNode::FBLUserLLNode(FBLUser val) {
	data = val;
	next = nullptr;
}
