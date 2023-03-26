#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n; vector<int> adj[MM];
int dfs(int src, int par, int k){
	multiset<int> s;
	for (int v : adj[src]){
		if (v == par) continue;
		int tmp = dfs(v, src, k);
		if (tmp == -1) return -1;
		s.insert(tmp + 1);
	}
	int ret = 0;
	if ((s.size() + (src != 1)) & 1) s.insert(0);
	while(!s.empty()){
		int cur = *s.begin(); s.erase(s.begin());
		auto it = s.lower_bound(k - cur);
		if (src == 1){
			if (it == s.end()) return -1;
			s.erase(it);
		} else {
			if (it == s.end()){
				if (ret) return -1;
				ret = cur;
			} else s.erase(it);
		}
	}
	return ret;
}
int main(){
	n = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if (dfs(1, 0, mid) != -1) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}

