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
	s->parent = NIL;
	return s;
}

void RBT::destroy(RBNode* node)
{
	if (node == NIL) {
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
	RBNode* curnode = successor(root, key);
	if (curnode == NIL) {
		cout << "The key is the maximum" << endl;
		return INF;
	}
	else return curnode->key;
}

//��ת����
//����
	/*       xp                 xp
	 *       /                  /
	 *     x                   y
	 *    / \      ===>       / \
	 *   lx  y               x   ry
	 *      / \             / \
	 *     ly  ry          lx  ly
	*/
void RBT::leftRotate(RBNode* x)
{
	RBNode* y = x->right;
	x->right = y->left;
	if (y->left != NIL) y->left->parent = x;
	y->parent = x->parent;
	if(root == x) root = y;//x�Ǹ��ڵ�
	else if (x == x->parent->left) x->parent->left = y;//x���丸�ڵ������
	else x->parent->right = y;//x���丸�ڵ���Һ���
	y->left = x;
	x->parent = y;
}
//����
	/*		xp                xp
	*		/                 /
	*	   x                 y
	*	  / \	== = >		/ \
	*	 y   rx           ly   x
	*	/ \					  / \
	*  ly  ry               ry  rx
	*/
void RBT::rightRotate(RBNode* x)
{
	RBNode* y = x->left;
	x->left = y->right;
	if (y->right != NIL) y->right->parent = x;
	y->parent = x->parent;
	if (root == x) root = y;//x�Ǹ��ڵ�
	else if (x == x->parent->left) x->parent->left = y;//x���丸�ڵ������
	else x->parent->right = y;//x���丸�ڵ���Һ���
	y->right = x;
	x->parent = y;
}

bool RBT::insert(int key)
{
	RBNode* parent = NIL;
	RBNode* x = root;
	while (x != NIL) {
		if (key == x->key) {
			cout<<"The key is already in the tree!"<<endl;
			return false;
		}
		parent = x;
		if (key < x->key) x = x->left;
		else x = x->right;
	}
	//���x==NIL,parentָ��Ҷ�ӽڵ�
	RBNode* s = createNode(key);
	if (parent == NIL) root = s;//��Ϊ��
	else if (key < parent->key) parent->left = s;
	else parent->right = s;
	s->parent = parent;
	//����
	insertFixup(s);
}
//��������
void RBT::insertFixup(RBNode* s)
{
	//����ڵ����ɫ,����Ҫע�⣬��ڵ������NIL,NIL�Ǻ�ɫ��
	RBNode* uncle;
	while (s->parent->color == RED) {//���ڵ��Ǻ�ɫ
		if (s->parent == s->parent->parent->left) {
			uncle = s->parent->parent->right;
			if (uncle->color == RED) {//���1����ڵ��Ǻ�ɫ
				//���ڵ����ڵ㶼��Ϊ��ɫ���游�ڵ��Ϊ��ɫ��Ȼ�����游�ڵ�Ϊ��ǰ�ڵ㣬�������ϵ���
				s->parent->color = BLACK;
				uncle->color = BLACK;
				s->parent->parent->color = RED;
				s = s->parent->parent;
			}
			else {
				//��ڵ��Ǻ�ɫ(����NIL)
				if (s == s->parent->right) {//���2����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
					//�Ը��ڵ�Ϊ��ǰ�ڵ�������ת��Ϊ���3
					s = s->parent;//�Ը��ڵ�Ϊ��ǰ�ڵ�
					leftRotate(s);
				}
				//���3����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ�������
				//���ڵ��Ϊ��ɫ���游�ڵ��Ϊ��ɫ��Ȼ�����游�ڵ�����
				s->parent->color = BLACK;
				s->parent->parent->color = RED;
				rightRotate(s->parent->parent);
			}
		}
		else {//�ԳƵ����
			uncle = s->parent->parent->left;
			if (uncle->color == RED) {//���1����ڵ��Ǻ�ɫ
				//���ڵ����ڵ㶼��Ϊ��ɫ���游�ڵ��Ϊ��ɫ��Ȼ�����游�ڵ�Ϊ��ǰ�ڵ㣬�������ϵ���
				s->parent->color = BLACK;
				uncle->color = BLACK;
				s->parent->parent->color = RED;
				s = s->parent->parent;
			}
			else {
				if (s == s->parent->left) {//���2����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ�������
					//�Ը��ڵ�Ϊ��ǰ�ڵ�������ת��Ϊ���3
					s = s->parent;
					rightRotate(s);
				}
				//���3����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
				//���ڵ��Ϊ��ɫ���游�ڵ��Ϊ��ɫ��Ȼ�����游�ڵ�����
				s->parent->color = BLACK;
				s->parent->parent->color = RED;
				leftRotate(s->parent->parent);
			}
		}
	}
	root->color = BLACK;//��󽫸��ڵ���Ϊ��ɫ,������Ϊ����󣬸��ڵ���ܱ�Ϊ��ɫ
}

void RBT::transplant(RBNode* u, RBNode* v)
{
	if (u->parent == NIL) root = v;//u�Ǹ��ڵ�
	else if (u == u->parent->left) u->parent->left = v;//u���丸�ڵ������
	else u->parent->right = v;//u���丸�ڵ���Һ���
	v->parent = u->parent;
}

void RBT::remove(int key)
{
	RBNode* s = iterativesearch(root, key);
	if (s == NIL) {
		cout<<"The key is not in the tree!"<<endl;
		return;
	}
	remove(s);
}

void RBT::remove(RBNode* z)
{
	RBNode* x = NIL;
	RBNode* y = z;
	Color y_original_color = y->color;
	//���1��zֻ��һ�����ӻ���û�к���
	if (z->left == NIL) {
		x = z->right;
		transplant(z, z->right);//��z���Һ����滻z
	}
	else if (z->right == NIL) {
		x = z->left;
		transplant(z, z->left);//��z�������滻z
	}
	else {
		//z����������,˵��z����Ҷ�ӽڵ�
		y = minimum(z->right);//�ҵ�z�ĺ�̽ڵ�
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) x->parent = y;//z�ĺ�̽ڵ���z���Һ��ӣ���yû������
		else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);//��y�滻z
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (y_original_color == BLACK) removeFixup(x);//���y����ɫ�Ǻ�ɫ,˵��ɾ����һ����ɫ�ڵ㣬��Ҫ������ע��xָ������滻�ڵ�
	delete z;//�ͷ�z
}

