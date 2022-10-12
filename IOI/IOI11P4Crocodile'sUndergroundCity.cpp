#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
vector<pair<int,int>> adj[MM]; int sd[MM], d[MM], c[MM], vis[MM];
void upd(int &a, int &b, int v){
    if (v <= a) b = a, a = v;
    else b = v;
}
int travel_plan(int N, int M, int R[][2], int W[], int K, int E[]){
    for (int i = 0; i < M; i++){
        adj[R[i][0]].push_back({W[i], R[i][1]});
        adj[R[i][1]].push_back({W[i], R[i][0]});
    } memset(d, 0x3f, sizeof d), memset(sd, 0x3f, sizeof sd);
    priority_queue<pair<int,int>> q;
    for (int i = 0; i < K; i++) q.push({0, E[i]}), d[E[i]] = sd[E[i]] = 0;
    while(q.size()){
        int u = q.top().second, dis = -q.top().first; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [w, v] : adj[u]){
            c[v]++;
            if (sd[u] + w >= sd[v]) continue;
            upd(d[v], sd[v], sd[u] + w);
            if (c[v] > 1) q.push({-sd[v], v});
        }
    } return sd[0];
}
int main(){}
