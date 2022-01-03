#ifndef _TREE_H_
#define _TREE_H_
#include <iostream>
#include"Node.h"

using namespace std;

template<class T>
class Tree
{
	Node<T>* root;
public:
	Tree();
	~Tree();
	void setRoot(Node<T>* leaf);
	Node<T>* getRoot(T key);
	//Add
	void insert(T key, Node<T>& leaf);
	//Delete
	void deleteTree(Node<T>* leaf);
	void deleteElement(T key,Node<T>*leaf);
	Node<T>* findMininumValue(Node<T>* leaf);
	//Find
	void findElement(T key, Node<T>* leaf);
	//Count
	int returnCountElements(Node<T>* leaf);
	int countElements(Node<T>* leaf,int& elements);
	int returnCountLevels(Node<T>*leaf);
	int countLevelsLeft(Node<T>*leaf,int&levels_left);
	int countLevelsRight(Node<T>* leaf, int& levels_right);
};


#endif