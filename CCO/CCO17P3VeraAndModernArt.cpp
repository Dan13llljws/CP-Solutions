#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
struct U{ll x; int v;};
struct Q{int id; ll x;};
int n, q, tot, tid, ans[MM], trie[2][MM<<6], id[MM<<6]; unordered_map<ll,int> cur; vector<Q> qq[MM<<1]; vector<U> uu[MM<<1];
int lg2(ll x){return 63 - __builtin_clzll(x);}
void dfs(int rt){
	for (U x : uu[id[rt]]) cur[x.x] += x.v;
	for (Q x : qq[id[rt]])
		for (int i = 0; i <= lg2(x.x); i++){
			ll v = (x.x & ((1LL << i) - 1)) | (1LL << i);
			if (cur.count(v)) ans[x.id] += cur[v];
		}
	if (trie[0][rt]) dfs(trie[0][rt]);
	if (trie[1][rt]) dfs(trie[1][rt]);
	for (U x : uu[id[rt]]){
		cur[x.x] -= x.v;
		if (!cur[x.x]) cur.erase(x.x);
	}
}		
int main(){
	n = re, q = re;
	for (int i = 0; i < n; i++){
		ll x = re, y = re; int v = re, rt = 0;
		for (int j = 0; j < lg2(y); j++){
			int &s = trie[y >> j & 1][rt];
			if (s) rt = s;
			else rt = s = ++tot;
		} 
		if (!id[rt]) id[rt] = ++tid;
		uu[id[rt]].push_back({x, v});
	}
	for (int i = 0; i < q; i++){
		ll x = re, y = re; int rt = 0;
		for (int j = 0; j < lg2(y); j++){
			int &s = trie[y >> j & 1][rt];
			if (s) rt = s;
			else break;
		}
		if (!id[rt]) id[rt] = ++tid;
		qq[id[rt]].push_back({i, x});
	} dfs(0);
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}
