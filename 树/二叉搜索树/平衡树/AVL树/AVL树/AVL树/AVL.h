
//AVL.h中有模板类，若main函数中只包含了AVL.h，而没有包含AVL.cpp，那么编译器无法根据模板类生成相应的代码，因此会报错。
//解决方法：将AVL.h和AVL.cpp放在一起，或者在main函数中包含AVL.cpp
//这里采用将AVL.h和AVL.cpp放在一起的方法
#pragma once
#include <iostream>
#include <cmath>
using namespace std;

//AVL树
//AVL树是一种自平衡二叉查找树，它的每个节点的左子树和右子树的高度差至多为1
//AVL树的高度为O(logn)
//AVL树的插入和删除操作会导致树的高度发生变化，因此需要对树进行平衡操作
//平衡操作包括左旋、右旋、左右旋、右左旋
//平衡操作的时间复杂度为O(1)
//AVL树的插入和删除操作的时间复杂度为O(logn)
//AVL树的查找操作的时间复杂度为O(logn)


#define INF 2147483647
//AVL树的节点
template<class T>
class AVLNode
{
public:
	T key; //节点的关键字
	int height; //节点的高度
	AVLNode* left; //节点的左孩子
	AVLNode* right; //节点的右孩子
    AVLNode(T k) :key(k),left(nullptr),right(nullptr),height(1){}//构造函数
	AVLNode(T k, AVLNode* l, AVLNode* r) :key(k), left(l), right(r), height(1) {}//构造函数
};

//AVL树
template<class T>
class AVL
{
public:
    AVL();
    ~AVL();

    // 获取树的高度
    int height();

    // 前序遍历"AVL树"
    void preOrder();
    // 中序遍历"AVL树"
    void inOrder();
    // 后序遍历"AVL树"
    void postOrder();

	int predecessor(T key);//查找前驱

	int successor(T key);//查找后继

    // (递归实现)查找"AVL树"中键值为key的节点
    AVLNode<T>* search(T key);
    // (非递归实现)查找"AVL树"中键值为key的节点
    AVLNode<T>* iterativeSearch(T key);

    // 查找最小结点：返回最小结点的键值。
    T minimum();
    // 查找最大结点：返回最大结点的键值。
    T maximum();

    // 将结点(key为节点键值)插入到AVL树中
    void insert(T key);

    // 删除结点(key为节点键值)
    void remove(T key);

    // 销毁AVL树
    void destroy();

    // 打印AVL树
    void print();
private:
	AVLNode<T>* root;//根节点
    // 获取树的高度
    int height(AVLNode<T>* tree);

    // 前序遍历"AVL树"
    void preOrder(AVLNode<T>* tree) const;
    // 中序遍历"AVL树"
    void inOrder(AVLNode<T>* tree) const;
    // 后序遍历"AVL树"
    void postOrder(AVLNode<T>* tree) const;

	AVLNode<T>* predecessor(AVLNode<T>* tree, T key);//查找前驱

	AVLNode<T>* successor(AVLNode<T>* tree, T key);//查找后继

    // (递归实现)查找"AVL树x"中键值为key的节点
    AVLNode<T>* search(AVLNode<T>* x, T key) const;
    // (非递归实现)查找"AVL树x"中键值为key的节点
    AVLNode<T>* iterativeSearch(AVLNode<T>* x, T key) const;

    // 查找最小结点：返回tree为根结点的AVL树的最小结点。
    AVLNode<T>* minimum(AVLNode<T>* tree);
    // 查找最大结点：返回tree为根结点的AVL树的最大结点。
    AVLNode<T>* maximum(AVLNode<T>* tree);

    // LL：左左对应的情况(右旋)。
    AVLNode<T>* RightRotation(AVLNode<T>* k2);

    // RR：右右对应的情况(左旋)。
    AVLNode<T>* LeftRotation(AVLNode<T>* k1);

    // LR：左右对应的情况(左右旋)。
    AVLNode<T>* LeftRightRotation(AVLNode<T>* k3);

    // RL：右左对应的情况(右左旋)。
    AVLNode<T>* RightLeftRotation(AVLNode<T>* k1);

    // 将结点插入到AVL树(tree)中
    AVLNode<T>* insert(AVLNode<T>*& tree, T key);

    // 删除AVL树(tree)中的结点，并返回被删除的结点
    AVLNode<T>* remove(AVLNode<T>*& tree, AVLNode<T>* z);

    // 销毁AVL树
    void destroy(AVLNode<T>*& tree);

    // 打印AVL树
    void print(AVLNode<T>* tree, T key, int direction);
};


//AVL树的构造函数
template<class T>
AVL<T>::AVL()
{
	root = NULL;
}

//AVL树的析构函数
template<class T>
AVL<T>::~AVL()
{
	//cout<<"调用析构函数"<<endl;
	destroy(root);
}

//获取树高度
template<class T>
int AVL<T>::height(AVLNode<T>* tree)
{
	return tree == NULL ? 0 : tree->height;
}

