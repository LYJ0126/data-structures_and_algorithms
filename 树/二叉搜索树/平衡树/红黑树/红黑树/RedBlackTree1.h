#pragma once
#include<iostream>
#include<cmath>
using namespace std;

//�����
//����������������ʣ�
//1.ÿ���ڵ�Ҫô�Ǻ�ɫ��Ҫô�Ǻ�ɫ
//2.���ڵ��Ǻ�ɫ
//3.ÿ��Ҷ�ӽڵ㣨NIL���Ǻ�ɫ
//4.���һ���ڵ��Ǻ�ɫ�ģ��������ӽڵ�����Ǻ�ɫ��
//5.����һ�ڵ㵽��ÿ��Ҷ�ӵ�����·����������ͬ��Ŀ�ĺ�ɫ�ڵ�
//������ĸ߶������2log(n+1)
//�����AVL�������������ת�������٣���˲����ɾ����������

//enum Color { RED, BLACK };

typedef enum
{
	RED,
	BLACK
}Color;
//������ڵ�
class RBNode
{
public:
	int key;
	//int num;//��ͬ��ֵ�ڵ�ĸ���
	Color color;
	RBNode* left;
	RBNode* right;
	//RBNode* parent;
	//RBNode(int key, Color color, RBNode* left, RBNode* right, RBNode* parent) :key(key), color(color), left(left), right(right), parent(parent) {}
};

class RBT
{
private:
	RBNode* root;//���ڵ�
	RBNode* NIL;//�ڱ��ڵ�(Ҷ�ӽڵ�)
	const int INF = 0x3f3f3f3f;
	void destroy(RBNode* node);//���ٺ����
public:
	RBT();//���캯��
	~RBT();//��������
	void inorder();//�������
	void preorder();//ǰ�����
	void postorder();//�������
	int predecessor(int key);
	int successor(int key);
	int search(int key);//����(�ݹ�)
	int iterativesearch(int key);//��������
	int minimum();//������Сֵ
	int maximum();//�������ֵ
protected:
	RBNode* createNode(int key);//�����ڵ�
	void inorder(RBNode* node);//�������
	void preorder(RBNode* node);//ǰ�����
	void postorder(RBNode* node);//�������
	RBNode* predecessor(RBNode* node, int key);//ǰ��
	RBNode* successor(RBNode* node, int key);//���
	RBNode* search(RBNode* x, int key);//����(�ݹ�)
	RBNode* iterativesearch(RBNode* x, int key);//��������
	RBNode* minimum(RBNode* node);//������Сֵ
	RBNode* maximum(RBNode* node);//�������ֵ
};