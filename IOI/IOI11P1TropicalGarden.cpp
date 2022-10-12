#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5 + 5;
struct E{int to, nxt;}g[MM], e[MM];
struct L{int t, d, x;};
int n, m, p, t, ehead[MM], ghead[MM], fst[MM], sec[MM], st[MM], d[MM], ans[MM], cntc[2][MM], cntt[MM]; 
void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
    memset(ehead, -1, sizeof ehead), memset(ghead, -1, sizeof ghead), memset(fst, -1, sizeof fst), memset(sec, -1, sizeof sec);
    for (int i = 0; i < M; i++){
        g[t].nxt = ghead[R[i][0]], ghead[R[i][0]] = t++;
        g[t].nxt = ghead[R[i][1]], ghead[R[i][1]] = t++;
    } t = 0;
    for (int i = 0; i < N; i++){
        for (int j = ghead[i]; ~j; j = g[j].nxt) 
            if (fst[i] == -1 || j < fst[i]) sec[i] = fst[i], fst[i] = j;
            else if (sec[i] == -1 || j < sec[i]) sec[i] = j;
        st[fst[i]] = 1;
        for (int j = ghead[i]; ~j; j = g[j].nxt)
            if (j == fst[i] && sec[i] != -1) e[t].nxt = ehead[sec[i]], e[t].to = j ^ 1, ehead[sec[i]] = t++;
            else e[t].nxt = ehead[fst[i]], e[t].to = j ^ 1, ehead[fst[i]] = t++;
    } vector<L> vec; int csz[2] = {-1, -1};
    for (int i = ghead[P]; ~i; i = g[i].nxt){
        vector<int> q = {i ^ 1}; int cy = -1; d[i ^ 1] = 1;
        for (int i1 = 0; i1 < (int)q.size(); i1++){
            int u = q[i1];
            for (int j = ehead[u]; ~j; j = e[j].nxt){
                if (e[j].to == (i ^ 1)){cy = csz[0] != -1, csz[cy] = d[u]; continue;}
                d[e[j].to] = d[u] + 1, q.push_back(e[j].to);
            }
        }
        for (int x : q) 
            if (st[x]) vec.push_back({0, d[x], cy});
    }
    for (int i = 0; i < Q; i++) vec.push_back({1, G[i], i}); 
    sort(vec.begin(), vec.end(), [](L a, L b){return a.d == b.d ? a.t < b.t : a.d < b.d;});
    for (L ev : vec){
        if (ev.t){
            for (int i : {0, 1})
                if (csz[i] != -1) ans[ev.x] += cntc[i][ev.d % csz[i]];
            if (ev.d <= 2 * M) ans[ev.x] += cntt[ev.d];
        } else if (ev.x != -1) cntc[ev.x][ev.d % csz[ev.x]]++;
        else cntt[ev.d]++;
    }
    for (int i = 0; i < Q; i++) answer(ans[i]);
}
int main(){}
