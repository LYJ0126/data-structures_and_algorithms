#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//�������
typedef struct node
{
	int key;
	node* left;
	node* right;
	node* p;
}node;
//�������
void inorder(node* ptr)
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		cout << ptr->key << ' ';
		inorder(ptr->right);
	}
}
//����ĳ����ֵ��Ӧ��㣨�ݹ�д����
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
//����ĳ����ֵ��Ӧ��㣨ѭ��д����
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
//������Сֵ��Ӧ���
node* findmin(node* ptr) {
	while (ptr->left != nullptr) {
		ptr = ptr->left;
	}
	return ptr;
}
//�������ֵ��Ӧ���
node* findmax(node* ptr)
{
	while (ptr->right != nullptr) {
		ptr = ptr->right;
	}
	return ptr;
}
//����ǰ��
node* pre(node* ptr)
{
	if (ptr == nullptr) return nullptr;
	if (ptr->left != nullptr) return findmax(ptr->left);
	else {
		node* y = ptr->p;
		while (y != nullptr && y->left == ptr) {//ptr������丸�׽������ӽ�㣬��ô���׽���Ǻ������ġ�֪���ҵ�
			                                    //���׽���ҽ������ʱ���ø��׽�������������
			ptr = y;
			y = ptr->p;
		}
		return y;//������ص�Ϊ�գ�˵����ʼptr�Ǽ�ֵ��С�Ľ��
	}
}
//���Һ��
node* suc(node* ptr)
{
	if (ptr == nullptr) return nullptr;
	if (ptr->right != nullptr) return findmin(ptr->right);
	else {
		node* y = ptr->p;
		while (y != nullptr && y->right == ptr) {//�������棬ptr������丸�׽������ӽ�㣬��ô���׽�����������ġ�
												//���׽����������ʱ���ø��׽����Ǻ�������
			ptr = y;
			y = ptr->p;
		}
		return y;
	}
}
//������
void insertnode(node*& root, node*& ptr)
{
	node* y=nullptr;//y�����м�����ĸ��׽��
	node* x = root;//�м����
	while (x != nullptr) {
		y = x;
		if (ptr->key < x->key) {
			x = x->left;
		}
		else x = x->right;
	}
	//�������
	ptr->p = y;
	if (y == nullptr) {
		root = ptr;//��Ϊ��ʱ���
	}
	else if (ptr->key < y->key) y->left = ptr;
	else y->right = ptr;
}
//�����滻
/*void transplant(node*& root, node*& u, node*& v)
{
	if (u->p = nullptr) root = v;//��uΪ�����ʱ
	else if (u == u->p->left) u->p->left = v;//��uΪ�丸�׽������ӽ��ʱ
	else u->p->right = v;//��uΪ�丸�׽������ӽ��ʱ
	if (v != nullptr) v->p = u->p;
}
//ɾ�����
void deletenode(node* &root, node* &ptr)
{
	if (ptr->left = nullptr) transplant(root, ptr, ptr->right);//û����������ֱ���������滻�ý��
	else if (ptr->right = nullptr) transplant(root, ptr, ptr->left);//û����������ֱ���������滻�ý��
	else {//������������ʱ
		node* y = findmin(ptr->right);//�������������������滻ptrλ�õĽ��Ӧ��������������С���Ǹ���ptr��̣�
		if (y->p != ptr) {//y����ptr�����ӽ��
			transplant(root, y, y->right);//y��һ��Ҫ������ȥ�滻ptrλ�ã�����y����������y��y�϶�û����������
										  //ͬʱyҪ���µ����������ӣ��µ���������ptr����������
			y->right = ptr->right;
			y->right->p = y;
		}
		//��ʱ�Ѿ�ת������y��ptr���ӽ��������y�滻ptr����
		transplant(root, ptr, y);
		y->left = ptr->left;
		y->left->p = y;//��ԭ��ptr����������
	}
	delete ptr;//ע���ͷſռ�
}*/
//ɾ�����
bool Remove(node*& ptr, int kx)
{
	if (nullptr == ptr) return false;
	node* temp = ptr;
	while (temp != nullptr && temp->key != kx) {//���Ҽ�kx��Ӧ�Ľ��
		temp = kx < temp->key ? temp->left : temp->right;
	}
	if (temp == nullptr) return false;
	if (temp->left != nullptr && temp->right != nullptr) {//������������
		node* last = findmin(temp->right);//���̽����滻�ý��
		temp->key = last->key;
		temp = last;
	}
	node* pa = temp->p;
	node* child = temp->left != nullptr ? temp->left : temp->right;//��ֻ��һ������ʱ�������滻�ý��
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

//�ͷſռ�
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
	node* root = nullptr;//��ʼ������Ϊ��
	//��������������
	for (int i = 1; i <= n; i++) {
		cin >> key;
		node*p = new node;//����ռ�
		p->left = nullptr;
		p->right = nullptr;
		p->p = nullptr;
		p->key = key;
		insertnode(root, p);
	}
	inorder(root);//�����������������Ҳ�൱��������
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
	//�ͷſռ�
	deletetree(root);
	return 0;
}