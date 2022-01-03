#pragma once
#include<iostream>
template<class T>
class Node
{
private:
	T key;
	Node<T>* left;
	Node<T>* right;
public:
	~Node()
	{
		std::cout << key << std::endl;
		if (left != nullptr)
		{
			delete left;
		}
		if (right != nullptr)
		{
			delete right;
		}
		left = nullptr;
		right = nullptr;
	}
	Node<T>* getLeft()
	{
		return left;
	}
	Node<T>* getRight()
	{
		return right;
	}
	void setLeft(Node<T>*leaf)
	{
		left = leaf;
	}
	void setRight(Node<T>* leaf)
	{
		right = leaf;
	}
	T getKey()
	{
		return key;
	}
	void setKey(T key)
	{
		this->key = key;
	}
};

