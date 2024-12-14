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

RBT:: ~RBT()//析构函数
{
	destroy(root);
	delete NIL;
	cout<<"RBT has been destroyed!"<<endl;//提示信息
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

RBNode* RBT::search(RBNode* node, int key)//递归查找
{
	if (node == NIL || node->key == key) return node;
	if (key < node->key) return search(node->left, key);
	else return search(node->right, key);
}
RBNode* RBT::iterativesearch(RBNode* node, int key)//迭代查找
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

RBNode* RBT::predecessor(RBNode* node, int key)//查找前驱
{
	RBNode* p = iterativesearch(node, key);
	if (p == NIL) {
		cout<<"The key is not in the tree!"<<endl;
		return NIL;
	}
	if (p->left != NIL) {
		return maximum(p->left);//左子树不为空，前驱为左子树中最大节点
	}
	else {
		//左子树为空，该节点的祖先节点中，最近的且右子树包含该节点的节点为其前驱
		RBNode* parent = NIL;
		RBNode* x = root;
		while (x != NIL) {
			if (key == x->key) break;
			else if (key < x->key) x = x->left;
			else {
				parent = x;//这个节点在parent的右子树中
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
		return minimum(p->right);//右子树不为空，后继为右子树中最小节点
	}
	else {
		//右子树为空,该节点的祖先节点中，最近的且左子树包含该节点的节点为其后继
		RBNode* parent = NIL;
		RBNode* x = root;
		while (x != NIL) {
			if (key == x->key) break;
			else if (key > x->key) x = x->right;
			else {
				parent = x;//这个节点在parent的左子树中
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