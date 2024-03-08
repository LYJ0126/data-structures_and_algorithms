#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class UnionSet {
public:
    UnionSet(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i, val[i] = 1;
    }

    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] *= val[fa[x]];
        return fa[x] = root;
    }

    void merge(int a, int b, double t) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        val[aa] = t * val[b] / val[a];
        fa[aa] = bb;
        return;
    }
    vector<int> fa;
    vector<double> val;
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), cnt = 0;
        unordered_map<string, int> mp;
        vector<double> ans;
        UnionSet u(2 * n);
        for (int i = 0; i < n; i++) {
            vector<string> x = equations[i];
            if (mp.find(x[0]) == mp.end()) mp[x[0]] = cnt++;
            if (mp.find(x[1]) == mp.end()) mp[x[1]] = cnt++;
            u.merge(mp[x[0]], mp[x[1]], values[i]);
        }
        for (auto& x : queries) {
            if (mp.find(x[0]) == mp.end() || mp.find(x[1]) == mp.end()) ans.push_back(-1);
            else if (u.get(mp[x[0]]) != u.get(mp[x[1]])) ans.push_back(-1);
            else {
                int a = mp[x[0]], b = mp[x[1]];
                ans.push_back(u.val[a] / u.val[b]);
            }
        }
        return ans;
    }
};