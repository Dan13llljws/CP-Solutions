#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
const char sp=' ',nl='\n';
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template<typename T>void read(T &s){s=0;char ch=getchar();T f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-48,ch=getchar();s*=f;}
template<typename T, typename...A>void read(T&f,A&...a){read(f);read(a...);}
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
#define af(x) x.begin(), x.end()
const int mod = 1e9 + 7, base = 131;
struct event{int t, x, y;};
int n, t, mx, mn, ans, cnt[101]; bool vis[101], sick[101], worksk[252];
bool cmp(event a, event b){return a.t < b.t;}
bool check(int i, int k, vector<event>&e){
	ms(vis, 0); ms(cnt, 0);
	vis[i] = 1;
	for (auto x : e){
		if (vis[x.x]) cnt[x.x]++;
		if (vis[x.y]) cnt[x.y]++;
		if (vis[x.x] && cnt[x.x] <= k) vis[x.y] = 1;
		if (vis[x.y] && cnt[x.y] <= k) vis[x.x] = 1;
	}
	for (int j = 1; j <= n; j++) if (sick[j] != vis[j]) return 0;
	return 1;
}
int main(){
	n = re, t = re; // the question is so confusing 
	for (int i = 1; i <= n; i++) sick[i] = getchar() - '0'; 
	getchar();
	vector<event> e(t);
	for (auto &x : e) read(x.t, x.x, x.y);
	sort(af(e), cmp);
	for (int i = 1; i <= n; i++){
		bool flag = 0;
		for (int j = 0; j <= 251; j++)
			if (check(i, j, e)) flag = 1, worksk[j] = 1;
		ans += flag;
	}
	for (int i = 0; i <= 251; i++) if (worksk[i]) mx = i;
	for (int i = 251; i >= 0; i--) if (worksk[i]) mn = i;
	pr(ans, sp, mn, sp); 
	if (mx == 251) pr("Infinity");
	else pr(mx);
	return 0;
	
}
