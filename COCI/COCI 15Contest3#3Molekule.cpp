#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
const char sp=' ',nl='\n';
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template<typename T>void read(T &s){s=0;char ch=getchar();ll f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-48,ch=getchar();s*=f;}
template<typename T, typename...A>void read(T&f,A&...a){read(f);read(a...);}
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int n, dep[MM];
vector<int> adj[MM];
pii edges[MM];
void dfs(int src, int par){
	dep[src] = dep[par] + 1;
	for (int v : adj[src])
		if (v != par) dfs(v, src);
}
int main(){
	n = re;
	for (int i = 0; i < n - 1; i++){
		read(edges[i].f, edges[i].s);
		adj[edges[i].f].pb(edges[i].s); adj[edges[i].s].pb(edges[i].f);
	}
	dfs(1, 1);
	for (int i = 0; i < n - 1; i++)
		pr(dep[edges[i].f] % 2, nl);
	return 0;
}

