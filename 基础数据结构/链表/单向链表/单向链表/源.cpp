#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
//��㹹��
typedef struct node 
{
	int value;
	node* next;
}node;
//����һ����㣺node *p = (node *)malloc(sizeof(node)); �� node *p = new node;
node* inscreate(int n)//����Ϊn��ͷ��������ķ�ʽ��������(����)
{
	node* head = NULL;//����nullptr
	for (int i = 1; i <= n; i++) {
		node* p = new node;//�� (node*)malloc(sizeof(node))
		int x;
		cin >> x;
		p->value = x;
		p->next = head;
		head = p;
	}
	return head;
}
//�����������
void printlist(node* head)
{
	if (!head) printf("List is empty./n");//�ȼ���if(head==NULL)
	else {
		while (head) {//�ȼ���while(head!=NULL)
			cout << head->value << ' ';
			head = head->next;
		}
	}
}
node* listcreate(int n)//��������������
{
	node* head = NULL, * tail = NULL;//ͷβ�ڵ�
	for (int i = 1; i <= n; ++i)
	{
		node* p = (node*)malloc(sizeof(node)); //�����½ڵ�
		int x;
		cin >> x;
		p->value = x;
		p->next = NULL; //���½ڵ��ָ���Ա��ֵ
		if (head == NULL) //�������û�нڵ�ʱ���������ĵ�һ���ڵ�
			head = p;
		else tail->next = p;		//������������Ľڵ�
		tail = p;
	}
	return head;
}
node* listcreate2() //����������������
{
	node* head = NULL, * tail = NULL, * p;
	int temp = 0;
	cin >> temp;
	while (temp != -1) //�ڵ����������ֱ������-1ֹͣ
	{
		p = (node*)malloc(sizeof(node)); //�����½ڵ�
		p->value = temp;
		p->next = NULL; //ÿһ���½ڵ㶼������β�ڵ�
		if (!head) head = p;
		else tail->next = p; //׷���½ڵ�
		tail = p;
		cin >> temp;
	}
	return head;
}
void insertnode(node* head, int i,int x)//�ڵ�i���ڵ�����ڵ㡣����������ͷ�ڵ㣬���������λ�ã��������
{
	node* current = head;//ָ��ָ���һ�����
	int j = 1;
	while (j < i && current->next!=NULL) {
		j++;
		current = current->next;
	}//ѭ������ʱ��currentָ���i���ڵ�����һ���ڵ㣨�ڵ�������iʱ��
	if (j == i) {//currentָ���i���ڵ�
		node* p = new node;
		p->value = x;
		p->next = current->next;//��i+1���ڵ�����p���²���Ľڵ㣩��
		current->next = p;//��i���ڵ�ָ���½ڵ�p
	}
	else cout << "û�нڵ�" << i << "\n";
}
//ע�⣺ɾ���ڵ㺯��Ҫ����head����Ϊ�����void������ɾ��ͷ�ڵ㣬head�������ָ��
node* deletenode(node* head,int i)//ɾ����i���ڵ㡣����������ͷ�ڵ㣬ɾ���ڵ�λ��i
{
	if (i == 1) //ɾ��ͷ�ڵ�
	{
		node* current = head; // currentָ��ͷ�ڵ�
		head = head->next; // headָ���µ�ͷ�ڵ�
		free(current); // delete current;�ͷ�ɾ���ڵ�Ŀռ�
	}
	else
	{
		node* previous = head; // previousָ��ͷ�ڵ�
		int j = 1;
		while (j < i - 1 && previous->next != NULL)
		{
			++j;
			previous = previous->next;
		} // ���ҵ�i-1���ڵ�
		if (previous->next != NULL) // �����д��ڵ�i���ڵ�
		{
			node* current = previous->next;
			// currentָ���i���ڵ�
			previous->next = current->next;
			// �ô�ɾ���ڵ��ǰ�������ڵ�������
			free(current); // delete current;�ͷŵ�i���ڵ�Ŀռ�
			//һ��Ҫ�ǵ��ͷ�
		}
		else cout << "û�нڵ�" << i << "\n";
	}
	return head;
}
//���������deletenode�����⣬����������ɾ��ͷ�ڵ�ĺ���
node* deletefirstnode1(node* head) //ɾ��ͷ�ڵ�
{
	node* current = head; // currentָ��ͷ�ڵ�
	head = head->next; // headָ���µ�ͷ�ڵ�
	free(current); // delete current;�ͷ�ɾ���ڵ�Ŀռ�
	return head;
}//ͷ�ڵ㱻ɾ��������Ҫ�����µ�ͷ�ڵ�
//������ǲ���Ҫ��һ���µı�������ʾ�µ�ͷ�ڵ����ô����
//���ú����ĸ�����
void deletefirstnode2(node* head) //ɾ��ͷ�ڵ�
{
	node* current = head; // currentָ��ͷ�ڵ�
	head = head->next; // *headָ���µ�ͷ�ڵ�
	free(current); // delete current;�ͷ�ɾ���ڵ�Ŀռ�
}//����head�Ͳ���������ָ��
void deleteList(node* head)//ɾ����������
{
	while (head)//�����������д��while(head -> next)����ɾ��β�ڵ㣡��
	{
		node* current = head;
		head = head->next;
		free(current); // delete current;
	}
}
void reverseprintlist(node* head)//�����������д��һ������ջ��
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
void reverseprintlist2(node* head)//�����������д�������ݹ飩
{
	if (head) {
		if (head->next != NULL) {
			reverseprintlist2(head->next);
		}
		cout << head->value << ' ';
	}
}

