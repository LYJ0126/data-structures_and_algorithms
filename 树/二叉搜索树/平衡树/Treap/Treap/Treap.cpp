#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include <climits>

using namespace std;

#define maxn 100010
#define INF 2147483647
// Treap
// Treap是一种二叉搜索树，它的每个节点都有一个随机优先级，满足二叉搜索树的性质，即左子树的值小于根节点的值，右子树的值大于根节点的值。
// 同时，Treap还满足堆的性质，即根节点的优先级大于左右子树的优先级。
// Treap的插入和删除操作都是O(logn)的，但是由于随机优先级的存在，Treap的平衡性不如AVL树和红黑树，但是在实际应用中，Treap的性能表现是非常好的。
// Treap的插入操作是先按照二叉搜索树的性质插入，然后根据随机优先级进行旋转操作，使得树保持平衡。
// Treap的删除操作是先按照二叉搜索树的性质删除，然后根据随机优先级进行旋转操作，使得树保持平衡。
// Treap的查询操作是按照二叉搜索树的性质进行查询。
struct node {
	int left, right;//左右儿子
	int value;//值
	int cnt;//相同值的个数
	int size;//子树大小
	int level;//随机优先级
}tree[maxn];
int tot = 1;//节点总数

void pushup(int p) {//更新节点子树大小信息
	tree[p].size = tree[tree[p].left].size + tree[tree[p].right].size + tree[p].cnt;
}

//旋转
void rotate(int& id, bool dir)
{
	if (dir == 0) {//左旋
		int rightnodes = tree[id].right;//保存右节点
		tree[id].right = tree[rightnodes].left;//右节点的左节点挂到当前节点的右节点
		tree[rightnodes].left = id;//当前节点挂到右节点的左节点
		pushup(id);//更新原根节点(现左节点)的size
		pushup(rightnodes);//更新原右节点(现根节点)的size
		id = rightnodes;//更新根节点
	}
	else {//右旋
		int leftnodes = tree[id].left;//保存左节点
		tree[id].left = tree[leftnodes].right;//左节点的右节点挂到当前节点的左节点
		tree[leftnodes].right = id;//当前节点挂到左节点的右节点
		pushup(id);//更新原根节点的size
		pushup(leftnodes);//更新原左节点(现根节点)的size
		id = leftnodes;//更新根节点
	}
}

//插入
void insert(int& id, int value)//插入值为value的节点
{
	if (id == 0) {//如果当前节点为空
		//新建节点
		tree[++tot].value = value;
		tree[tot].cnt = 1;
		tree[tot].size = 1;
		tree[tot].level = rand();
		id = tot;
		return;
	}
	if (tree[id].value == value) {//如果当前节点的值等于value
		tree[id].cnt++;//当前节点的cnt++
		pushup(id);//更新当前节点的size
		return;
	}
	if (value < tree[id].value) {//如果value小于当前节点的值
		insert(tree[id].left, value);//递归插入左子树
		if (tree[tree[id].left].level > tree[id].level) rotate(id, 1);//如果左子树的优先级大于当前节点的优先级，右旋
	}
	else {//如果value大于当前节点的值
		insert(tree[id].right, value);//递归插入右子树
		if (tree[tree[id].right].level > tree[id].level) rotate(id, 0);//如果右子树的优先级大于当前节点的优先级，左旋
	}
	pushup(id);//更新当前节点的size
}

//删除
void remove(int& id, int value)//删除值为value的节点
{
	if (id == 0) return;//如果当前节点为空，直接返回
	if (tree[id].value == value) {//如果当前节点的值等于value,找到了要删除的节点
		if (tree[id].cnt > 1) {//该点不止一个，直接减少cnt
			tree[id].cnt--;//当前节点的cnt--
			pushup(id);//更新当前节点的size
			return;
		}
		//如果该点只有一个，删除该点
		if (tree[id].left == 0 || tree[id].right == 0) {//如果当前节点的左右子树有一个为空或者都为空
			id = tree[id].left + tree[id].right;//当前节点等于左右子树的非空节点,即用左右子树的非空根节点替换当前节点
			return;
		}
		//如果当前节点的左右子树都不为空
		if (tree[tree[id].left].level > tree[tree[id].right].level) {//如果左子树的优先级大于右子树的优先级
			rotate(id, 1);//右旋
			remove(tree[id].right, value);//递归删除
		}
		else {//如果右子树的优先级大于左子树的优先级
			rotate(id, 0);//左旋
			remove(tree[id].left, value);//递归删除
		}
	}
	else if (value < tree[id].value) remove(tree[id].left, value);//如果value小于当前节点的值，递归删除左子树
	else remove(tree[id].right, value);//如果value大于当前节点的值，递归删除右子树
	pushup(id);//更新当前节点的size
}


