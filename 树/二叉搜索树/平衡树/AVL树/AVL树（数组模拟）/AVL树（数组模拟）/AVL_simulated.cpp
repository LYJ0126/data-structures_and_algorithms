
//数组模拟AVL树
#include<iostream>
#include<cmath>
using namespace std;

#define INF 2147483647
const int maxn = 100001;
//tree[]为树中的元素，height[]为树中节点的高度，Size[]为树中节点的大小，num[]为相同元素的个数
//leftchild[]为树中节点的左儿子，rightchild[]为树中节点的右儿子,cnt为树中节点的个数
int tree[maxn], height[maxn], Size[maxn], leftchild[maxn], rightchild[maxn], num[maxn], cnt = 0;

void update(int x) {//更新节点x的高度和子树大小
	height[x] = max(height[leftchild[x]], height[rightchild[x]]) + 1;
	Size[x] = Size[leftchild[x]] + Size[rightchild[x]] + num[x];
}

void RightRotation(int &x) {//右旋(对应情况LL)
	int y = leftchild[x];//y指向x的左儿子
	leftchild[x] = rightchild[y];//y的右儿子挂到x的左儿子
	rightchild[y] = x;//x成为y的右儿子
	update(x);//更新x
	update(y);//更新y
	x = y;//更新根节点
}

void LeftRotation(int &x) {//左旋(对应情况RR)
	int y = rightchild[x];//y指向x的右儿子
	rightchild[x] = leftchild[y];//y的左儿子挂到x的右儿子
	leftchild[y] = x;//x成为y的左儿子
	update(x);//更新x
	update(y);//更新y
	x = y;//更新根节点
}

void LeftRightRotation(int &x) {//左右旋(对应情况LR)
	LeftRotation(leftchild[x]);//先左旋x的左儿子
	RightRotation(x);//再右旋x
}

void RightLeftRotation(int &x) {//右左旋(对应情况RL)
	RightRotation(rightchild[x]);//先右旋x的右儿子
	LeftRotation(x);//再左旋x
}

void insert(int &x, int v) {//插入元素v
	if (x == 0) {//如果x为空
		x = ++cnt;//新建节点
		tree[x] = v;//节点值为v
		num[x] = 1;//节点个数为1
		Size[x] = 1;//节点大小为1
		height[x] = 1;//节点高度为1
		leftchild[x] = rightchild[x] = 0;//左右儿子为空
		return;
	}
	if (v == tree[x]) {//如果v等于x的值
		num[x]++;//x的个数加1
		update(x);//更新x的高度和子树大小
		return;
	}
	if (v < tree[x]) {//如果v小于x的值
		insert(leftchild[x], v);//插入到x的左儿子
		if (height[leftchild[x]] - height[rightchild[x]] == 2) {//如果左儿子的高度比右儿子的高度大2
			if (v < tree[leftchild[x]])//如果v小于左儿子的值
				RightRotation(x);//右旋x(对应情况LL)
			else
				LeftRightRotation(x);//左右旋x(对应情况LR)
		}
	}
	else {//如果v大于x的值
		insert(rightchild[x], v);//插入到x的右儿子
		if (height[rightchild[x]] - height[leftchild[x]] == 2) {//如果右儿子的高度比左儿子的高度大2
			if (v > tree[rightchild[x]])//如果v大于右儿子的值
				LeftRotation(x);//左旋x(对应情况RR)
			else
				RightLeftRotation(x);//右左旋x(对应情况RL)
		}
	}
	update(x);//更新x的高度和子树大小
}

int findmin(int x) {//查找最小值
	while (leftchild[x])//一直往左儿子走
		x = leftchild[x];
	return tree[x];
}

int findmax(int x) {//查找最大值
	while (rightchild[x])//一直往右儿子走
		x = rightchild[x];
	return tree[x];
}

int minimum(int x) {//查找最小值对应的编号
	while (leftchild[x])//一直往左儿子走
		x = leftchild[x];
	return x;
}

int maximum(int x) {//查找最大值对应的编号
	while (rightchild[x])//一直往右儿子走
		x = rightchild[x];
	return x;
}

//递归查找
int search(int x, int v)
{
	if (!x) return 0;
	if (tree[x] == v) return x;
	else if (v < tree[x]) return search(leftchild[x], v);
	else return search(rightchild[x], v);
}
//非递归查找
int iterativesearch(int x, int v)
{
	while (x) {
		if (tree[x] == v) return x;
		else if (v < tree[x]) x = leftchild[x];
		else x = rightchild[x];
	}
}

