#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e3 + 5;
int d, f, t, ans[MM], w[MM], a[MM]; vector<int> adj[MM];
int main(){
	d = re; memset(a, -1, sizeof a);
	for (int i = 1; i <= d; i++) w[i] = re;
	f = re;
	for (int i = 0; i < f; i++){
		int u = re, v = re;
		adj[u].push_back(v);
	}
	t = re, ans[1] = 1;
	for (int v : adj[1]) a[v] = w[v] - 1;
	for (int i = 1; i <= t; i++){
		for (int j = 1; j <= d; j++)
			if (a[j] == 0){
				for (int v : adj[j])
					if (a[v] == -1) a[v] = w[v];
				ans[j]++;
			}
		for (int j = 1; j <= d; j++) if (a[j] >= 0) a[j]--;
	}
	for (int i = 1; i <= d; i++) printf("%d\n", ans[i]);
}

