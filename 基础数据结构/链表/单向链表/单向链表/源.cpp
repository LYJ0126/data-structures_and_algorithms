#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
//结点构建
typedef struct node 
{
	int value;
	node* next;
}node;
//创建一个结点：node *p = (node *)malloc(sizeof(node)); 或 node *p = new node;
node* inscreate(int n)//个数为n，头部插入结点的方式构建链表(倒序)
{
	node* head = NULL;//或者nullptr
	for (int i = 1; i <= n; i++) {
		node* p = new node;//或 (node*)malloc(sizeof(node))
		int x;
		cin >> x;
		p->value = x;
		p->next = head;
		head = p;
	}
	return head;
}
//输出整个链表
void printlist(node* head)
{
	if (!head) printf("List is empty./n");//等价于if(head==NULL)
	else {
		while (head) {//等价于while(head!=NULL)
			cout << head->value << ' ';
			head = head->next;
		}
	}
}
node* listcreate(int n)//带参数创建链表
{
	node* head = NULL, * tail = NULL;//头尾节点
	for (int i = 1; i <= n; ++i)
	{
		node* p = (node*)malloc(sizeof(node)); //创建新节点
		int x;
		cin >> x;
		p->value = x;
		p->next = NULL; //给新节点的指针成员赋值
		if (head == NULL) //链表起初没有节点时，处理创建的第一个节点
			head = p;
		else tail->next = p;		//处理后续创建的节点
		tail = p;
	}
	return head;
}
node* listcreate2() //不带参数创建链表
{
	node* head = NULL, * tail = NULL, * p;
	int temp = 0;
	cin >> temp;
	while (temp != -1) //节点个数不定，直到输入-1停止
	{
		p = (node*)malloc(sizeof(node)); //创建新节点
		p->value = temp;
		p->next = NULL; //每一个新节点都可能是尾节点
		if (!head) head = p;
		else tail->next = p; //追加新节点
		tail = p;
		cin >> temp;
	}
	return head;
}
void insertnode(node* head, int i,int x)//在第i个节点后插入节点。参数：链表头节点，带插入结点的位置，插入的数
{
	node* current = head;//指针指向第一个结点
	int j = 1;
	while (j < i && current->next!=NULL) {
		j++;
		current = current->next;
	}//循环结束时，current指向第i个节点或最后一个节点（节点数不足i时）
	if (j == i) {//current指向第i个节点
		node* p = new node;
		p->value = x;
		p->next = current->next;//第i+1个节点连在p（新插入的节点）后
		current->next = p;//第i个节点指向新节点p
	}
	else cout << "没有节点" << i << "\n";
}
//注意：删除节点函数要返回head，因为如果是void函数，删除头节点，head变成悬浮指针
node* deletenode(node* head,int i)//删除第i个节点。参数：链表头节点，删除节点位置i
{
	if (i == 1) //删除头节点
	{
		node* current = head; // current指向头节点
		head = head->next; // head指向新的头节点
		free(current); // delete current;释放删除节点的空间
	}
	else
	{
		node* previous = head; // previous指向头节点
		int j = 1;
		while (j < i - 1 && previous->next != NULL)
		{
			++j;
			previous = previous->next;
		} // 查找第i-1个节点
		if (previous->next != NULL) // 链表中存在第i个节点
		{
			node* current = previous->next;
			// current指向第i个节点
			previous->next = current->next;
			// 让待删除节点的前后两个节点相链接
			free(current); // delete current;释放第i个节点的空间
			//一定要记得释放
		}
		else cout << "没有节点" << i << "\n";
	}
	return head;
}
//除了上面的deletenode函数外，这里有两个删除头节点的函数
node* deletefirstnode1(node* head) //删除头节点
{
	node* current = head; // current指向头节点
	head = head->next; // head指向新的头节点
	free(current); // delete current;释放删除节点的空间
	return head;
}//头节点被删除，所以要返回新的头节点
//如果我们不想要设一个新的变量来表示新的头节点该怎么做？
//利用函数的副作用
void deletefirstnode2(node* head) //删除头节点
{
	node* current = head; // current指向头节点
	head = head->next; // *head指向新的头节点
	free(current); // delete current;释放删除节点的空间
}//这样head就不会变成悬浮指针
void deleteList(node* head)//删除整个链表
{
	while (head)//遍历链表，如果写成while(head -> next)则不能删除尾节点！！
	{
		node* current = head;
		head = head->next;
		free(current); // delete current;
	}
}
void reverseprintlist(node* head)//反向遍历链表。写法一（调用栈）
{
	stack<node*>nodestack;
	node* current = head;
	while (current)
	{
		nodestack.push(current);
		current = current->next;
	}
	while (!nodestack.empty())
	{
		current = nodestack.top();
		cout << current->value << ' ';
		nodestack.pop();
	}
}
void reverseprintlist2(node* head)//反向遍历链表。写法二（递归）
{
	if (head) {
		if (head->next != NULL) {
			reverseprintlist2(head->next);
		}
		cout << head->value << ' ';
	}
}

