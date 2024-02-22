#include "Union.h"

int unionfind::getancestor1(int id, int* p) {
	if (p[id] == id) return id;
	return p[id] = getancestor1(p[id], p);//利用递归同时完成路径压缩
}

int unionfind::getancestor2(int id, int* p) {//迭代写法
	int root = p[id];
	while (root != id) {//如果id就是根节点的话不进入循环
		id = p[id];
		root = p[id];
	}
	//路径压缩
	while (id != p[id]) {
		int nxt = p[id];
		p[id] = root;
		id = nxt;
	}
	return root;
}

void unionfind::merge(int x, int y, int* p) {//合并
	x = getancestor1(x, p);
	y = getancestor1(y, p);
	if (x != y) p[y] = x;
}