//查询
int queryrank(int id, int value)//查询值value的排名
{
	if (id == 0) return 1;//如果当前节点为空，返回1。因为若数值不在树中，数自身要算一个
	if (tree[id].value == value) return tree[tree[id].left].size + 1;//如果当前节点的值等于value，返回左子树的size+1
	if (value < tree[id].value) return queryrank(tree[id].left, value);//如果value小于当前节点的值，递归查询左子树
	else return tree[tree[id].left].size + tree[id].cnt + queryrank(tree[id].right, value);//如果value大于当前节点的值，返回左子树的size+当前节点的cnt+递归查询右子树
}

int queryvalue(int id, int rank)//查询排名为rank的节点的值
{
	if (id == 0) {
		cout<<"No such node!"<<endl;//如果当前节点为空，输出"No such node!
		return 0;//如果当前节点为空，返回0
	}
	if (tree[tree[id].left].size >= rank) return queryvalue(tree[id].left, rank);//如果左子树的size大于等于rank，递归查询左子树
	else if (tree[tree[id].left].size + tree[id].cnt >= rank) return tree[id].value;//如果左子树的size+当前节点的cnt大于等于rank，返回当前节点的值
	else return queryvalue(tree[id].right, rank - tree[tree[id].left].size - tree[id].cnt);//返回右子树的rank
}

int querynum(int id, int value)//查询值为value的节点的个数
{
	if (id == 0) return 0;//如果当前节点为空，返回0
	else if (tree[id].value == value) return tree[id].cnt;//如果当前节点的值等于value，返回当前节点的cnt
	else if (value < tree[id].value) return querynum(tree[id].left, value);//如果value小于当前节点的值，递归查询左子树
	else return querynum(tree[id].right, value);//如果value大于当前节点的值，递归查询右子树
}

int querypre(int id, int value)//查询值为value的节点的前驱
{
	if (id == 0) return -INF;//找不到该节点(实际上是递归结束了),此时为了维护最大值 返回负无穷
	if (tree[id].value >= value) return querypre(tree[id].left, value);//如果当前节点的值大于等于value，递归查询左子树
	else return max(tree[id].value, querypre(tree[id].right, value));//如果当前节点的值小于value，返回当前节点的值和递归查询右子树的最大值
}

int querysuc(int id, int value)//查询值为value的节点的后继
{
	if (id == 0) return INF;//找不到该节点(实际上是递归结束了),此时为了维护最小值 返回正无穷
	if (tree[id].value <= value) return querysuc(tree[id].right, value);//如果当前节点的值小于等于value，递归查询右子树
	else return min(tree[id].value, querysuc(tree[id].left, value));//如果当前节点的值大于value，返回当前节点的值和递归查询左子树的最小值
}

void preorder(int id)//前序遍历
{
	if (id == 0) return;
	for(int i = 0; i < tree[id].cnt; i++) cout << tree[id].value << " ";
	preorder(tree[id].left);
	preorder(tree[id].right);
}

void inorder(int id)//中序遍历
{
	if (id == 0) return;
	inorder(tree[id].left);
	for(int i = 0; i < tree[id].cnt; i++) cout << tree[id].value << " ";
	inorder(tree[id].right);
}

void postorder(int id)//后序遍历
{
	if (id == 0) return;
	postorder(tree[id].left);
	postorder(tree[id].right);
	for(int i = 0; i < tree[id].cnt; i++) cout << tree[id].value << " ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	int n, root = 1;
	cin >> n;
	//初始化根节点(哑节点)
	tree[root].value = -INF;
	tree[root].size = 0;
	tree[root].level = INT_MAX;
	tree[root].cnt = 0;
	tree[root].left = tree[root].right = 0;
	for (int i = 1; i <= n; i++)
	{
		int op, x;
		cin >> op >> x;
		if (op == 1) insert(root, x);
		else if (op == 2) remove(root, x);
		else if (op == 3) printf("%d\n", queryrank(root, x));
		else if (op == 4) printf("%d\n", queryvalue(root, x));
		else if (op == 5) printf("%d\n", querypre(root, x));
		else if (op == 6) printf("%d\n", querysuc(root, x));
		else printf("%d\n", querysuc(root, x));
	}
	return 0;
}