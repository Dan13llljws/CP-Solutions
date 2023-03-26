#include <bits/stdc++.h>
using namespace std;
const int MM = 128;
int p[MM];
void dfs(int l, int r, string &s){
    if (l == r) return;
    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; i++) s[i] = '1', add_element(s), s[i] = '0';
    string lft = s, rit = s;
    for (int i = l; i <= mid; i++) rit[i] = '1';
    for (int i = mid + 1; i <= r; i++) lft[i] = '1';
    dfs(l, mid, lft), dfs(mid + 1, r, rit);
}
void dfs1(int l, int r, vector<int> &v, string &s){
    if (l == r){p[v[0]] = l; return;}
    int mid = (l + r) >> 1;
    vector<int> ls, rs; string lft = s, rit = s;
    for (int x : v){
        s[x] = '1';
        if (check_element(s)) ls.push_back(x), rit[x] = '1';
        else rs.push_back(x), lft[x] = '1';
        s[x] = '0';
    } dfs1(l, mid, ls, lft), dfs1(mid + 1, r, rs, rit);
}
int* restore_permutation(int n, int w, int r){
    vector<int> v(n); string s(n, '0');  
    iota(v.begin(), v.end(), 0); dfs(0, n - 1, s), compile_set(), dfs1(0, n - 1, v, s);
    return p;
}
int main(){}

