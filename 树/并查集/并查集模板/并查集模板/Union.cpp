#include "Union.h"

int unionfind::getancestor1(int id, int* p) {
	if (p[id] == id) return id;
	return p[id] = getancestor1(p[id], p);//���õݹ�ͬʱ���·��ѹ��
}

int unionfind::getancestor2(int id, int* p) {//����д��
	int root = p[id];
	while (root != id) {//���id���Ǹ��ڵ�Ļ�������ѭ��
		id = p[id];
		root = p[id];
	}
	//·��ѹ��
	while (id != p[id]) {
		int nxt = p[id];
		p[id] = root;
		id = nxt;
	}
	return root;
}

void unionfind::merge(int x, int y, int* p) {//�ϲ�
	x = getancestor1(x, p);
	y = getancestor1(y, p);
	if (x != y) p[y] = x;
}