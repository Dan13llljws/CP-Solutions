#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define pb push_back
#define g(x, y) (x*m+y)
const int mod = 1e9 + 7, base = 131, MM = (1<<20)+5;
int n, m, a, b, c, st, dist[MM];
int dir[8][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, 0}, {0, -1}, {-1, -1}};
vector<int> adj[MM]; queue<int> q;
int next(int mask){
	int ret = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int cur = mask >> g(i, j) & 1, cnt = 0;
			for (int k = 0; k < 8; k++){
				int nx = i + dir[k][0], ny = j + dir[k][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) cnt += mask >> g(nx, ny) & 1;
			}
			if ((cur && cnt >= a && cnt <= b) || (!cur && cnt > c)) ret |= 1 << g(i, j);
		}
	}
	return ret;
}
int main(){
	n = re, m = re, a = re, b = re, c = re; 
	for (int i = 0; i < (1 << n * m); i++) adj[next(i)].pb(i);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			st |= (getchar() == '*') << g(i, j);
		getchar();
	}
	q.push(st);
	while(!q.empty()){
		int p = q.front(); q.pop();
		if (!sz(adj[p])) return 0 * printf("%d", dist[p]);
		for (int v : adj[p])
			if (!dist[v] && v != st){
				dist[v] = dist[p] + 1;
				q.push(v);
			}
	}
	printf("-1");
	return 0;
}