void RBT::removeFixup(RBNode* x)
{
	RBNode* w;
	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {//x������
			w = x->parent->right;//x���ֵܽڵ�
			if (w->color == RED) {//���1��x���ֵܽڵ�w�Ǻ�ɫ
				//�ֵܽڵ�w��Ϊ��ɫ�����ڵ��Ϊ��ɫ��Ȼ���Ը��ڵ�����
				w->color = BLACK;
				x->parent->color = RED;
				leftRotate(x->parent);
				w = x->parent->right;//���������ֵܽڵ�
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {//���2��x���ֵܽڵ�w�Ǻ�ɫ����w���������Ӷ��Ǻ�ɫ
				//�ֵܽڵ�w��Ϊ��ɫ��Ȼ���Ը��ڵ�Ϊ��ǰ�ڵ㣬�������ϵ���
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {//���3��x���ֵܽڵ�w�Ǻ�ɫ����w�������Ǻ�ɫ���Һ����Ǻ�ɫ
					//�ֵܽڵ�w�����ӱ�Ϊ��ɫ���ֵܽڵ�w��Ϊ��ɫ��Ȼ�����ֵܽڵ�w����
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(w);
					w = x->parent->right;//���������ֵܽڵ�
				}
				//���4��x���ֵܽڵ�w�Ǻ�ɫ����w���Һ����Ǻ�ɫ
				//�ֵܽڵ�w����ɫ��Ϊ���ڵ����ɫ�����ڵ��Ϊ��ɫ���ֵܽڵ�w���Һ��ӱ�Ϊ��ɫ��Ȼ���Ը��ڵ�����
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(x->parent);
				x = root;//��������
			}
		}
		else {//�ԳƵ����,x���Һ���
			w = x->parent->left;//x���ֵܽڵ�
			if (w->color == RED) {//���1��x���ֵܽڵ�w�Ǻ�ɫ
				//�ֵܽڵ�w��Ϊ��ɫ�����ڵ��Ϊ��ɫ��Ȼ���Ը��ڵ�����
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				w = x->parent->left;//���������ֵܽڵ�
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {//���2��x���ֵܽڵ�w�Ǻ�ɫ����w���������Ӷ��Ǻ�ɫ
				//�ֵܽڵ�w��Ϊ��ɫ��Ȼ���Ը��ڵ�Ϊ��ǰ�ڵ㣬�������ϵ���
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {//���3��x���ֵܽڵ�w�Ǻ�ɫ����w���Һ����Ǻ�ɫ�������Ǻ�ɫ
					//�ֵܽڵ�w���Һ��ӱ�Ϊ��ɫ���ֵܽڵ�w��Ϊ��ɫ��Ȼ�����ֵܽڵ�w����
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(w);
					w = x->parent->left;//���������ֵܽڵ�
				}
				//���4��x���ֵܽڵ�w�Ǻ�ɫ����w�������Ǻ�ɫ
				//�ֵܽڵ�w����ɫ��Ϊ���ڵ����ɫ�����ڵ��Ϊ��ɫ���ֵܽڵ�w�����ӱ�Ϊ��ɫ��Ȼ���Ը��ڵ�����
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(x->parent);
				x = root;//��������
			}
		}
	}
	x->color = BLACK;//���x��Ϊ��ɫ
}

void RBT::print()
{
	if(root != NIL) print(root, root->key, 0);
}

void RBT::print(RBNode* node, int key, int direction)
{
	if (node != NIL) {
		if (direction == 0) cout << node->key << "(black) is root" << endl;
		else {
			string color = node->color == RED ? "red" : "black";
			cout << node->key << "(" << color << ") is " << key << "'s " << (direction == 1 ? "right" : "left") << " child" << endl;
		}
		print(node->left, node->key, -1);
		print(node->right, node->key, 1);
	}
}