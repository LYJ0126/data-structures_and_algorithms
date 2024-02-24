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
// Treap��һ�ֶ���������������ÿ���ڵ㶼��һ��������ȼ���������������������ʣ�����������ֵС�ڸ��ڵ��ֵ����������ֵ���ڸ��ڵ��ֵ��
// ͬʱ��Treap������ѵ����ʣ������ڵ�����ȼ������������������ȼ���
// Treap�Ĳ����ɾ����������O(logn)�ģ���������������ȼ��Ĵ��ڣ�Treap��ƽ���Բ���AVL���ͺ������������ʵ��Ӧ���У�Treap�����ܱ����Ƿǳ��õġ�
// Treap�Ĳ���������Ȱ��ն��������������ʲ��룬Ȼ�����������ȼ�������ת������ʹ��������ƽ�⡣
// Treap��ɾ���������Ȱ��ն���������������ɾ����Ȼ�����������ȼ�������ת������ʹ��������ƽ�⡣
// Treap�Ĳ�ѯ�����ǰ��ն��������������ʽ��в�ѯ��
struct node {
	int left, right;//���Ҷ���
	int value;//ֵ
	int cnt;//��ֵͬ�ĸ���
	int size;//������С
	int level;//������ȼ�
}tree[maxn];
int tot = 1;//�ڵ�����

void pushup(int p) {//���½ڵ�������С��Ϣ
	tree[p].size = tree[tree[p].left].size + tree[tree[p].right].size + tree[p].cnt;
}

//��ת
void rotate(int& id, bool dir)
{
	if (dir == 0) {//����
		int rightnodes = tree[id].right;//�����ҽڵ�
		tree[id].right = tree[rightnodes].left;//�ҽڵ����ڵ�ҵ���ǰ�ڵ���ҽڵ�
		tree[rightnodes].left = id;//��ǰ�ڵ�ҵ��ҽڵ����ڵ�
		pushup(id);//����ԭ���ڵ�(����ڵ�)��size
		pushup(rightnodes);//����ԭ�ҽڵ�(�ָ��ڵ�)��size
		id = rightnodes;//���¸��ڵ�
	}
	else {//����
		int leftnodes = tree[id].left;//������ڵ�
		tree[id].left = tree[leftnodes].right;//��ڵ���ҽڵ�ҵ���ǰ�ڵ����ڵ�
		tree[leftnodes].right = id;//��ǰ�ڵ�ҵ���ڵ���ҽڵ�
		pushup(id);//����ԭ���ڵ��size
		pushup(leftnodes);//����ԭ��ڵ�(�ָ��ڵ�)��size
		id = leftnodes;//���¸��ڵ�
	}
}

//����
void insert(int& id, int value)//����ֵΪvalue�Ľڵ�
{
	if (id == 0) {//�����ǰ�ڵ�Ϊ��
		//�½��ڵ�
		tree[++tot].value = value;
		tree[tot].cnt = 1;
		tree[tot].size = 1;
		tree[tot].level = rand();
		id = tot;
		return;
	}
	if (tree[id].value == value) {//�����ǰ�ڵ��ֵ����value
		tree[id].cnt++;//��ǰ�ڵ��cnt++
		pushup(id);//���µ�ǰ�ڵ��size
		return;
	}
	if (value < tree[id].value) {//���valueС�ڵ�ǰ�ڵ��ֵ
		insert(tree[id].left, value);//�ݹ����������
		if (tree[tree[id].left].level > tree[id].level) rotate(id, 1);//��������������ȼ����ڵ�ǰ�ڵ�����ȼ�������
	}
	else {//���value���ڵ�ǰ�ڵ��ֵ
		insert(tree[id].right, value);//�ݹ����������
		if (tree[tree[id].right].level > tree[id].level) rotate(id, 0);//��������������ȼ����ڵ�ǰ�ڵ�����ȼ�������
	}
	pushup(id);//���µ�ǰ�ڵ��size
}

//ɾ��
void remove(int& id, int value)//ɾ��ֵΪvalue�Ľڵ�
{
	if (id == 0) return;//�����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
	if (tree[id].value == value) {//�����ǰ�ڵ��ֵ����value,�ҵ���Ҫɾ���Ľڵ�
		if (tree[id].cnt > 1) {//�õ㲻ֹһ����ֱ�Ӽ���cnt
			tree[id].cnt--;//��ǰ�ڵ��cnt--
			pushup(id);//���µ�ǰ�ڵ��size
			return;
		}
		//����õ�ֻ��һ����ɾ���õ�
		if (tree[id].left == 0 || tree[id].right == 0) {//�����ǰ�ڵ������������һ��Ϊ�ջ��߶�Ϊ��
			id = tree[id].left + tree[id].right;//��ǰ�ڵ�������������ķǿսڵ�,�������������ķǿո��ڵ��滻��ǰ�ڵ�
			return;
		}
		//�����ǰ�ڵ��������������Ϊ��
		if (tree[tree[id].left].level > tree[tree[id].right].level) {//��������������ȼ����������������ȼ�
			rotate(id, 1);//����
			remove(tree[id].right, value);//�ݹ�ɾ��
		}
		else {//��������������ȼ����������������ȼ�
			rotate(id, 0);//����
			remove(tree[id].left, value);//�ݹ�ɾ��
		}
	}
	else if (value < tree[id].value) remove(tree[id].left, value);//���valueС�ڵ�ǰ�ڵ��ֵ���ݹ�ɾ��������
	else remove(tree[id].right, value);//���value���ڵ�ǰ�ڵ��ֵ���ݹ�ɾ��������
	pushup(id);//���µ�ǰ�ڵ��size
}


