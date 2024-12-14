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
	RBNode* curnode = successor(root, key);
	if (curnode == NIL) {
		cout << "The key is the maximum" << endl;
		return INF;
	}
	else return curnode->key;
}

//旋转操作
//左旋
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
	if(root == x) root = y;//x是根节点
	else if (x == x->parent->left) x->parent->left = y;//x是其父节点的左孩子
	else x->parent->right = y;//x是其父节点的右孩子
	y->left = x;
	x->parent = y;
}
//右旋
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
	if (root == x) root = y;//x是根节点
	else if (x == x->parent->left) x->parent->left = y;//x是其父节点的左孩子
	else x->parent->right = y;//x是其父节点的右孩子
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
	//最后x==NIL,parent指向叶子节点
	RBNode* s = createNode(key);
	if (parent == NIL) root = s;//树为空
	else if (key < parent->key) parent->left = s;
	else parent->right = s;
	s->parent = parent;
	//调整
	insertFixup(s);
}
//插入修正
void RBT::insertFixup(RBNode* s)
{
	//看叔节点的颜色,这里要注意，叔节点可以是NIL,NIL是黑色的
	RBNode* uncle;
	while (s->parent->color == RED) {//父节点是红色
		if (s->parent == s->parent->parent->left) {
			uncle = s->parent->parent->right;
			if (uncle->color == RED) {//情况1：叔节点是红色
				//父节点和叔节点都变为黑色，祖父节点变为红色，然后以祖父节点为当前节点，继续向上调整
				s->parent->color = BLACK;
				uncle->color = BLACK;
				s->parent->parent->color = RED;
				s = s->parent->parent;
			}
			else {
				//叔节点是黑色(包括NIL)
				if (s == s->parent->right) {//情况2：叔节点是黑色，且当前节点是右孩子
					//以父节点为当前节点左旋，转化为情况3
					s = s->parent;//以父节点为当前节点
					leftRotate(s);
				}
				//情况3：叔节点是黑色，且当前节点是左孩子
				//父节点变为黑色，祖父节点变为红色，然后以祖父节点右旋
				s->parent->color = BLACK;
				s->parent->parent->color = RED;
				rightRotate(s->parent->parent);
			}
		}
		else {//对称的情况
			uncle = s->parent->parent->left;
			if (uncle->color == RED) {//情况1：叔节点是红色
				//父节点和叔节点都变为黑色，祖父节点变为红色，然后以祖父节点为当前节点，继续向上调整
				s->parent->color = BLACK;
				uncle->color = BLACK;
				s->parent->parent->color = RED;
				s = s->parent->parent;
			}
			else {
				if (s == s->parent->left) {//情况2：叔节点是黑色，且当前节点是左孩子
					//以父节点为当前节点右旋，转化为情况3
					s = s->parent;
					rightRotate(s);
				}
				//情况3：叔节点是黑色，且当前节点是右孩子
				//父节点变为黑色，祖父节点变为红色，然后以祖父节点左旋
				s->parent->color = BLACK;
				s->parent->parent->color = RED;
				leftRotate(s->parent->parent);
			}
		}
	}
	root->color = BLACK;//最后将根节点设为黑色,这是因为插入后，根节点可能变为红色
}

void RBT::transplant(RBNode* u, RBNode* v)
{
	if (u->parent == NIL) root = v;//u是根节点
	else if (u == u->parent->left) u->parent->left = v;//u是其父节点的左孩子
	else u->parent->right = v;//u是其父节点的右孩子
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
	//情况1：z只有一个孩子或者没有孩子
	if (z->left == NIL) {
		x = z->right;
		transplant(z, z->right);//用z的右孩子替换z
	}
	else if (z->right == NIL) {
		x = z->left;
		transplant(z, z->left);//用z的左孩子替换z
	}
	else {
		//z有两个孩子,说明z不是叶子节点
		y = minimum(z->right);//找到z的后继节点
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) x->parent = y;//z的后继节点是z的右孩子，即y没有左孩子
		else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);//用y替换z
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (y_original_color == BLACK) removeFixup(x);//如果y的颜色是黑色,说明删除了一个黑色节点，需要调整。注意x指向的是替换节点
	delete z;//释放z
}

void RBT::removeFixup(RBNode* x)
{
	RBNode* w;
	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {//x是左孩子
			w = x->parent->right;//x的兄弟节点
			if (w->color == RED) {//情况1：x的兄弟节点w是红色
				//兄弟节点w变为黑色，父节点变为红色，然后以父节点左旋
				w->color = BLACK;
				x->parent->color = RED;
				leftRotate(x->parent);
				w = x->parent->right;//重新设置兄弟节点
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {//情况2：x的兄弟节点w是黑色，且w的两个孩子都是黑色
				//兄弟节点w变为红色，然后以父节点为当前节点，继续向上调整
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {//情况3：x的兄弟节点w是黑色，且w的左孩子是红色，右孩子是黑色
					//兄弟节点w的左孩子变为黑色，兄弟节点w变为红色，然后以兄弟节点w右旋
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(w);
					w = x->parent->right;//重新设置兄弟节点
				}
				//情况4：x的兄弟节点w是黑色，且w的右孩子是红色
				//兄弟节点w的颜色变为父节点的颜色，父节点变为黑色，兄弟节点w的右孩子变为黑色，然后以父节点左旋
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(x->parent);
				x = root;//调整结束
			}
		}
		else {//对称的情况,x是右孩子
			w = x->parent->left;//x的兄弟节点
			if (w->color == RED) {//情况1：x的兄弟节点w是红色
				//兄弟节点w变为黑色，父节点变为红色，然后以父节点右旋
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				w = x->parent->left;//重新设置兄弟节点
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {//情况2：x的兄弟节点w是黑色，且w的两个孩子都是黑色
				//兄弟节点w变为红色，然后以父节点为当前节点，继续向上调整
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {//情况3：x的兄弟节点w是黑色，且w的右孩子是红色，左孩子是黑色
					//兄弟节点w的右孩子变为黑色，兄弟节点w变为红色，然后以兄弟节点w左旋
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(w);
					w = x->parent->left;//重新设置兄弟节点
				}
				//情况4：x的兄弟节点w是黑色，且w的左孩子是红色
				//兄弟节点w的颜色变为父节点的颜色，父节点变为黑色，兄弟节点w的左孩子变为黑色，然后以父节点右旋
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(x->parent);
				x = root;//调整结束
			}
		}
	}
	x->color = BLACK;//最后将x设为黑色
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