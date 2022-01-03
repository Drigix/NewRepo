#include "Tree.h"

template<class T>
Tree<T>::Tree()
{
	root = NULL;
}

template<class T>
Tree<T>::~Tree()
{
	//deleteTree(root);
	delete root;
}

template<class T>
Node<T>* Tree<T>::getRoot(T key)
{
	if (root==nullptr)
	{
		root = new Node<T>;
		root->setKey(key);
		root->setLeft(NULL);
		root->setRight(NULL);
		return root;
	}
	return root;
}

template<class T>
void Tree<T>::setRoot(Node<T>* leaf)
{
	root = leaf;
}

//Add
template<class T>
void Tree<T>::insert(T key, Node<T>& leaf)
{
	
	if (key < leaf.getKey())
	{
		if (leaf.getLeft() != NULL)
		{
			insert(key, *leaf.getLeft());
		}
		else
		{
			leaf.setLeft(new Node<T>);
			leaf.getLeft()->setKey(key);
			leaf.getLeft()->setLeft(NULL);
			leaf.getLeft()->setRight(NULL);
		}
	}
	else if (key >= leaf.getKey())
	{
		if (leaf.getRight() != NULL)
		{
			insert(key, *leaf.getRight());
		}
		else
		{
			leaf.setRight(new Node<T>);
			leaf.getRight()->setKey(key);
			leaf.getRight()->setLeft(NULL);
			leaf.getRight()->setRight(NULL);
		}
	}
		
}

//Delete
template<class T>
void Tree<T>::deleteTree(Node<T>* leaf)
{
	if (leaf != NULL)
	{
		Node<T>* temp = leaf;
		deleteTree(leaf->getLeft());
		deleteTree(leaf->getRight());
		delete temp;
	}
}

template<class T>
Node<T>* Tree<T>::findMininumValue(Node<T>*leaf)
{
	Node<T>* temp = leaf;
	while (temp && temp->getLeft() != NULL)
	{
		temp = temp->getLeft();
	}
	return temp;
}

template<class T>
void Tree<T>::deleteElement(T key, Node<T>* leaf)
{
	if (leaf == NULL)
	{
		cout << "ELEMENT NOT EXIST IN THIS TREE!" << endl;
	}
	else if (key < leaf->getKey())
	{
		deleteElement(key, leaf->getLeft());
	}
	else if (key > leaf->getKey())
	{
		deleteElement(key, leaf->getRight());
	}
	else
	{
		if (leaf->getLeft() == NULL && leaf->getRight() == NULL)
		{
			delete leaf;
			leaf = NULL;
		}
		else if (leaf->getLeft() == NULL)
		{
			Node<T>* temp = leaf;
			leaf = leaf->getRight();
			delete temp;
		}
		else if (leaf->getRight() == NULL)
		{
			Node<T>* temp = leaf;
			leaf = leaf->getLeft();
			delete temp;
		}
		else
		{
			Node<T>* temp = findMininumValue(leaf->getRight());
			leaf->setKey(temp->getKey());
			deleteElement(temp->getKey(), leaf->getRight());
			delete temp;
		}
	}
}

//Find
template<class T>
void Tree<T>::findElement(T key, Node<T>* leaf)
{
	if (leaf == NULL)
	{
		cout << "ELEMENT NOT EXIST!" << endl;
	}
	else if (key < leaf->getKey())
	{
		findElement(key, leaf->getLeft());
	}
	else if (key > leaf->getKey())
	{
		findElement(key, leaf->getRight());
	}
	else
	{
		cout << "ELEMENT YOU ARE LOOKING FOR:" << leaf->getKey() << endl;
	}
}

//Count
template<class T>
int Tree<T>::returnCountElements(Node<T>* leaf)
{
	if (leaf == NULL)
	{
		return 0;
	}
	else
	{
		int elements = 1;
		countElements(leaf, elements);
		return elements;
	}
}

template<class T>
int Tree<T>::countElements(Node<T>* leaf,int& elements)
{
	if (leaf != NULL)
	{
		if (leaf->getLeft() != NULL && leaf->getRight() != NULL)
		{
			elements += 2;
		}
		else if (leaf->getLeft() != NULL || leaf->getRight() != NULL)
		{
			elements++;
		}
		countElements(leaf->getLeft(), elements);
		countElements(leaf->getRight(), elements);
	}
	return elements;
}

template<class T>
int Tree<T>::returnCountLevels(Node<T>* leaf)
{
	if (leaf != NULL)
	{
		int levels_left = 1, levels_right = 1;

		if (countLevelsLeft(leaf->getLeft(), levels_left) >= countLevelsRight(leaf->getRight(), levels_right))
		{
			return levels_left;
		}
		else
		{
			return levels_right;
		}
	}
	else
	{
		return 0;
	}
}

template<class T>
int Tree<T>::countLevelsLeft(Node<T>* leaf, int& levels_left)
{
	if (leaf != NULL)
	{
		if (leaf->getLeft() != NULL || leaf->getRight() != NULL)
		{
			levels_left++;
		}
		countLevelsLeft(leaf->getLeft(), levels_left);
		countLevelsLeft(leaf->getRight(), levels_left);
	}
	return levels_left;
}

template<class T>
int Tree<T>::countLevelsRight(Node<T>* leaf, int& levels_right)
{
	if (leaf != NULL)
	{
		if (leaf->getLeft() != NULL || leaf->getRight() != NULL)
		{
			levels_right++;
		}
		countLevelsRight(leaf->getLeft(), levels_right);
		countLevelsRight(leaf->getRight(), levels_right);
	}
	return levels_right;
}