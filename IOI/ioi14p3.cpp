#include <stdio.h>
int cnt[1505];
void initialize(int n){}
int hasEdge(int u, int v){
    if (u < v) u = v;
    return ++cnt[u] == u;
}
