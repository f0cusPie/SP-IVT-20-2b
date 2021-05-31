#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class VNode
{
public:
	VNode* left;
	VNode* right;
	VNode* parent;
	T data;

	VNode(VNode* root, T element)
	{
		parent = root;
		left = nullptr;
		right = nullptr;
		data = element;
	}

	VNode(VNode* root, T* element)
	{
		parent = root;
		left = nullptr;
		right = nullptr;
		data = *element;
	}
};

template <typename T>
class VTree
{
private:
	VNode<T>* _root;
	int _size;

public:
	// constructors
	VTree(unsigned int size = 0)
	{
		Delete();
		for (int i = 0; i < size; i++)
		{
			Insert(0);
		}
	}

	VTree(vector<T> vec)
	{
		Delete();
		for (int i = 0; i < vec.size(); i++)
		{
			Insert(vec[i]);
		}
	}

	// change tree
	void Insert(T element)
	{
		if (_root == nullptr)
		{
			_root = new VNode<T>(nullptr, element);
			_size = 1;
		}
		else
		{
			VNode<T>* ptr = _root;
			while (true)
			{
				if (element < ptr->data)
				{
					if (ptr->left == nullptr)
					{
						VNode<T>* t = new VNode<T>(ptr, element);
						ptr->left = t;
						_size++;
						return;
					}
					else
					{
						ptr = ptr->left;
					}
				}
				else
				{
					if (ptr->right == nullptr)
					{
						VNode<T>* t = new VNode<T>(ptr, element);
						ptr->right = t;
						_size++;
						return;
					}
					else
					{
						ptr = ptr->right;
					}
				}
			}
		}
	}

	void Delete()
	{
		Delete_R(_root);
		_root = nullptr;
	}

	// change format
	void ToBalancedTree()
	{
		vector<T> vec = ToVector();
		Delete();
		if (vec.size() > 0)
		{
			_root = new VNode<T>(nullptr, vec[0]);
			vec.erase(vec.begin());
			_size++;
			InsertBalanced_R(&vec, _root, CountDeep(vec.size() + 1) - 1);
		}
	}

	void ToSearchTree()
	{
		vector<T> vec = ToVector();
		Delete();
		for (int i = 0; i < vec.size(); i++)
		{
			Insert(vec[i]);
		}
	}

	// get information
	int Size()
	{
		return _size;
	}

	T Min()
	{
		if (_root != nullptr)
		{
			ToSearchTree();
			VNode<T>* ptr = _root;
			while (ptr->left != nullptr)
			{
				ptr = ptr->left;
			}
			return ptr->data;
		}
		return INT16_MAX;
	}

	string ToString()
	{
		return CreateString_R(_root);
	}

	vector<T> ToVector()
	{
		return ToVector_R(_root);
	}

private:
	// change tree
	void Delete_R(VNode<T>* cur)
	{
		if (cur != nullptr)
		{
			Delete_R(cur->left);
			Delete_R(cur->right);
			cur->left = nullptr;
			cur->right = nullptr;
			cur->parent = nullptr;
			delete cur;
			cur = nullptr;
			_size--;
		}
	}

	// change format
	// to balanced tree
	int Sum(int n)
	{
		int res = 0;
		for (int i = 0; i <= n; i++)
		{
			res += i;
		}
		return res;
	}

	int CountDeep(int n)
	{
		int res = 0;
		while (Sum(res) < n) res++;
		return res;
	}

	void InsertBalanced_R(vector<T>* vec, VNode<T>* parent, int deep)
	{
		if (deep > 0 && vec->size() > 0)
		{
			if (vec->size() > 0)
			{
				parent->left = new VNode<T>(parent, *vec->begin());
				vec->erase(vec->begin());
				_size++;
				InsertBalanced_R(vec, parent->left, deep - 1);
			}
			if (vec->size() > 0)
			{
				parent->right = new VNode<T>(parent, *vec->begin());
				vec->erase(vec->begin());
				_size++;
				InsertBalanced_R(vec, parent->right, deep - 1);
			}
		}
	}

	// get information
	string CreateString_R(VNode<T>* cur)
	{
		string res;
		if (cur != nullptr)
		{
			res += to_string(cur->data);
			res += "[";
			if (cur->left != nullptr)
			{
				res += "l(";
				res += CreateString_R(cur->left);
				res += ")";
			}
			if (cur->right != nullptr)
			{
				res += "r(";
				res += CreateString_R(cur->right);
				res += ")";
			}
			res += "]";
			res += ",";
		}
		return res;
	}

	vector<T> ToVector_R(VNode<T>* cur)
	{
		vector<T> res;

		if (cur != nullptr)
		{
			res.push_back(cur->data);

			// take elements from left branch
			vector<T> fromBranch = ToVector_R(cur->left);
			for (int i = 0; i < fromBranch.size(); i++)
			{
				res.push_back(fromBranch[i]);
			}

			// take elements from right branch
			fromBranch = ToVector_R(cur->right);
			for (int i = 0; i < fromBranch.size(); i++)
			{
				res.push_back(fromBranch[i]);
			}
		}

		return res;
	}
}; 
