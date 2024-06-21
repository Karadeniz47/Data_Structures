tum: derleme calistirma

derleme:
	g++ -I ./inc/ -o ./lib/AVLTreeNode.o -c ./src/AVLTreeNode.cpp
	g++ -I ./inc/ -o ./lib/AVLTree.o -c ./src/AVLTree.cpp
	g++ -I ./inc/ -o ./lib/AVLTrees.o -c ./src/AVLTrees.cpp
	g++ -I ./inc/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./inc/ -o ./bin/test ./lib/AVLTreeNode.o ./lib/AVLTree.o ./lib/AVLTrees.o ./lib/Stack.o ./src/test.cpp

calistirma:
	./bin/test