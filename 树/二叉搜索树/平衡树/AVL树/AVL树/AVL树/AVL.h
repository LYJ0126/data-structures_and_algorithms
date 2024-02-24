
//AVL.h����ģ���࣬��main������ֻ������AVL.h����û�а���AVL.cpp����ô�������޷�����ģ����������Ӧ�Ĵ��룬��˻ᱨ��
//�����������AVL.h��AVL.cpp����һ�𣬻�����main�����а���AVL.cpp
//������ý�AVL.h��AVL.cpp����һ��ķ���
#pragma once
#include <iostream>
#include <cmath>
using namespace std;

//AVL��
//AVL����һ����ƽ����������������ÿ���ڵ�����������������ĸ߶Ȳ�����Ϊ1
//AVL���ĸ߶�ΪO(logn)
//AVL���Ĳ����ɾ�������ᵼ�����ĸ߶ȷ����仯�������Ҫ��������ƽ�����
//ƽ�����������������������������������
//ƽ�������ʱ�临�Ӷ�ΪO(1)
//AVL���Ĳ����ɾ��������ʱ�临�Ӷ�ΪO(logn)
//AVL���Ĳ��Ҳ�����ʱ�临�Ӷ�ΪO(logn)


#define INF 2147483647
//AVL���Ľڵ�
template<class T>
class AVLNode
{
public:
	T key; //�ڵ�Ĺؼ���
	int height; //�ڵ�ĸ߶�
	AVLNode* left; //�ڵ������
	AVLNode* right; //�ڵ���Һ���
    AVLNode(T k) :key(k),left(nullptr),right(nullptr),height(1){}//���캯��
	AVLNode(T k, AVLNode* l, AVLNode* r) :key(k), left(l), right(r), height(1) {}//���캯��
};

//AVL��
template<class T>
class AVL
{
public:
    AVL();
    ~AVL();

    // ��ȡ���ĸ߶�
    int height();

    // ǰ�����"AVL��"
    void preOrder();
    // �������"AVL��"
    void inOrder();
    // �������"AVL��"
    void postOrder();

	int predecessor(T key);//����ǰ��

	int successor(T key);//���Һ��

    // (�ݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
    AVLNode<T>* search(T key);
    // (�ǵݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
    AVLNode<T>* iterativeSearch(T key);

    // ������С��㣺������С���ļ�ֵ��
    T minimum();
    // ��������㣺���������ļ�ֵ��
    T maximum();

    // �����(keyΪ�ڵ��ֵ)���뵽AVL����
    void insert(T key);

    // ɾ�����(keyΪ�ڵ��ֵ)
    void remove(T key);

    // ����AVL��
    void destroy();

    // ��ӡAVL��
    void print();
private:
	AVLNode<T>* root;//���ڵ�
    // ��ȡ���ĸ߶�
    int height(AVLNode<T>* tree);

    // ǰ�����"AVL��"
    void preOrder(AVLNode<T>* tree) const;
    // �������"AVL��"
    void inOrder(AVLNode<T>* tree) const;
    // �������"AVL��"
    void postOrder(AVLNode<T>* tree) const;

	AVLNode<T>* predecessor(AVLNode<T>* tree, T key);//����ǰ��

	AVLNode<T>* successor(AVLNode<T>* tree, T key);//���Һ��

    // (�ݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
    AVLNode<T>* search(AVLNode<T>* x, T key) const;
    // (�ǵݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
    AVLNode<T>* iterativeSearch(AVLNode<T>* x, T key) const;

    // ������С��㣺����treeΪ������AVL������С��㡣
    AVLNode<T>* minimum(AVLNode<T>* tree);
    // ��������㣺����treeΪ������AVL��������㡣
    AVLNode<T>* maximum(AVLNode<T>* tree);

    // LL�������Ӧ�����(����)��
    AVLNode<T>* RightRotation(AVLNode<T>* k2);

    // RR�����Ҷ�Ӧ�����(����)��
    AVLNode<T>* LeftRotation(AVLNode<T>* k1);

    // LR�����Ҷ�Ӧ�����(������)��
    AVLNode<T>* LeftRightRotation(AVLNode<T>* k3);

    // RL�������Ӧ�����(������)��
    AVLNode<T>* RightLeftRotation(AVLNode<T>* k1);

    // �������뵽AVL��(tree)��
    AVLNode<T>* insert(AVLNode<T>*& tree, T key);

    // ɾ��AVL��(tree)�еĽ�㣬�����ر�ɾ���Ľ��
    AVLNode<T>* remove(AVLNode<T>*& tree, AVLNode<T>* z);

    // ����AVL��
    void destroy(AVLNode<T>*& tree);

    // ��ӡAVL��
    void print(AVLNode<T>* tree, T key, int direction);
};


//AVL���Ĺ��캯��
template<class T>
AVL<T>::AVL()
{
	root = NULL;
}

//AVL������������
template<class T>
AVL<T>::~AVL()
{
	//cout<<"������������"<<endl;
	destroy(root);
}

//��ȡ���߶�
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

