
//����ģ��AVL��
#include<iostream>
#include<cmath>
using namespace std;

#define INF 2147483647
const int maxn = 100001;
//tree[]Ϊ���е�Ԫ�أ�height[]Ϊ���нڵ�ĸ߶ȣ�Size[]Ϊ���нڵ�Ĵ�С��num[]Ϊ��ͬԪ�صĸ���
//leftchild[]Ϊ���нڵ������ӣ�rightchild[]Ϊ���нڵ���Ҷ���,cntΪ���нڵ�ĸ���
int tree[maxn], height[maxn], Size[maxn], leftchild[maxn], rightchild[maxn], num[maxn], cnt = 0;

void update(int x) {//���½ڵ�x�ĸ߶Ⱥ�������С
	height[x] = max(height[leftchild[x]], height[rightchild[x]]) + 1;
	Size[x] = Size[leftchild[x]] + Size[rightchild[x]] + num[x];
}

void RightRotation(int &x) {//����(��Ӧ���LL)
	int y = leftchild[x];//yָ��x�������
	leftchild[x] = rightchild[y];//y���Ҷ��ӹҵ�x�������
	rightchild[y] = x;//x��Ϊy���Ҷ���
	update(x);//����x
	update(y);//����y
	x = y;//���¸��ڵ�
}

void LeftRotation(int &x) {//����(��Ӧ���RR)
	int y = rightchild[x];//yָ��x���Ҷ���
	rightchild[x] = leftchild[y];//y������ӹҵ�x���Ҷ���
	leftchild[y] = x;//x��Ϊy�������
	update(x);//����x
	update(y);//����y
	x = y;//���¸��ڵ�
}

void LeftRightRotation(int &x) {//������(��Ӧ���LR)
	LeftRotation(leftchild[x]);//������x�������
	RightRotation(x);//������x
}

void RightLeftRotation(int &x) {//������(��Ӧ���RL)
	RightRotation(rightchild[x]);//������x���Ҷ���
	LeftRotation(x);//������x
}

void insert(int &x, int v) {//����Ԫ��v
	if (x == 0) {//���xΪ��
		x = ++cnt;//�½��ڵ�
		tree[x] = v;//�ڵ�ֵΪv
		num[x] = 1;//�ڵ����Ϊ1
		Size[x] = 1;//�ڵ��СΪ1
		height[x] = 1;//�ڵ�߶�Ϊ1
		leftchild[x] = rightchild[x] = 0;//���Ҷ���Ϊ��
		return;
	}
	if (v == tree[x]) {//���v����x��ֵ
		num[x]++;//x�ĸ�����1
		update(x);//����x�ĸ߶Ⱥ�������С
		return;
	}
	if (v < tree[x]) {//���vС��x��ֵ
		insert(leftchild[x], v);//���뵽x�������
		if (height[leftchild[x]] - height[rightchild[x]] == 2) {//�������ӵĸ߶ȱ��Ҷ��ӵĸ߶ȴ�2
			if (v < tree[leftchild[x]])//���vС������ӵ�ֵ
				RightRotation(x);//����x(��Ӧ���LL)
			else
				LeftRightRotation(x);//������x(��Ӧ���LR)
		}
	}
	else {//���v����x��ֵ
		insert(rightchild[x], v);//���뵽x���Ҷ���
		if (height[rightchild[x]] - height[leftchild[x]] == 2) {//����Ҷ��ӵĸ߶ȱ�����ӵĸ߶ȴ�2
			if (v > tree[rightchild[x]])//���v�����Ҷ��ӵ�ֵ
				LeftRotation(x);//����x(��Ӧ���RR)
			else
				RightLeftRotation(x);//������x(��Ӧ���RL)
		}
	}
	update(x);//����x�ĸ߶Ⱥ�������С
}

int findmin(int x) {//������Сֵ
	while (leftchild[x])//һֱ���������
		x = leftchild[x];
	return tree[x];
}

int findmax(int x) {//�������ֵ
	while (rightchild[x])//һֱ���Ҷ�����
		x = rightchild[x];
	return tree[x];
}

int minimum(int x) {//������Сֵ��Ӧ�ı��
	while (leftchild[x])//һֱ���������
		x = leftchild[x];
	return x;
}

int maximum(int x) {//�������ֵ��Ӧ�ı��
	while (rightchild[x])//һֱ���Ҷ�����
		x = rightchild[x];
	return x;
}

//�ݹ����
int search(int x, int v)
{
	if (!x) return 0;
	if (tree[x] == v) return x;
	else if (v < tree[x]) return search(leftchild[x], v);
	else return search(rightchild[x], v);
}
//�ǵݹ����
int iterativesearch(int x, int v)
{
	while (x) {
		if (tree[x] == v) return x;
		else if (v < tree[x]) x = leftchild[x];
		else x = rightchild[x];
	}
}

