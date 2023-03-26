#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define pb push_back
int n, cnt, p[105], in[30], ans[30]; char str[105][105];
vector<int> adj[30]; queue<int> q;
int main(){
	n = re;
	for (int i = 1; i <= n; i++) scanf("%s", str[i]);
	for (int i = 1; i <= n; i++) p[i] = re;
	for (int i = 2; i <= n; i++){
		int j = 0;
		while(str[p[i]][j] && str[p[i - 1]][j] && str[p[i]][j] == str[p[i - 1]][j]) j++;
		if (str[p[i]][j] && str[p[i - 1]][j])
			adj[str[p[i - 1]][j] - 'a'].pb(str[p[i]][j] - 'a'), in[str[p[i]][j] - 'a']++;
		else if (!str[p[i]][j] && str[p[i - 1]][j]) return 0 * puts("NE");
	}
	for (int i = 0; i < 26; i++)
		if (!in[i]) q.push(i), ans[i] = cnt++;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for (int v : adj[u])
			if (!--in[v]) q.push(v), ans[v] = cnt++;
	}
	if (cnt != 26) return 0 * puts("NE");
	puts("DA");
	for (int i = 0; i < 26; i++) putchar(ans[i] + 'a');
	puts("");
}
