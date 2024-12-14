#include "RedBlackTree1.h"

RBT::RBT()
{
	NIL = createNode(0);
	root = NIL;
	NIL->color = BLACK;
}

RBNode* RBT::createNode(int key)
{
	RBNode* s = new RBNode();
	s->key = key;
	s->color = RED;
	s->left = NIL;
	s->right = NIL;
	//s->parent = NIL;
	return s;
}

void RBT::destroy(RBNode* node)
{
	if (node == root) {
		return;
	}
	if (node->left != NIL) destroy(node->left);
	if (node->right != NIL) destroy(node->right);
	delete node;
	node = nullptr;
}

RBT:: ~RBT()//��������
{
	destroy(root);
	delete NIL;
	cout<<"RBT has been destroyed!"<<endl;//��ʾ��Ϣ
}

void RBT::inorder(RBNode* node)
{
	if (node == NIL) return;
	inorder(node->left);
	cout<<node->key<<" ";
	inorder(node->right);
}
void RBT::inorder()
{
	inorder(root);
}

void RBT::preorder(RBNode* node)
{
	if (node == NIL) return;
	cout<<node->key<<" ";
	preorder(node->left);
	preorder(node->right);
}
void RBT::preorder()
{
	preorder(root);
}

void RBT::postorder(RBNode* node)
{
	if (node == NIL) return;
	postorder(node->left);
	postorder(node->right);
	cout<<node->key<<" ";
}
void RBT::postorder()
{
	postorder(root);
}

RBNode* RBT::search(RBNode* node, int key)//�ݹ����
{
	if (node == NIL || node->key == key) return node;
	if (key < node->key) return search(node->left, key);
	else return search(node->right, key);
}
RBNode* RBT::iterativesearch(RBNode* node, int key)//��������
{
	while (node != NIL) {
		if (node->key == key) return node;
		if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NIL;
}

int RBT::search(int key)
{
	RBNode* curnode = search(root, key);
	if (curnode != NIL) return curnode->key;
	else {
		cout<<"No such key!"<<endl;
		return -INF;
	}
}
int RBT::iterativesearch(int key)
{
	RBNode* curnode = iterativesearch(root, key);
	if (curnode != NIL) return curnode->key;
	else {
		cout<<"No such key!"<<endl;
	return -INF;
	}
}

RBNode* RBT::minimum(RBNode* node)
{
	if (node == NIL) return NIL;
	while(node->left != NIL) node = node->left;
	return node;
}
RBNode* RBT::maximum(RBNode* node)
{
	if (node == NIL) return NIL;
	while(node->right != NIL) node = node->right;
	return node;
}
int RBT::minimum()
{
	RBNode* curnode = minimum(root);
	if (curnode == NIL) {
		cout << "The tree is empty" << endl;
		return -INF;
	}
	else return curnode->key;
}
int RBT::maximum()
{
	RBNode* curnode = maximum(root);
	if (curnode == NIL) {
		cout << "The tree is emtpy" << endl;
		return INF;
	}
	else return curnode->key;
}

RBNode* RBT::predecessor(RBNode* node, int key)//����ǰ��
{
	RBNode* p = iterativesearch(node, key);
	if (p == NIL) {
		cout<<"The key is not in the tree!"<<endl;
		return NIL;
	}
	if (p->left != NIL) {
		return maximum(p->left);//��������Ϊ�գ�ǰ��Ϊ�����������ڵ�
	}
	else {
		//������Ϊ�գ��ýڵ�����Ƚڵ��У�������������������ýڵ�Ľڵ�Ϊ��ǰ��
		RBNode* parent = NIL;
		RBNode* x = root;
		while (x != NIL) {
			if (key == x->key) break;
			else if (key < x->key) x = x->left;
			else {
				parent = x;//����ڵ���parent����������
				x = x->right;
			}
		}
		return parent;
	}
}
int RBT::predecessor(int key)
{
	RBNode* curnode = predecessor(root, key);
	if (curnode == NIL) {
		cout << "The key is the minimum" << endl;
		return -INF;
	}
	else return curnode->key;
}

RBNode* RBT::successor(RBNode* node, int key)
{
	RBNode* p = iterativesearch(node, key);
	if (p == NIL) {
		cout << "The key is not in the tree!" << endl;
		return NIL;
	}
	if (p->right != NIL) {
		return minimum(p->right);//��������Ϊ�գ����Ϊ����������С�ڵ�
	}
	else {
		//������Ϊ��,�ýڵ�����Ƚڵ��У�������������������ýڵ�Ľڵ�Ϊ����
		RBNode* parent = NIL;
		RBNode* x = root;
		while (x != NIL) {
			if (key == x->key) break;
			else if (key > x->key) x = x->right;
			else {
				parent = x;//����ڵ���parent����������
				x = x->left;
			}
		}
		return parent;
	}
}
int RBT::successor(int key)
{
	RBNode* curnode = predecessor(root, key);
	if (curnode == NIL) {
		cout << "The key is the maximum" << endl;
		return INF;
	}
	else return curnode->key;
}