void removeid(int& x, int id, int removenum)//ɾ�����Ϊid�Ľڵ�
{
	if(x==0 || id==0) return;//��ǰ�ڵ�Ϊ��
	if (tree[id] < tree[x]) {
		removeid(leftchild[x], id, removenum);//ɾ���������ж�Ӧ�ڵ�
		//ɾ������AVL��ʧ�⣬�������Ӧ��ƽ�����
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
		removeid(rightchild[x], id, removenum);//ɾ���������ж�Ӧ�Ľڵ�
		//ɾ������AVL��ʧ�⣬�������Ӧ��ƽ�����
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
		if (num[x] > removenum) num[x] -= removenum;//�ýڵ㲻ֻһ����ֱ�Ӽ��ٽڵ�����
		else {
			if (leftchild[x] && rightchild[x]) {//�������ӽڵ�
				if (height[leftchild[x]] > height[rightchild[x]]) {//�������߶ȴ����������߶�
					int k = maximum(leftchild[x]);//�ҵ��������е����ֵ
					tree[x] = tree[k];//�����ֵ����x
					num[x] = num[k];//����x�ĸ���
					//if (leftchild[0] == x) leftchild[0] = k;//���ɾ�����Ǹ��ڵ㣬��Ҫ���¸��ڵ�
					removeid(leftchild[x], k, num[k]);//ɾ���������е����ֵ,ע��������ɾ��num[k]���ڵ㣬ȫ��ɾ��
				}
				else {//�������߶ȴ��ڵ����������߶�
					int k = minimum(rightchild[x]);//�ҵ��������е���Сֵ
					tree[x] = tree[k];//����Сֵ����x
					num[x] = num[k];//����x�ĸ���
					//if (leftchild[0] == x) leftchild[0] = k;//���ɾ�����Ǹ��ڵ㣬��Ҫ���¸��ڵ�
					removeid(rightchild[x], k, num[k]);//ɾ���������е���Сֵ��ע��������ɾ��num[k]���ڵ㣬ȫ��ɾ��
				}
			}
			else {//ֻ��һ���ӽڵ��û���ӽڵ�
				//int temp = x;
				if (leftchild[x] == 0) x = rightchild[x];//������Ϊ�գ�����������x
				else if (rightchild[x] == 0) x = leftchild[x];//������Ϊ�գ�����������x
				//delete temp;//ɾ���ڵ�
			}
		}
	}
	if (x) update(x);//����x�ĸ߶Ⱥ�������С
}

void remove(int& x, int key)
{
	int z;
	int tempx = x;
	if ((z = iterativesearch(x, key)) != 0) {
		removeid(x, z, 1);
		//cout << "x:" << x << endl;
	}
	else cout << "The node is not in the tree!" << endl;//"����û������ڵ㣡"
}

void preorder(int x) {//�������
	if (x == 0) return;
	for(int i=0;i<num[x];i++)
		cout << tree[x] << " ";
	preorder(leftchild[x]);
	preorder(rightchild[x]);
}

void inorder(int x) {//�������
	if (x == 0) return;
	inorder(leftchild[x]);
	for(int i=0;i<num[x];i++)
		cout << tree[x] << " ";
	inorder(rightchild[x]);
}

void postorder(int x) {//�������
	if (x == 0) return;
	postorder(leftchild[x]);
	postorder(rightchild[x]);
	for(int i=0;i<num[x];i++)
		cout << tree[x] << " ";
}

int predecessor(int x, int v) {//����ǰ��
	if (x == 0) return -INF;//û��ǰ��
	if (tree[x] >= v) return predecessor(leftchild[x], v);//�����ǰ�ڵ��ֵ���ڵ���value���ݹ��ѯ������
	else return max(tree[x], predecessor(rightchild[x], v));////�����ǰ�ڵ��ֵС��value�����ص�ǰ�ڵ��ֵ�͵ݹ��ѯ�����������ֵ
}

int successor(int x, int v) {//���Һ��
	if (x == 0) return INF;//û�к��
	if (tree[x] <= v) return successor(rightchild[x], v);//�����ǰ�ڵ��ֵС�ڵ���value���ݹ��ѯ������
	else return min(tree[x], successor(leftchild[x], v));//�����ǰ�ڵ��ֵ����value�����ص�ǰ�ڵ��ֵ�͵ݹ��ѯ����������Сֵ
}

void print(int x, int key, int direction) {//��ӡ��
	if (x) {
		if (direction == 0) cout << tree[x] << " is root" << endl;
		else cout << tree[x] << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << endl;
		print(leftchild[x], tree[x], -1);
		print(rightchild[x], tree[x], 1);
	}
}

int queryrank(int x, int v) {//��ѯ����
	if (x == 0) return 1;//�����ǰ�ڵ�Ϊ�գ�����1����Ϊ����ֵ�������У�������Ҫ��һ��
	if (v == tree[x]) return Size[leftchild[x]] + 1;//�����ǰ�ڵ��ֵ����value�������������Ĵ�С+1
	if (v < tree[x]) return queryrank(leftchild[x], v);//�����ǰ�ڵ��ֵ����value���ݹ��ѯ������
	else return Size[leftchild[x]] + num[x] + queryrank(rightchild[x], v);//�����ǰ�ڵ��ֵС��value�������������Ĵ�С+��ǰ�ڵ�ĸ���+�ݹ��ѯ������
}

