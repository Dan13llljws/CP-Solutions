#include <bits/stdc++.h>
using namespace std;
int main(){
    int s = 0;
    unordered_map<int,int> d;
    for (int i = 0; i < 9; i++){
        int x;
        cin >> x;
        s = s * 10 + x;
    }
    vector<int> p;
    for (int i = 0, j = 1; i < 9; i++, j *= 10)
        p.push_back(j);
    queue<int> q;
    q.push(s);
    auto upd = [&](int u, int i, int j) -> void{
        int a = u / p[i] % 10, b = u / p[j] % 10;
        int v = u + (b - a) * p[i] + (a - b) * p[j];
        if (d.count(v)) return;
        d[v] = d[u] + 1, q.push(v);
    };
    while(q.size()){
        int u = q.front(); q.pop();
        for (int i = 0; i < 9; i += 3)
            upd(u, i, i + 1), upd(u, i + 1, i + 2);
        for (int i = 3; i < 9; i++)
            upd(u, i - 3, i);
    }
    cout << d[123456789] << '\n';
}
