#pragma once
#include<iostream>
#include<cmath>
using namespace std;

//红黑树
//红黑树满足以下性质：
//1.每个节点要么是红色，要么是黑色
//2.根节点是黑色
//3.每个叶子节点（NIL）是黑色
//4.如果一个节点是红色的，则它的子节点必须是黑色的
//5.从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点
//红黑树的高度最多是2log(n+1)
//相比于AVL树，红黑树的旋转操作更少，因此插入和删除操作更快

//enum Color { RED, BLACK };

typedef enum
{
	RED,
	BLACK
}Color;
//红黑树节点
class RBNode
{
public:
	int key;
	//int num;//相同键值节点的个数
	Color color;
	RBNode* left;
	RBNode* right;
	//RBNode* parent;
	//RBNode(int key, Color color, RBNode* left, RBNode* right, RBNode* parent) :key(key), color(color), left(left), right(right), parent(parent) {}
};

class RBT
{
private:
	RBNode* root;//根节点
	RBNode* NIL;//哨兵节点(叶子节点)
	const int INF = 0x3f3f3f3f;
	void destroy(RBNode* node);//销毁红黑树
public:
	RBT();//构造函数
	~RBT();//析构函数
	void inorder();//中序遍历
	void preorder();//前序遍历
	void postorder();//后序遍历
	int predecessor(int key);
	int successor(int key);
	int search(int key);//查找(递归)
	int iterativesearch(int key);//迭代查找
	int minimum();//查找最小值
	int maximum();//查找最大值
protected:
	RBNode* createNode(int key);//创建节点
	void inorder(RBNode* node);//中序遍历
	void preorder(RBNode* node);//前序遍历
	void postorder(RBNode* node);//后序遍历
	RBNode* predecessor(RBNode* node, int key);//前驱
	RBNode* successor(RBNode* node, int key);//后继
	RBNode* search(RBNode* x, int key);//查找(递归)
	RBNode* iterativesearch(RBNode* x, int key);//迭代查找
	RBNode* minimum(RBNode* node);//查找最小值
	RBNode* maximum(RBNode* node);//查找最大值
};