int queryvalue(int x, int k) {//��ѯ����Ϊk����
	if (x == 0) {
		cout<<"No such node!"<<endl;//"û�������Ľڵ㣡
		return INF;//�����ǰ�ڵ�Ϊ�գ�����INF
	}
	if (Size[leftchild[x]] >= k) return queryvalue(leftchild[x], k);//����������Ĵ�С���ڵ���k���ݹ��ѯ������
	if (Size[leftchild[x]] + num[x] >= k) return tree[x];//����������Ĵ�С+��ǰ�ڵ�ĸ������ڵ���k�����ص�ǰ�ڵ��ֵ
	return queryvalue(rightchild[x], k - Size[leftchild[x]] - num[x]);//����ݹ��ѯ������,����kҪ��ȥ�������Ĵ�С�͵�ǰ�ڵ�ĸ���
}

int querynum(int x, int v) {//��ѯ��ֵΪv�ĸ���
	if (x == 0) return 0;//�����ǰ�ڵ�Ϊ�գ�����0
	if (v == tree[x]) return num[x];//�����ǰ�ڵ��ֵ����value�����ص�ǰ�ڵ�ĸ���
	if (v < tree[x]) return querynum(leftchild[x], v);//�����ǰ�ڵ��ֵ����value���ݹ��ѯ������
	else return querynum(rightchild[x], v);//�����ǰ�ڵ��ֵС��value���ݹ��ѯ������
}

int main()
{
	int n, key;
	cin >> n;
	//�����ƽڵ�
	tree[0] = 0;
	height[0] = 0;
	Size[0] = 0;
	leftchild[0] = 0;
	rightchild[0] = 0;
	num[0] = 0;
	//������룬����AVL�������ƽڵ�������Ϊ���ڵ�
	//1 2 3 4 6 7 8 9 11 24
	for (int i = 0; i < n; i++) {
		cin >> key;
		insert(leftchild[0], key);
	}
	//�������
	cout << "Preorder:" << endl;
	preorder(leftchild[0]);
	cout << endl;
	//�������
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//�������
	cout << "Postorder:" << endl;
	postorder(leftchild[0]);
	cout << endl;
	//��ѯ��Сֵ
	cout << "The minimum value is:" << findmin(leftchild[0]) << endl;
	//��ѯ���ֵ
	cout << "The maximum value is:" << findmax(leftchild[0]) << endl;
	//��ѯǰ��
	cout << "The predecessor of 11 is:" << predecessor(leftchild[0], 11) << endl;
	//��ѯ���
	cout << "The successor of 4 is:" << successor(leftchild[0], 4) << endl;
	//��ѯ����
	cout << "The rank of 6 is:" << queryrank(leftchild[0], 6) << endl;
	//��ѯ����Ϊ10����
	cout << "The value of rank 10 is:" << queryvalue(leftchild[0], 10) << endl;
	//��ѯ��ֵΪ6�ĸ���
	cout << "The number of 6 is:" << querynum(leftchild[0], 6) << endl;
	//ɾ����ֵΪ6�Ľڵ�
	cout<<"Remove 6"<<endl;
	remove(leftchild[0], 6);
	//�������
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//��ӡ����Ϣ
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//����3����ֵΪ5�Ľڵ�
	cout<<"Insert 5 5 5"<<endl;
	insert(leftchild[0], 5);
	insert(leftchild[0], 5);
	insert(leftchild[0], 5);
	//�������
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//��ѯ��ֵΪ5�ĸ���
	cout << "The number of 5 is:" << querynum(leftchild[0], 5) << endl;
	//��ӡ����Ϣ
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//ɾ����ֵΪ9�Ľڵ�
	cout<<"Remove 9"<<endl;
	remove(leftchild[0], 9);
	//�������
	cout<<"Inorder:"<<endl;
	inorder(leftchild[0]);
	cout<<endl;
	//��ӡ����Ϣ
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//ɾ�����ڵ�
	cout << "Remove root : " << leftchild[0] << endl;
	remove(leftchild[0], tree[leftchild[0]]);
	//�������
	cout << "Inorder:" << endl;
	inorder(leftchild[0]);
	cout << endl;
	//��ӡ����Ϣ
	print(leftchild[0], tree[leftchild[0]], 0);
	cout<< endl;
	//��ѯ5������
	cout << "The rank of 5 is:" << queryrank(leftchild[0], 5) << endl;
	//��ѯ����Ϊ5����
	cout << "The value of rank 6 is:" << queryvalue(leftchild[0], 6) << endl;
	//��ѯ��ֵΪ5�ĸ���
	cout << "The number of 5 is:" << querynum(leftchild[0], 5) << endl;
	return 0;
}