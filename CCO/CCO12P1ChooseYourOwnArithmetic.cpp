#include <bits/stdc++.h>
using namespace std;
int W, D, d[10], V; unordered_set<int> s;
int main(){ // gay q copying bruces sol
    scanf("%d %d", &W, &D);
    for(int i=0; i<D; i++) scanf("%d", &d[i]), s.insert(d[i]);
    while(W--){
        unordered_set<int> s2;
        for(auto u: s)
            for(int i=0; i<D; i++)
                s2.insert(u+d[i]), s2.insert(u*d[i]);
        s=s2;
    }
    scanf("%d", &V);
    for(int i=0, x; i<V; i++){
        scanf("%d", &x);
        printf("%c\n", s.count(x)? 'Y':'N');
    }
}
