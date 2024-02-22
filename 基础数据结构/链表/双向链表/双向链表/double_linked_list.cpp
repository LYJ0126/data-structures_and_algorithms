#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

//双向链表
typedef struct node
{
	int data;
	node* next;
	node* prev;
	node() :data(0), next(nullptr), prev(nullptr) {};
	node(int x) :data(x), next(nullptr), prev(nullptr) {};
	node(int x, node* p, node* q) :data(x), next(p), prev(q) {};
}node;

node* listcreate(int n)
{
	node* head = nullptr, * tail = nullptr;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		node* p = new node(x);
		if (head == nullptr)
		{
			head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			p->prev = tail;
			tail = p;
		}
	}
	return head;
}

void listprint(node* head)
{
	node* p = head;
	if (!p) {
		cout<<"List is empty"<<endl;
		return;
	}
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void listnodeinsert(node* head, int x, int pos)
{
	node* cur = head;
	int j = 1;
	while (j < pos && cur != nullptr)
	{
		cur = cur->next;
		j++;
	}
	if (cur == nullptr)
	{
		cout << "插入位置不合法" << endl;
		return;
	}
	else {
		node* p = new node(x, cur->next, cur);
		if (cur->next != nullptr)
		{
			cur->next->prev = p;
		}
		cur->next = p;
	}
}

void listnodedelete(node* head, int pos)
{
	node* cur = head;
	int j = 1;
	while (j < pos && cur != nullptr)
	{
		cur = cur->next;
		j++;
	}
	if (cur == nullptr)
	{
		cout << "删除位置不合法" << endl;
		return;
	}
	else {
		if (cur == head) {
			head = head->next;
			if(head) head->prev = nullptr;
		}
		else {
			cur->prev->next = cur->next;
			if (cur->next != nullptr)
			{
				cur->next->prev = cur->prev;
			}
		}
		delete cur;
	}
}

void listdestroy(node* head)
{
	node* p = head;
	while (p != nullptr)
	{
		node* q = p;
		p = p->next;
		delete q;
	}
}

int main()
{
	int n;
	cin >> n;
	node* head = listcreate(n);
	listprint(head);
	int x, pos;
	cin >> x >> pos;
	listnodeinsert(head, x, pos);
	listprint(head);
	cin >> pos;
	listnodedelete(head, pos);
	listprint(head);
	listdestroy(head);
	return 0;
}