//��ת
//����(LL)
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
//����(RR)
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
//������(LR)
template<class T>
AVLNode<T>* AVL<T>::LeftRightRotation(AVLNode<T>* k3)
{
	k3->left = LeftRotation(k3->left);
	return RightRotation(k3);
}
//������(RL)
template<class T>
AVLNode<T>* AVL<T>::RightLeftRotation(AVLNode<T>* k1)
{
	k1->right = RightRotation(k1->right);
	return LeftRotation(k1);
}

//����
template<class T>
AVLNode<T>* AVL<T>::insert(AVLNode<T>*& tree, T key)
{
	if (tree == NULL)//��ǰ�ڵ�Ϊ�գ������½ڵ�
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
		tree->left = insert(tree->left, key);//���뵽������
		//�������AVL��ʧȥƽ�⣬�������Ӧ��ƽ�����
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
		tree->right = insert(tree->right, key);//���뵽������
		//�������AVL��ʧȥƽ�⣬�������Ӧ��ƽ�����
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
	tree->height = max(height(tree->left), height(tree->right)) + 1;//�������߶�
	return tree;
}
template<class T>
void AVL<T>::insert(T key)
{
	insert(root, key);
}

//ɾ��
template<class T>
//ɾ���ڵ�z�������ظ��ڵ�
AVLNode<T>* AVL<T>::remove(AVLNode<T>*& tree, AVLNode<T>* z)
{
	if (tree == NULL || z == NULL)//��Ϊ�ջ�Ҫɾ���Ľڵ�Ϊ��
		return NULL;
	if (z->key < tree->key)//Ҫɾ���Ľڵ�����������
	{
		tree->left = remove(tree->left, z);//ɾ���������еĽڵ�
		//ɾ������AVL��ʧȥƽ�⣬�������Ӧ��ƽ�����
		if (height(tree->right) - height(tree->left) == 2)
		{
			AVLNode<T>* r = tree->right;
			if (height(r->left) > height(r->right))//RL
				tree = RightLeftRotation(tree);
			else//RR
				tree = LeftRotation(tree);
		}
	}
	else if (z->key > tree->key)//Ҫɾ���Ľڵ�����������
	{
		tree->right = remove(tree->right, z);//ɾ���������еĽڵ�
		//ɾ������AVL��ʧȥƽ�⣬�������Ӧ��ƽ�����
		if (height(tree->left) - height(tree->right) == 2)
		{
			AVLNode<T>* l = tree->left;
			if (height(l->right) > height(l->left))//LR
				tree = LeftRightRotation(tree);
			else//LL
				tree = RightRotation(tree);
		}
	}
	else//tree��Ҫɾ���Ľڵ�
	{
		if (tree->left != NULL && tree->right != NULL)//tree�������ӽڵ�
		{
			if (height(tree->left) > height(tree->right))//�������߶ȴ����������߶�
			{
				AVLNode<T>* max = maximum(tree->left);//�ҵ��������е����ڵ�
				tree->key = max->key;//�����ڵ��ֵ����tree
				tree->left = remove(tree->left, max);//ɾ���������е����ڵ�
				//�������ַ��������Ա�֤ɾ���������Ȼ��ƽ���
			}
			else
			{
				AVLNode<T>* min = minimum(tree->right);//�ҵ��������е���С�ڵ�
				tree->key = min->key;//����С�ڵ��ֵ����tree
				tree->right = remove(tree->right, min);//ɾ���������е���С�ڵ�
				//�������ַ��������Ա�֤ɾ���������Ȼ��ƽ���
			}
		}
		else//tree��һ����û���ӽڵ�
		{
			AVLNode<T>* temp = tree;
			tree = (tree->left != NULL) ? tree->left : tree->right;
			delete temp;
		}
	}
	if (tree != NULL)
		tree->height = max(height(tree->left), height(tree->right)) + 1;//�������߶�
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


//��ֵ
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

//����
//ǰ�����
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
//�������
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
//�������
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

//����
//�ݹ����
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
//�ǵݹ����
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

//����ǰ��
template<class T>
AVLNode<T>* AVL<T>::predecessor(AVLNode<T>* tree, T key)
{
	AVLNode<T>* p = iterativeSearch(tree, key);
	if (p == NULL)
	{
		cout << "The key is not in the tree!" << endl;
		return NULL;
	}
	if (p->left != NULL)//��������Ϊ�գ�ǰ�����������е����ڵ�
		return maximum(p->left);
	//������Ϊ��
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

//���Һ��
template<class T>
AVLNode<T>* AVL<T>::successor(AVLNode<T>* tree, T key)
{
	AVLNode<T>* p = iterativeSearch(tree, key);
	if (p == NULL)
	{
		cout << "The key is not in the tree!" << endl;
		return NULL;
	}
	if (p->right != NULL)//��������Ϊ�գ�������������е���С�ڵ�
		return minimum(p->right);
	//������Ϊ��
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

//����
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

//��ӡ
template<class T>
void AVL<T>::print(AVLNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree�Ǹ��ڵ�
			cout << tree->key << " is root" << endl;
		else                // tree�Ƿ�֧�ڵ�
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