template<class T>
int AVL<T>::height()
{
	return height(root);
}

//旋转
//右旋(LL)
template<class T>
AVLNode<T>* AVL<T>::RightRotation(AVLNode<T>* k2)
{
	AVLNode<T>* k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}
//左旋(RR)
template<class T>
AVLNode<T>* AVL<T>::LeftRotation(AVLNode<T>* k1)
{
	AVLNode<T>* k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	return k2;
}
//左右旋(LR)
template<class T>
AVLNode<T>* AVL<T>::LeftRightRotation(AVLNode<T>* k3)
{
	k3->left = LeftRotation(k3->left);
	return RightRotation(k3);
}
//右左旋(RL)
template<class T>
AVLNode<T>* AVL<T>::RightLeftRotation(AVLNode<T>* k1)
{
	k1->right = RightRotation(k1->right);
	return LeftRotation(k1);
}

//插入
template<class T>
AVLNode<T>* AVL<T>::insert(AVLNode<T>*& tree, T key)
{
	if (tree == NULL)//当前节点为空，创建新节点
	{
		tree = new AVLNode<T>(key);
		if (tree == NULL)
		{
			cout << "ERROR: create AVL tree node failed!" << endl;
			return NULL;
		}
	}
	else if (key < tree->key)
	{
		tree->left = insert(tree->left, key);//插入到左子树
		//插入后，若AVL树失去平衡，则进行相应的平衡操作
		if (height(tree->left) - height(tree->right) == 2)
		{
			if (key < tree->left->key)//LL
				tree = RightRotation(tree);
			else
				tree = LeftRightRotation(tree);//LR
		}
	}
	else if (key > tree->key)
	{
		tree->right = insert(tree->right, key);//插入到右子树
		//插入后，若AVL树失去平衡，则进行相应的平衡操作
		if (height(tree->right) - height(tree->left) == 2)
		{
			if (key > tree->right->key)//RR
				tree = LeftRotation(tree);
			else
				tree = RightLeftRotation(tree);//RL
		}
	}
	else//key == tree->key
	{
		cout << "ERROR: the key is already in the tree!" << endl;
	}
	tree->height = max(height(tree->left), height(tree->right)) + 1;//更新树高度
	return tree;
}
template<class T>
void AVL<T>::insert(T key)
{
	insert(root, key);
}

//删除
template<class T>
//删除节点z，并返回根节点
AVLNode<T>* AVL<T>::remove(AVLNode<T>*& tree, AVLNode<T>* z)
{
	if (tree == NULL || z == NULL)//树为空或要删除的节点为空
		return NULL;
	if (z->key < tree->key)//要删除的节点在左子树中
	{
		tree->left = remove(tree->left, z);//删除左子树中的节点
		//删除后，若AVL树失去平衡，则进行相应的平衡操作
		if (height(tree->right) - height(tree->left) == 2)
		{
			AVLNode<T>* r = tree->right;
			if (height(r->left) > height(r->right))//RL
				tree = RightLeftRotation(tree);
			else//RR
				tree = LeftRotation(tree);
		}
	}
	else if (z->key > tree->key)//要删除的节点在右子树中
	{
		tree->right = remove(tree->right, z);//删除右子树中的节点
		//删除后，若AVL树失去平衡，则进行相应的平衡操作
		if (height(tree->left) - height(tree->right) == 2)
		{
			AVLNode<T>* l = tree->left;
			if (height(l->right) > height(l->left))//LR
				tree = LeftRightRotation(tree);
			else//LL
				tree = RightRotation(tree);
		}
	}
	else//tree是要删除的节点
	{
		if (tree->left != NULL && tree->right != NULL)//tree有两个子节点
		{
			if (height(tree->left) > height(tree->right))//左子树高度大于右子树高度
			{
				AVLNode<T>* max = maximum(tree->left);//找到左子树中的最大节点
				tree->key = max->key;//将最大节点的值赋给tree
				tree->left = remove(tree->left, max);//删除左子树中的最大节点
				//采用这种方法，可以保证删除后的树仍然是平衡的
			}
			else
			{
				AVLNode<T>* min = minimum(tree->right);//找到右子树中的最小节点
				tree->key = min->key;//将最小节点的值赋给tree
				tree->right = remove(tree->right, min);//删除右子树中的最小节点
				//采用这种方法，可以保证删除后的树仍然是平衡的
			}
		}
		else//tree有一个或没有子节点
		{
			AVLNode<T>* temp = tree;
			tree = (tree->left != NULL) ? tree->left : tree->right;
			delete temp;
		}
	}
	if (tree != NULL)
		tree->height = max(height(tree->left), height(tree->right)) + 1;//更新树高度
	return tree;
}
template<class T>
void AVL<T>::remove(T key)
{
	AVLNode<T>* z;
	if ((z = search(root, key)) != NULL)
		root = remove(root, z);
	else cout << "ERROR: the key is not in the tree!" << endl;
}


