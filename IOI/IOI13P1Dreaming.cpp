#include <bits/stdc++.h>
using namespace std;
int dist[100001], pre[100001]; bool vis[100001];
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    int maxDiameter = 0;
    vector<int> radius;
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++){
        adj[A[i]].push_back(make_pair(T[i], B[i]));
        adj[B[i]].push_back(make_pair(T[i], A[i]));
    }
    for (int i = 0; i < N; i++){
        if (!vis[i]){
            int maxd = 0, far = i, cur;
            queue<pair<int, int>> q;
            q.push(make_pair(i, 0));
            vector<int> clean;
            vis[i] = 1;
            clean.push_back(i);
            while(!q.empty()){
                int p = q.front().first, d = q.front().second; q.pop();
                if (d > maxd){
                    maxd = d;
                    far = p;
                }
                for (auto v : adj[p]){
                    if (!vis[v.second]){
                        vis[v.second] = 1;
                        clean.push_back(v.second);
                        q.push(make_pair(v.second, v.first + d));
                    }
                }
            }
            for (int e : clean) vis[e] = 0;
            maxd = 0; q.push(make_pair(far, 0)); cur = far;
            vis[far] = 1;
            while(!q.empty()){
                int p = q.front().first, d = q.front().second; q.pop();
                if (d > maxd){
                    maxd = d;
                    far = p;
                }
                for (auto v : adj[p]){
                    if (!vis[v.second]){
                        vis[v.second] = 1;
                        pre[v.second] = p;
                        dist[v.second] = v.first;
                        q.push(make_pair(v.second, v.first + d));
                    }
                }
            }
            int r = maxd;
            maxDiameter = max(maxDiameter, maxd);
            for (int x = 0; far != cur; far = pre[far]){
                r = min(r, max(maxd - x, x));
                x += dist[far];
            }
            radius.push_back(r);
        }
    }
    sort(radius.begin(), radius.end());
    int S = radius.size();
    if (S == 1) return maxDiameter;
    int a = radius[S - 1] + radius[S - 2] + L, b = radius[S - 2] + radius[S - 3] + 2 * L;
    if (S == 2) return max(maxDiameter, a);
    return max(a, max(b, maxDiameter));
}