//����������������˫ָ���㷨ʵ��
//�ҳ��м�ڵ㣨ż�����ڵ�ʱ�м�ڵ�Ϊlen/2��
node* findmid(node* head) 
{
	node* slow = head;
	node* fast = head;//����ָ�룬��ָ���ٶ�����ָ�������
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//�ҳ�������k���ڵ�
node* findlastknode(node* head,int k)
{
	node* temp1 = head;
	node* temp2 = head;
	int aim = k;
	while (k > 1) {
		if (temp2 == NULL) {
			cout << "û�е�����" << aim << "���ڵ㡣/n";
			return NULL;
		}
		temp2 = temp2->next;
		k--;
	}//���ÿ�ָ��temp2�ߵ�k��λ�ã��������ͬ���ߣ�temp2��β�ڵ�ʱ��temp1Ҳ�͵��˵�����k���ڵ㡣
	while (temp2->next != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp1;
}

//��ת����
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
		pnode = ne;//�����Ƿ��򹹽�����
	}
	return reversedhead;
}

//��ȡ������
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
//�ж����������Ƿ��ཻ�������ؽ���
//ע�⣬�����������ཻ���ض���Y�Σ���������X��
//����������Ȳ�dis���ýϳ�����������dis�����������������ཻ��ָ��ػ���ײ����ײ�㼴�ཻ�㡣
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
	//��ʱ����ָ��Ҫô��ײ��Ҫô����β�ڵ�
	if (temp1 == temp2) {
		return temp1;
	}
	else {
		cout << "���������ཻ\n";
		return NULL;
	}
}

//�ж������Ƿ��л�·����ȡ���ӵ㣬���㻷�ĳ���
//1.�ж��Ƿ��л�·������˫ָ�룬��ָ���ٶ�Ϊ��ָ���������������л�·����ָ��ض������ָ����ײ��
//  ��û�л������ָ���ߵ�NULL
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
//2.�жϻ��ĳ���
//  ����ײ������ߣ����ٴ���ײʱ��slow����len��fast����2*len��len�������ȡ�
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
	}//�״�����
	int len = 0;
	while (slow != fast) {
		len++;
		slow = slow->next;
		fast = fast->next->next;
	}
	return len;
}
//3.��û������ӵ�
//  slow��fast��һ����ײ�㵽�������ӵ�ľ���=ͷָ�뵽�������ӵ�ľ���
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