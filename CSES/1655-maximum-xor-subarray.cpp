#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> trie(1, vector<int>(2));
    auto insert = [&](int x){
        int rt = 0;
        for (int i = 30; i >= 0; i--){
            int &s = trie[rt][x >> i & 1];
            if (!s) s = trie.size(), trie.push_back(vector<int>(2));
            rt = s;
        }
    };
    auto query = [&](int x){
        int ret = 0, rt = 0;
        for (int i = 30; i >= 0; i--){
            int a = x >> i & 1, b = a ^ 1;
            if (trie[rt][b]) rt = trie[rt][b], ret |= 1 << i;
            else rt = trie[rt][a];
        }
        return ret;
    };
    int cur = 0, ans = 0;
    insert(0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        cur ^= x, ans = max(ans, query(cur)), insert(cur);
    }
    cout << ans << '\n';
}

