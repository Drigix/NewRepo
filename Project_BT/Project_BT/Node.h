#pragma once
#include<iostream>
template<class T>
class Node
{
private:
	T key;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
public:
	Node(Node<T>* _parent) : parent(_parent) {}
	~Node()
	{
		if (left != nullptr)
		{
			delete left;
			left = nullptr;
		}
		if (right != nullptr)
		{
			delete right;
			right = nullptr;
		}
	}
	Node<T>* getLeft()
	{
		return left;
	}
	Node<T>* getRight()
	{
		return right;
	}
	Node<T>* getParent() {
		return parent;
	}
	void clear() {
		right = NULL;
		left = NULL;
	}
	void setLeft(Node<T>* leaf)
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