void removeid(int& x, int id, int removenum)//删除编号为id的节点
{
	if(x==0 || id==0) return;//当前节点为空
	if (tree[id] < tree[x]) {
		removeid(leftchild[x], id, removenum);//删除左子树中对应节点
		//删除后，若AVL树失衡，则进行相应的平衡操作
		if (height[rightchild[x]] - height[leftchild[x]] == 2) {
			int temp = rightchild[x];
			if (height[leftchild[temp]] > height[rightchild[temp]]) {//RL
				RightLeftRotation(x);
			}
			else {//RR
				LeftRotation(x);
			}
		}
	}
	else if (tree[id] > tree[x]) {
		removeid(rightchild[x], id, removenum);//删除右子树中对应的节点
		//删除后，若AVL树失衡，则进行相应的平衡操作
		if (height[leftchild[x]] - height[rightchild[x]] == 2) {
			int temp = leftchild[x];
			if (height[rightchild[temp]] > height[leftchild[temp]]) {//LR
				LeftRightRotation(x);
			}
			else {//LL
				RightRotation(x);
			}
		}
	}
	else {
		if (num[x] > removenum) num[x] -= removenum;//该节点不只一个，直接减少节点数量
		else {
			if (leftchild[x] && rightchild[x]) {//有两个子节点
				if (height[leftchild[x]] > height[rightchild[x]]) {//左子树高度大于右子树高度
					int k = maximum(leftchild[x]);//找到左子树中的最大值
					tree[x] = tree[k];//将最大值赋给x
					num[x] = num[k];//更新x的个数
					//if (leftchild[0] == x) leftchild[0] = k;//如果删除的是根节点，需要更新根节点
					removeid(leftchild[x], k, num[k]);//删除左子树中的最大值,注意这里是删除num[k]个节点，全部删除
				}
				else {//右子树高度大于等于左子树高度
					int k = minimum(rightchild[x]);//找到右子树中的最小值
					tree[x] = tree[k];//将最小值赋给x
					num[x] = num[k];//更新x的个数
					//if (leftchild[0] == x) leftchild[0] = k;//如果删除的是根节点，需要更新根节点
					removeid(rightchild[x], k, num[k]);//删除右子树中的最小值，注意这里是删除num[k]个节点，全部删除
				}
			}
			else {//只有一个子节点或没有子节点
				//int temp = x;
				if (leftchild[x] == 0) x = rightchild[x];//左子树为空，右子树代替x
				else if (rightchild[x] == 0) x = leftchild[x];//右子树为空，左子树代替x
				//delete temp;//删除节点
			}
		}
	}
	if (x) update(x);//更新x的高度和子树大小
}

void remove(int& x, int key)
{
	int z;
	int tempx = x;
	if ((z = iterativesearch(x, key)) != 0) {
		removeid(x, z, 1);
		//cout << "x:" << x << endl;
	}
	else cout << "The node is not in the tree!" << endl;//"树中没有这个节点！"
}

void preorder(int x) {//先序遍历
	if (x == 0) return;
	for(int i=0;i<num[x];i++)
		cout << tree[x] << " ";
	preorder(leftchild[x]);
	preorder(rightchild[x]);
}

void inorder(int x) {//中序遍历
	if (x == 0) return;
	inorder(leftchild[x]);
	for(int i=0;i<num[x];i++)
		cout << tree[x] << " ";
	inorder(rightchild[x]);
}

void postorder(int x) {//后序遍历
	if (x == 0) return;
	postorder(leftchild[x]);
	postorder(rightchild[x]);
	for(int i=0;i<num[x];i++)
		cout << tree[x] << " ";
}

int predecessor(int x, int v) {//查找前驱
	if (x == 0) return -INF;//没有前驱
	if (tree[x] >= v) return predecessor(leftchild[x], v);//如果当前节点的值大于等于value，递归查询左子树
	else return max(tree[x], predecessor(rightchild[x], v));////如果当前节点的值小于value，返回当前节点的值和递归查询右子树的最大值
}

int successor(int x, int v) {//查找后继
	if (x == 0) return INF;//没有后继
	if (tree[x] <= v) return successor(rightchild[x], v);//如果当前节点的值小于等于value，递归查询右子树
	else return min(tree[x], successor(leftchild[x], v));//如果当前节点的值大于value，返回当前节点的值和递归查询左子树的最小值
}

void print(int x, int key, int direction) {//打印树
	if (x) {
		if (direction == 0) cout << tree[x] << " is root" << endl;
		else cout << tree[x] << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << endl;
		print(leftchild[x], tree[x], -1);
		print(rightchild[x], tree[x], 1);
	}
}