//最值
template<class T>
AVLNode<T>* AVL<T>::minimum(AVLNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}
template<class T>
T AVL<T>::minimum()
{
	AVLNode<T>* p = minimum(root);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

template<class T>
AVLNode<T>* AVL<T>::maximum(AVLNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}
template<class T>
T AVL<T>::maximum()
{
	AVLNode<T>* p = maximum(root);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

//遍历
//前序遍历
template<class T>
void AVL<T>::preOrder(AVLNode<T>* tree) const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
template<class T>
void AVL<T>::preOrder()
{
	preOrder(root);
	cout << endl;
}
//中序遍历
template<class T>
void AVL<T>::inOrder(AVLNode<T>* tree) const
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}
template<class T>
void AVL<T>::inOrder()
{
	inOrder(root);
	cout << endl;
}
//后序遍历
template<class T>
void AVL<T>::postOrder(AVLNode<T>* tree) const
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}
template<class T>
void AVL<T>::postOrder()
{
	postOrder(root);
	cout << endl;
}

//查找
//递归查找
template<class T>
AVLNode<T>* AVL<T>::search(AVLNode<T>* tree, T key) const
{
	if (tree == nullptr)
		return nullptr;
	if (tree->key == key)
		return tree;
	if (key < tree->key)
		return search(tree->left, key);
	else
		return search(tree->right, key);
}
template<class T>
AVLNode<T>* AVL<T>::search(T key)
{
	AVLNode<T>* p = search(root, key);
	if (p != NULL)
		return p;
	else {
		cout << "The key is not in the tree!" << endl;
		return NULL;
	}
}
//非递归查找
template<class T>
AVLNode<T>* AVL<T>::iterativeSearch(AVLNode<T>* tree, T key) const
{
	while (tree != NULL)
	{
		if (tree->key == key)
			return tree;
		else if (key < tree->key)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return NULL;
}
template<class T>
AVLNode<T>* AVL<T>::iterativeSearch(T key)
{
	AVLNode<T>* p = iterativeSearch(root, key);
	if (p != NULL)
		return p;
	else {
		cout << "The key is not in the tree!" << endl;
		return NULL;
	}
}

//查找前驱
template<class T>
AVLNode<T>* AVL<T>::predecessor(AVLNode<T>* tree, T key)
{
	AVLNode<T>* p = iterativeSearch(tree, key);
	if (p == NULL)
	{
		cout << "The key is not in the tree!" << endl;
		return NULL;
	}
	if (p->left != NULL)//左子树不为空，前驱是左子树中的最大节点
		return maximum(p->left);
	//左子树为空
	AVLNode<T>* parent = NULL;
	AVLNode<T>* x = tree;
	while (x != NULL)
	{
		if (key == x->key)
			break;
		else if (key < x->key)
			x = x->left;
		else
		{
			parent = x;
			x = x->right;
		}
	}
	if (parent == NULL) cout << key << " is the minimum." << endl;
	return parent;
}
template<class T>
int AVL<T>::predecessor(T key)
{
	AVLNode<T>* p = predecessor(root, key);
	if (p != NULL)
		return p->key;
	else
	{
		//cout << "The key is not in the tree!" << endl;
		return -INF;
		//return (T)NULL;
	}
}

//查找后继
template<class T>
AVLNode<T>* AVL<T>::successor(AVLNode<T>* tree, T key)
{
	AVLNode<T>* p = iterativeSearch(tree, key);
	if (p == NULL)
	{
		cout << "The key is not in the tree!" << endl;
		return NULL;
	}
	if (p->right != NULL)//右子树不为空，后继是右子树中的最小节点
		return minimum(p->right);
	//右子树为空
	AVLNode<T>* parent = NULL;
	AVLNode<T>* x = tree;
	while (x != NULL)
	{
		if (key == x->key)
			break;
		else if (key < x->key)
		{
			parent = x;
			x = x->left;
		}
		else
			x = x->right;
	}
	if (parent == NULL) cout << key << " is the maximum." << endl;
	return parent;
}
template<class T>
int AVL<T>::successor(T key)
{
	AVLNode<T>* p = successor(root, key);
	if (p != NULL)
		return p->key;
	else
	{
		//cout << "The key is not in the tree!" << endl;
		return INF;
		//return (T)NULL;
	}
}

//销毁
template<class T>
void AVL<T>::destroy(AVLNode<T>*& tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		destroy(tree->left);
	if (tree->right != NULL)
		destroy(tree->right);
	delete tree;
	tree = NULL;
}
template<class T>
void AVL<T>::destroy()
{
	destroy(root);
}

//打印
template<class T>
void AVL<T>::print(AVLNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree是根节点
			cout << tree->key << " is root" << endl;
		else                // tree是分支节点
			cout << tree->key << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << endl;
		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}
template<class T>
void AVL<T>::print()
{
	if (root != NULL)
		print(root, root->key, 0);
}