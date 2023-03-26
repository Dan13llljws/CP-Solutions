#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
int dx[MM], dy[MM], id[MM], vis[MM]; set<int> C, D;
void findLocation(int n, int first, int location[], int stype[]){
    auto set_c = [&](int i, int p){C.insert(p), location[i] = p, stype[i] = 1;};
    auto set_d = [&](int i, int p){D.insert(p), location[i] = p, stype[i] = 2;};
    for (int i = 1; i < n; i++) dx[i] = getDistance(0, i), id[i] = i;
    sort(id, id + n, [&](int a, int b){return dx[a] < dx[b];});
    int l = id[0], r = id[1];
    set_c(l, first), set_d(r, first + dx[r]);
    for (int i = 1; i < n; i++) 
        if (i != id[1]) dy[i] = getDistance(id[1], i);
    for (int i = 2; i < n; i++){
        int j = id[i];
        if (dx[j] == dx[id[1]] + dy[j] && dx[id[1]] > dy[j]) set_c(j, location[id[1]] - dy[j]);
        else if (dx[id[1]] + dy[j] == dx[j]){
            int dis = getDistance(l, j), len = (dy[l] + dis - dy[j]) / 2;
            if (!C.count(location[l] + len)) set_c(j, location[id[1]] - dy[j]), l = j;
            else set_d(j, location[l] + dis);
        } else {
            int dis = getDistance(r, j), len = (dx[r] + dis - dx[j]) / 2;
            if (!D.count(location[r] - len)) set_d(j, first + dx[j]), r = j;
            else set_c(j, location[r] - dis);
        }
    }
}
int main(){}
