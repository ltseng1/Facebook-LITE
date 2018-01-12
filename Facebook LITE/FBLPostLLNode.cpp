#include "FBLPostLLNode.h"

FBLPostLLNode::FBLPostLLNode() {
	next = nullptr;
}

FBLPostLLNode::FBLPostLLNode(FBLPost val) {
	data = val;
	next = nullptr;
}
