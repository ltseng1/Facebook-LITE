all: main

FBLPost:	FBLPost.o
		g++ FBLPost.o -o FBLPost

FBLPost.o:	FBLPost.cpp FBLPost.h
		g++ -c FBLPost.cpp

FBLUser:	FBLUser.o
		g++ FBLUser.o -o FBLUser

FBLUser.o:	FBLUser.cpp FBLUser.h
		g++ -c FBLUser.cpp

FBLUserLL:	FBLUserLL.o
		g++ FBLUserLL.o -o FBLUserLL

FBLUserLL.o:	FBLUserLL.cpp FBLUserLL.h
		g++ -c FBLUserLL.cpp

FBLUserLLNode:	FBLUserLLNode.o
		g++ FBLUserLLNode.o -o FBLUserLLNode

FBLUserLLNode.o:	FBLUserLLNode.cpp FBLUserLLNode.h
		g++ -c FBLUserLLNode.cpp

FBLPostLL:	FBLPostLL.o
		g++ FBLPostLL.o -o FBLPostLL

FBLPostLL.o:	FBLPostLL.cpp FBLPostLL.h
		g++ -c FBLPostLL.cpp

FBLPostLLNode:	FBLPostLLNode.o
		g++ FBLPostLLNode.o -o FBLPostLLNode

FBLPostLLNode.o:	FBLPostLLNode.cpp FBLPostLLNode.h
		g++ -c FBLPostLLNode.cpp

FBLComment:	FBLComment.o
		g++ FBLComment.o -o FBLComment

FBLComment.o:	FBLComment.cpp FBLComment.h
		g++ -c FBLComment.cpp

FBLCommentNode:	FBLCommentNode.o
		g++ FBLCommentNode.o -o FBLCommentNode

FBLCommentNode.o:	FBLCommentNode.cpp FBLCommentNode.h
		g++ -c FBLCommentNode.cpp

FBLCommentLL: FBLCommentLL.o
		g++ FBLCommentLL.o -o FBLCommentLL

FBLCommentLL.o:	FBLCommentLL.cpp FBLCommentLL.h
		g++ -c FBLCommentLL.cpp




main: 	main.o FBLPost.o FBLUser.o FBLUserLL.o FBLUserLLNode.o FBLPostLL.o FBLPostLLNode.o FBLCommentLL.o FBLCommentNode.o FBLComment.o
	g++ main.o FBLPost.o FBLUser.o FBLUserLL.o FBLUserLLNode.o FBLPostLL.o FBLPostLLNode.o FBLCommentLL.o FBLCommentNode.o FBLComment.o -o main

clean:
	rm -f *.o

