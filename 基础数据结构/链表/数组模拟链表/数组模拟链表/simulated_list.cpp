#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

// Ä£ÄâÁ´±í
const int N = 100010;
typedef struct node
{
	int value;
	int prev;
	int next;
}node;

node list[N];
int head = 0, tail = 0, idx = 0;

void newnode(int val)
{
	list[++idx].value = val;
	if (!head) {
		head = tail = idx;
		list[idx].prev = list[idx].next = 0;
	}
	else {
		list[tail].next = idx;
		list[idx].prev = tail;
		list[idx].next = 0;
		tail = idx;
	}
}

void listcreate(int n)
{
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		newnode(val);
	}
}

int getid(int val)
{
	for (int i = head; i; i = list[i].next) {
		if (list[i].value == val) return i;
	}
	return -1;
}

void insert(int k, int x)
{
	list[++idx].value = x;
	list[idx].prev = k;
	list[idx].next = list[k].next;
	list[k].next = idx;
	if (list[idx].next) list[list[idx].next].prev = idx;
	else tail = idx;
}

void remove(int k)
{
	if(k==head) head = list[k].next;
	else if(k==tail) tail = list[k].prev;
	else {
		list[list[k].prev].next = list[k].next;
		list[list[k].next].prev = list[k].prev;
	}
}

void listprint()
{
	for (int i = head; i; i = list[i].next) {
		cout << list[i].value << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	listcreate(n);
	listprint();
	int m;
	cin >> m;
	while (m--) {
		string op;
		cin >> op;
		if (op == "L") {
			int x;
			cin >> x;
			insert(head, x);
		}
		else if (op == "R") {
			int x;
			cin >> x;
			insert(tail, x);
		}
		else if (op == "D") {
			int k;
			cin >> k;
			remove(k);
		}
		else if (op == "IL") {
			int k, x;
			cin >> k >> x;
			insert(list[k].prev, x);
		}
		else if (op == "IR") {
			int k, x;
			cin >> k >> x;
			insert(k, x);
		}
		listprint();
	}
	return 0;
}