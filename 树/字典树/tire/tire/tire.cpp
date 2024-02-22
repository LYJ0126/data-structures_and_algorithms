#include<iostream>
#include<cstring>
using namespace std;

struct trie {
    int nex[100000][26], cnt;//nex[u][c]��ʾ�ڵ�u��c�ַ�ָ�����һ���ڵ㣬
    //����˵�ǽ�� u ������ַ����������һ���ַ� c �γɵ��ַ����Ľ�㡣
    bool exist[100000];  // �ý���β���ַ����Ƿ����

    void insert(char* s, int l) {  // �����ַ���
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // ���û�У�����ӽ��
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    bool find(char* s, int l) {  // �����ַ���
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};