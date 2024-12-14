#include "RedBlackTree1.h"
#include <crtdbg.h>

int main()
{
	//����ڴ�й©
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	RBT tree;
	int a[] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	cout << "�������:";
	for (int i = 0; i < 10; i++)
	{
		tree.insert(a[i]);
	}
	cout << endl;
	cout << "ǰ�����:";
	tree.preorder();
	cout << endl;
	cout << "�������:";
	tree.inorder();
	cout << endl;
	cout << "�������:";
	tree.postorder();
	cout << endl;
	cout << "��Сֵ:" << tree.minimum() << endl;
	cout << "���ֵ:" << tree.maximum() << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << "ɾ���ڵ�8" << endl;
	tree.remove(8);
	cout << "�������:";
	tree.inorder();
	cout << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << "ɾ���ڵ�5" << endl;
	tree.remove(5);
	cout << "�������:";
	tree.inorder();
	cout << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << "����ڵ�8" << endl;
	tree.insert(8);
	cout << "�������:";
	tree.inorder();
	cout << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << endl;
	cout << "1��ǰ��:" << tree.predecessor(1) << endl;
	cout << "4�ĺ��:" << tree.successor(4) << endl;
	return 0;
}