#include "RedBlackTree1.h"
#include <crtdbg.h>

int main()
{
	//检查内存泄漏
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	RBT tree;
	int a[] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	cout << "依次添加:";
	for (int i = 0; i < 10; i++)
	{
		tree.insert(a[i]);
	}
	cout << endl;
	cout << "前序遍历:";
	tree.preorder();
	cout << endl;
	cout << "中序遍历:";
	tree.inorder();
	cout << endl;
	cout << "后序遍历:";
	tree.postorder();
	cout << endl;
	cout << "最小值:" << tree.minimum() << endl;
	cout << "最大值:" << tree.maximum() << endl;
	cout << "树的详细信息:" << endl;
	tree.print();
	cout << "删除节点8" << endl;
	tree.remove(8);
	cout << "中序遍历:";
	tree.inorder();
	cout << endl;
	cout << "树的详细信息:" << endl;
	tree.print();
	cout << "删除节点5" << endl;
	tree.remove(5);
	cout << "中序遍历:";
	tree.inorder();
	cout << endl;
	cout << "树的详细信息:" << endl;
	tree.print();
	cout << "插入节点8" << endl;
	tree.insert(8);
	cout << "中序遍历:";
	tree.inorder();
	cout << endl;
	cout << "树的详细信息:" << endl;
	tree.print();
	cout << endl;
	cout << "1的前驱:" << tree.predecessor(1) << endl;
	cout << "4的后继:" << tree.successor(4) << endl;
	return 0;
}