//��ѯ
int queryrank(int id, int value)//��ѯֵvalue������
{
	if (id == 0) return 1;//�����ǰ�ڵ�Ϊ�գ�����1����Ϊ����ֵ�������У�������Ҫ��һ��
	if (tree[id].value == value) return tree[tree[id].left].size + 1;//�����ǰ�ڵ��ֵ����value��������������size+1
	if (value < tree[id].value) return queryrank(tree[id].left, value);//���valueС�ڵ�ǰ�ڵ��ֵ���ݹ��ѯ������
	else return tree[tree[id].left].size + tree[id].cnt + queryrank(tree[id].right, value);//���value���ڵ�ǰ�ڵ��ֵ��������������size+��ǰ�ڵ��cnt+�ݹ��ѯ������
}

int queryvalue(int id, int rank)//��ѯ����Ϊrank�Ľڵ��ֵ
{
	if (id == 0) {
		cout<<"No such node!"<<endl;//�����ǰ�ڵ�Ϊ�գ����"No such node!
		return 0;//�����ǰ�ڵ�Ϊ�գ�����0
	}
	if (tree[tree[id].left].size >= rank) return queryvalue(tree[id].left, rank);//�����������size���ڵ���rank���ݹ��ѯ������
	else if (tree[tree[id].left].size + tree[id].cnt >= rank) return tree[id].value;//�����������size+��ǰ�ڵ��cnt���ڵ���rank�����ص�ǰ�ڵ��ֵ
	else return queryvalue(tree[id].right, rank - tree[tree[id].left].size - tree[id].cnt);//������������rank
}

int querynum(int id, int value)//��ѯֵΪvalue�Ľڵ�ĸ���
{
	if (id == 0) return 0;//�����ǰ�ڵ�Ϊ�գ�����0
	else if (tree[id].value == value) return tree[id].cnt;//�����ǰ�ڵ��ֵ����value�����ص�ǰ�ڵ��cnt
	else if (value < tree[id].value) return querynum(tree[id].left, value);//���valueС�ڵ�ǰ�ڵ��ֵ���ݹ��ѯ������
	else return querynum(tree[id].right, value);//���value���ڵ�ǰ�ڵ��ֵ���ݹ��ѯ������
}

int querypre(int id, int value)//��ѯֵΪvalue�Ľڵ��ǰ��
{
	if (id == 0) return -INF;//�Ҳ����ýڵ�(ʵ�����ǵݹ������),��ʱΪ��ά�����ֵ ���ظ�����
	if (tree[id].value >= value) return querypre(tree[id].left, value);//�����ǰ�ڵ��ֵ���ڵ���value���ݹ��ѯ������
	else return max(tree[id].value, querypre(tree[id].right, value));//�����ǰ�ڵ��ֵС��value�����ص�ǰ�ڵ��ֵ�͵ݹ��ѯ�����������ֵ
}

int querysuc(int id, int value)//��ѯֵΪvalue�Ľڵ�ĺ��
{
	if (id == 0) return INF;//�Ҳ����ýڵ�(ʵ�����ǵݹ������),��ʱΪ��ά����Сֵ ����������
	if (tree[id].value <= value) return querysuc(tree[id].right, value);//�����ǰ�ڵ��ֵС�ڵ���value���ݹ��ѯ������
	else return min(tree[id].value, querysuc(tree[id].left, value));//�����ǰ�ڵ��ֵ����value�����ص�ǰ�ڵ��ֵ�͵ݹ��ѯ����������Сֵ
}

void preorder(int id)//ǰ�����
{
	if (id == 0) return;
	for(int i = 0; i < tree[id].cnt; i++) cout << tree[id].value << " ";
	preorder(tree[id].left);
	preorder(tree[id].right);
}

void inorder(int id)//�������
{
	if (id == 0) return;
	inorder(tree[id].left);
	for(int i = 0; i < tree[id].cnt; i++) cout << tree[id].value << " ";
	inorder(tree[id].right);
}

void postorder(int id)//�������
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
	//��ʼ�����ڵ�(�ƽڵ�)
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