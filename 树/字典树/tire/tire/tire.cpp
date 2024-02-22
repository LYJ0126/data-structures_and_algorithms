#include<iostream>
#include<cstring>
using namespace std;

struct trie {
    int nex[100000][26], cnt;//nex[u][c]表示节点u的c字符指向的下一个节点，
    //或着说是结点 u 代表的字符串后面添加一个字符 c 形成的字符串的结点。
    bool exist[100000];  // 该结点结尾的字符串是否存在

    void insert(char* s, int l) {  // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    bool find(char* s, int l) {  // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};