//以下两个函数利用双指针算法实现
//找出中间节点（偶数个节点时中间节点为len/2）
node* findmid(node* head) 
{
	node* slow = head;
	node* fast = head;//快慢指针，快指针速度是慢指针的两倍
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//找出倒数第k个节点
node* findlastknode(node* head,int k)
{
	node* temp1 = head;
	node* temp2 = head;
	int aim = k;
	while (k > 1) {
		if (temp2 == NULL) {
			cout << "没有倒数第" << aim << "个节点。/n";
			return NULL;
		}
		temp2 = temp2->next;
		k--;
	}//先让快指针temp2走到k的位置，后面二者同步走，temp2到尾节点时，temp1也就到了倒数第k个节点。
	while (temp2->next != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp1;
}

//翻转链表
node* reverlist(node* head)
{
	node* reversedhead = NULL;
	node* pnode = head;
	node* pre = NULL;
	while (pnode != NULL) {
		if (pnode->next == NULL) {
			reversedhead = pnode;
		}
		node* ne = pnode->next;
		pnode->next = pre;
		pre = pnode;
		pnode = ne;//这里是反向构建链表
	}
	return reversedhead;
}

//获取链表长度
int getlistlen(node* head)
{
	node* current = head;
	int len = 1;
	while (current->next != NULL) {
		current = current->next;
		len++;
	}
	return len;
}
//判断两个链表是否相交，并返回交点
//注意，两个链表若相交，必定成Y形，不可能是X形
//求出两链表长度差dis，让较长的链表先走dis步。这样，若链表相交，指针必会相撞，相撞点即相交点。
node* findcrosspoint(node* head1, node* head2) 
{
	int m = getlistlen(head1);
	int n = getlistlen(head2);
	int dis = 0;
	node* temp1 = head1;
	node* temp2 = head2;
	if (m > n) {
		dis = m - n;
		while (dis > 0) {
			temp1 = temp1->next;
			dis--;
		}
	}
	else {
		dis = n - m;
		while (dis > 0) {
			temp2 = temp2->next;
			dis--;
		}
	}
	while (temp1 != temp2 && temp1->next != NULL && temp2->next != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	//此时两个指针要么相撞，要么到了尾节点
	if (temp1 == temp2) {
		return temp1;
	}
	else {
		cout << "两个链表不相交\n";
		return NULL;
	}
}

//判断链表是否有环路，获取链接点，计算环的长度
//1.判断是否有环路。利用双指针，快指针速度为慢指针两倍，若链表有环路，快指针必定会和慢指针相撞。
//  若没有环，则快指针走到NULL
bool cotainloop(node* head)
{
	if (head == NULL) {
		return false;
	}
	node* slow = head;
	node* fast = head;
	while (slow != fast && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL) {
		return false;
	}
	return true;
}
//2.判断环的长度
//  在相撞点继续走，当再次相撞时，slow走了len，fast走了2*len，len即环长度。
int getlooplen(node* head) {
	if (head == NULL) return 0;
	node* slow = head;
	node* fast = head;
	while (slow != fast && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL) {
		return 0;
	}//首次相遇
	int len = 0;
	while (slow != fast) {
		len++;
		slow = slow->next;
		fast = fast->next->next;
	}
	return len;
}
//3.获得环的连接点
//  slow与fast第一次碰撞点到环的连接点的距离=头指针到环的连接点的距离
node* getjoinpoint(node* head) 
{
	if (head == NULL) return NULL;
	node* slow = head;
	node* fast = head;
	while (slow != fast && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL) return NULL;
	node* fromhead = head;
	node* fromcrashpoint = slow;
	while (fromcrashpoint != fromhead) {
		fromhead = fromhead->next;
		fromcrashpoint = fromcrashpoint->next;
	}
	return fromhead;
}
int main()
{
	int n;
	cin >> n;
	node* head = listcreate(n);
	printlist(head);
	int key,pos;
	cin >> pos >> key;
	insertnode(head, pos, key);
	printlist(head);
	return 0;
}