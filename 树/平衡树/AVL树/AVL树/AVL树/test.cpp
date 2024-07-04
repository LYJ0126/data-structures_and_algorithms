

//AVL.h����ģ���࣬��main������ֻ������AVL.h����û�а���AVL.cpp����ô�������޷�����ģ����������Ӧ�Ĵ��룬��˻ᱨ��
//�����������AVL.h��AVL.cpp����һ�𣬻�����main�����а���AVL.cpp
#include "AVL.h"
#include <crtdbg.h>
using namespace std;

int main()
{
	//����ڴ�й©
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	AVL<int> tree;
	int a[] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	cout<<"�������:";
	for (int i = 0; i < 10; i++)
	{
		tree.insert(a[i]);
	}
	cout << endl;
	cout << "ǰ�����:";
	tree.preOrder();
	cout << endl;
	cout << "�������:";
	tree.inOrder();
	cout << endl;
	cout << "�������:";
	tree.postOrder();
	cout << endl;
	cout << "���ĸ߶�:" << tree.height() << endl;
	cout << "��Сֵ:" << tree.minimum() << endl;
	cout << "���ֵ:" << tree.maximum() << endl;
	cout<<"������ϸ��Ϣ:"<<endl;
	tree.print();
	cout << "ɾ���ڵ�8" << endl;
	tree.remove(8);
	cout << "�������:";
	tree.inOrder();
	cout << endl;
	cout << "���ĸ߶�:" << tree.height() << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << "ɾ���ڵ�5" << endl;
	tree.remove(5);
	cout << "�������:";
	tree.inOrder();
	cout << endl;
	cout << "���ĸ߶�:" << tree.height() << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << "����ڵ�8" << endl;
	tree.insert(8);
	cout << "�������:";
	tree.inOrder();
	cout << endl;
	cout << "���ĸ߶�:" << tree.height() << endl;
	cout << "������ϸ��Ϣ:" << endl;
	tree.print();
	cout << endl;
	cout << "1��ǰ��:" << tree.predecessor(1) << endl;
	cout << "4�ĺ��:" << tree.successor(4) << endl;
	return 0;
}