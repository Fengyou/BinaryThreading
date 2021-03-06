#include<iostream>

using namespace std;

enum PointerTag{THREAD, LINK};

template<class T>
struct BinaryTreeThdNode
{
	T _data;
	BinaryTreeThdNode<T>* _left;
	BinaryTreeThdNode<T>* _right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	BinaryTreeThdNode(const T& data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{}
};

template<class T>
class BinaryTreeThd
{
public:
	BinaryTreeThd(const T* array, int size)
	:_root(NULL)
	{
		int index = 0;
		_CreateTree(_root, array, size, index);
	}

	void InOrderThreading()
	{
		BinaryTreeThdNode<T>* prev = NULL;
		_InOrderThreading(_root, prev);
	}

	void PrevOrderThreading()
	{
		BinaryTreeThdNode<T>* prev = NULL;
		_PrevOrderThreading(_root, prev);
	}

	void InThreadOrder()
	{
		BinaryTreeThdNode<T>* cur = _root;

		while (cur)
		{
			while (cur && cur->_leftTag != THREAD)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";

			if (cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}

			if (cur)
			{
				cur = cur->_right;
			}
		}
	}
protected:
	void _CreateTree(BinaryTreeThdNode<T>*& root, const T* array, int size, int& index)
	{
		if (index < size && array[index] != '#')
		{
			root = new BinaryTreeThdNode<T>(array[index]);
			_CreateTree(root->_left, array, size, index++);
			_CreateTree(root->_right, array, size, index++);
		}
	}
	void _InOrderThreading(BinaryTreeThdNode<T>* cur, BinaryTreeThdNode<T>* prev)
	{
		if (cur)
		{
			_InOrderThreading(cur->_left, prev);
			
			//ÏßË÷»¯×óÇ°Çý
			if (cur->_left == NULL)
			{
				cur->_leftTag = THREAD;
				cur->_left = prev;
			}
			
			//ÏßË÷»¯ÓÒºó¼Ì
			if (prev && prev->_right == NULL)
			{
				prev->_rightTag = THREAD;
				prev->_right = cur;
			}
			prev = cur;

			_InOrderThreading(cur->_right, prev);
		}
	}

	void _PrevOrderThreading(BinaryTreeThdNode<T>* cur, BinaryTreeThdNode<T>* prev)
	{
		if (cur)
		{
			if (cur->_left == NULL)
			{
				cur->_leftTag = THREAD;
				cur->_left = prev;
			}

			if (prev && prev->_right == NULL)
			{
				prev->_rightTag = THREAD;
				prev->_right = cur;
			}

			prev = cur;
			if (cur->_leftTag == LINK)
			{
				_PrevOrderThreading(cur->_left, prev);
			}
			if (cur->_rightTag == LINK)
			{
				_PrevOrderThreading(cur->_right, prev);
			}
		}
	}

private:
	BinaryTreeThdNode<T>* _root;
};
	