int queryrank(int x, int v) {//查询排名
	if (x == 0) return 1;//如果当前节点为空，返回1。因为若数值不在树中，数自身要算一个
	if (v == tree[x]) return Size[leftchild[x]] + 1;//如果当前节点的值等于value，返回左子树的大小+1
	if (v < tree[x]) return queryrank(leftchild[x], v);//如果当前节点的值大于value，递归查询左子树
	else return Size[leftchild[x]] + num[x] + queryrank(rightchild[x], v);//如果当前节点的值小于value，返回左子树的大小+当前节点的个数+递归查询右子树
}

int queryvalue(int x, int k) {//查询排名为k的数
	if (x == 0) {
		cout<<"No such node!"<<endl;//"没有这样的节点！
		return INF;//如果当前节点为空，返回INF
	}
	if (Size[leftchild[x]] >= k) return queryvalue(leftchild[x], k);//如果左子树的大小大于等于k，递归查询左子树
	if (Size[leftchild[x]] + num[x] >= k) return tree[x];//如果左子树的大小+当前节点的个数大于等于k，返回当前节点的值
	return queryvalue(rightchild[x], k - Size[leftchild[x]] - num[x]);//否则递归查询右子树,并且k要减去左子树的大小和当前节点的个数
}

int querynum(int x, int v) {//查询数值为v的个数
	if (x == 0) return 0;//如果当前节点为空，返回0
	if (v == tree[x]) return num[x];//如果当前节点的值等于value，返回当前节点的个数
	if (v < tree[x]) return querynum(leftchild[x], v);//如果当前节点的值大于value，递归查询左子树
	else return querynum(rightchild[x], v);//如果当前节点的值小于value，递归查询右子树
}

int main()
{
	int n, key;
	cin >> n;
	//创建哑节点
	tree[0] = 0;
	height[0] = 0;
	Size[0] = 0;
	leftchild[0] = 0;
	rightchild[0] = 0;
	num[0] = 0;
	//逐个插入，构建AVL树。以哑节点的左儿子为根节点
	//1 2 3 4 6 7 8 9 11 24
	for (int i = 0; i < n; i++) {
		cin >> key;
		insert(leftchild[0], key);
	}
	//先序遍历
	cout << "Preorder:" << endl;
	preorder(leftchild[0]);
	cout << endl;
	//中序遍历
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//后序遍历
	cout << "Postorder:" << endl;
	postorder(leftchild[0]);
	cout << endl;
	//查询最小值
	cout << "The minimum value is:" << findmin(leftchild[0]) << endl;
	//查询最大值
	cout << "The maximum value is:" << findmax(leftchild[0]) << endl;
	//查询前驱
	cout << "The predecessor of 11 is:" << predecessor(leftchild[0], 11) << endl;
	//查询后继
	cout << "The successor of 4 is:" << successor(leftchild[0], 4) << endl;
	//查询排名
	cout << "The rank of 6 is:" << queryrank(leftchild[0], 6) << endl;
	//查询排名为10的数
	cout << "The value of rank 10 is:" << queryvalue(leftchild[0], 10) << endl;
	//查询数值为6的个数
	cout << "The number of 6 is:" << querynum(leftchild[0], 6) << endl;
	//删除数值为6的节点
	cout<<"Remove 6"<<endl;
	remove(leftchild[0], 6);
	//中序遍历
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//打印树信息
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//插入3个数值为5的节点
	cout<<"Insert 5 5 5"<<endl;
	insert(leftchild[0], 5);
	insert(leftchild[0], 5);
	insert(leftchild[0], 5);
	//中序遍历
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//查询数值为5的个数
	cout << "The number of 5 is:" << querynum(leftchild[0], 5) << endl;
	//打印树信息
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//删除数值为9的节点
	cout<<"Remove 9"<<endl;
	remove(leftchild[0], 9);
	//中序遍历
	cout<<"Inorder:"<<endl;
	inorder(leftchild[0]);
	cout<<endl;
	//打印树信息
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//删除根节点
	cout << "Remove root : " << leftchild[0] << endl;
	remove(leftchild[0], tree[leftchild[0]]);
	//中序遍历
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//打印树信息
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//查询5的排名
	cout << "The rank of 5 is:" << queryrank(leftchild[0], 5) << endl;
	//查询排名为5的数
	cout << "The value of rank 6 is:" << queryvalue(leftchild[0], 6) << endl;
	//查询数值为5的个数
	cout << "The number of 5 is:" << querynum(leftchild[0], 5) << endl;
	return 0;
}