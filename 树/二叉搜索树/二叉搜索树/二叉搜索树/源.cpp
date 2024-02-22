#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//构建结点
typedef struct node
{
	int key;
	node* left;
	node* right;
	node* p;
}node;
//中序遍历
void inorder(node* ptr)
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		cout << ptr->key << ' ';
		inorder(ptr->right);
	}
}
//查找某个键值对应结点（递归写法）
node* search(node* ptr, int k)
{
	if (ptr == nullptr) {
		cout << "There is no such node whose key is ." << k << endl;
		return NULL;
	}
	if (ptr->key == k) return ptr;
	if (k < ptr->key) {
		return search(ptr->left, k);
	}
	else return search(ptr->right, k);
}
//查找某个键值对应结点（循环写法）
node* search2(node* ptr, int k) {
	while (ptr != nullptr && k != ptr->key) {
		if (k < ptr->key) ptr = ptr->left;
		else ptr = ptr->right;
	}
	if (ptr == nullptr) {
		cout << "There is no such node whose key is ." << k << endl;
		return NULL;
	}
	else return ptr;
}
//查找最小值对应结点
node* findmin(node* ptr) {
	while (ptr->left != nullptr) {
		ptr = ptr->left;
	}
	return ptr;
}
//查找最大值对应结点
node* findmax(node* ptr)
{
	while (ptr->right != nullptr) {
		ptr = ptr->right;
	}
	return ptr;
}
//查找前驱
node* pre(node* ptr)
{
	if (ptr == nullptr) return nullptr;
	if (ptr->left != nullptr) return findmax(ptr->left);
	else {
		node* y = ptr->p;
		while (y != nullptr && y->left == ptr) {//ptr如果是其父亲结点的左子结点，那么父亲结点是后于它的。知道找到
			                                    //父亲结点右结点是它时，该父亲结点才是先于它。
			ptr = y;
			y = ptr->p;
		}
		return y;//如果返回的为空，说明开始ptr是键值最小的结点
	}
}
//查找后继
node* suc(node* ptr)
{
	if (ptr == nullptr) return nullptr;
	if (ptr->right != nullptr) return findmin(ptr->right);
	else {
		node* y = ptr->p;
		while (y != nullptr && y->right == ptr) {//类似上面，ptr如果是其父亲结点的右子结点，那么父亲结点是先于它的。
												//父亲结点左结点是它时，该父亲结点才是后于它。
			ptr = y;
			y = ptr->p;
		}
		return y;
	}
}
//插入结点
void insertnode(node*& root, node*& ptr)
{
	node* y=nullptr;//y保存中间变量的父亲结点
	node* x = root;//中间变量
	while (x != nullptr) {
		y = x;
		if (ptr->key < x->key) {
			x = x->left;
		}
		else x = x->right;
	}
	//插入操作
	ptr->p = y;
	if (y == nullptr) {
		root = ptr;//树为空时情况
	}
	else if (ptr->key < y->key) y->left = ptr;
	else y->right = ptr;
}
//子树替换
/*void transplant(node*& root, node*& u, node*& v)
{
	if (u->p = nullptr) root = v;//当u为根结点时
	else if (u == u->p->left) u->p->left = v;//当u为其父亲结点的左子结点时
	else u->p->right = v;//当u为其父亲结点的右子结点时
	if (v != nullptr) v->p = u->p;
}
//删除结点
void deletenode(node* &root, node* &ptr)
{
	if (ptr->left = nullptr) transplant(root, ptr, ptr->right);//没有左子树，直接右子树替换该结点
	else if (ptr->right = nullptr) transplant(root, ptr, ptr->left);//没有右子树，直接左子树替换该结点
	else {//左右子树都有时
		node* y = findmin(ptr->right);//右子树结点比左子树大，替换ptr位置的结点应该是右子树中最小的那个（ptr后继）
		if (y->p != ptr) {//y不是ptr的右子结点
			transplant(root, y, y->right);//y等一下要到上面去替换ptr位置，所以y右子树接替y（y肯定没有左子树）
										  //同时y要与新的右子树连接（新的右子树是ptr的右子树）
			y->right = ptr->right;
			y->right->p = y;
		}
		//此时已经转换成了y是ptr右子结点的情况，y替换ptr即可
		transplant(root, ptr, y);
		y->left = ptr->left;
		y->left->p = y;//与原来ptr左子树连接
	}
	delete ptr;//注意释放空间
}*/
//删除结点
bool Remove(node*& ptr, int kx)
{
	if (nullptr == ptr) return false;
	node* temp = ptr;
	while (temp != nullptr && temp->key != kx) {//查找键kx对应的结点
		temp = kx < temp->key ? temp->left : temp->right;
	}
	if (temp == nullptr) return false;
	if (temp->left != nullptr && temp->right != nullptr) {//左右子树都有
		node* last = findmin(temp->right);//其后继将会替换该结点
		temp->key = last->key;
		temp = last;
	}
	node* pa = temp->p;
	node* child = temp->left != nullptr ? temp->left : temp->right;//当只有一个子树时，子树替换该结点
	if (child != nullptr) child->p = pa;
	if (pa == nullptr) pa = child;
	else {
		if (pa->left == temp) {
			pa->left = child;
		}
		else pa->right = child;
	}
	delete temp;
	return true;
}

//释放空间
void deletetree(node* ptr)
{
	if (ptr != nullptr) {
		deletetree(ptr->left);
		deletetree(ptr->right);
		delete ptr;
	}
}

int main()
{
	int key, n;
	cin >> n;
	node* root = nullptr;//初始创建根为空
	//建立二叉搜索树
	for (int i = 1; i <= n; i++) {
		cin >> key;
		node*p = new node;//申请空间
		p->left = nullptr;
		p->right = nullptr;
		p->p = nullptr;
		p->key = key;
		insertnode(root, p);
	}
	inorder(root);//中序遍历，上面整个也相当于树排序
	cout << "\n";
	cout << "What key do you want to find?" << endl;
	cin >> key;
	node* ans = search2(root, key);
	cout << ans->key << endl;
	node* minimum = findmin(root);
	node* maximum = findmax(root);
	cout << "The min key is " << minimum->key << endl;
	cout << "The max key is " << maximum->key << endl;
	cout << "Whose predecessor do you want to find?" << endl;
	cin >> key;
	node* temp1 = search2(root, key);
	node* predecessor = pre(temp1);
	if(predecessor) cout << predecessor->key << endl;
	cout << "Whose successor do you want to find?" << endl;
	cin >> key;
	node* temp2 = search2(root, key);
	node* successor = suc(temp2);
	if(successor) cout << successor->key << endl;
	cout << "What key do you want to insert?" << endl;
	cin >> key;
	node* temp3 = new node;
	temp3->key = key;
	temp3->left = nullptr;
	temp3->right = nullptr;
	temp3->p = nullptr;
	insertnode(root,temp3);
	n++;
	inorder(root);
	cout << "\n";
	cout << "What key do you want to delete?" << endl;
	cin >> key;
	bool flag = Remove(root, key);
	if (flag) cout<<"Delete successfully!"<<endl;
	else cout<<"Delete failed!"<<endl;
	n--;
	inorder(root);
	cout << "\n";
	cout << "Now, there are " << n << " nodes";
	//释放空间
	deletetree(root);
	return 0;
}