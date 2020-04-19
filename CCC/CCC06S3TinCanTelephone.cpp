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
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
int n, cnt;
int orientation(pii p, pii q, pii r){
	return (q.s - p.s) * (r.f - q.f) - (r.s - q.s) * (q.f - p.f);
}
bool inter(pii a, pii b, pii c, pii d){
	if (max(a.f, b.f) < min(c.f, d.f) || // completly out
		min(a.f, b.f) > max(c.f, d.f) ||
		max(a.s, b.s) < min(c.s, d.s) ||
		min(a.s, b.s) > max(c.s, d.s)) return 0;
	if (orientation(a, b, c) * orientation(a, b, d) > 0 || orientation(c, d, a) * orientation(c, d, b) > 0) return 0; 
	return 1;
}
int main(){
	pii a, b;
	read(a.f, a.s, b.f, b.s, n);
	for (int i = 0; i < n; i++){
		int k = re;
		vector<pii> p(k);
		for (int j = 0; j < k; j++) p[j].f = re, p[j].s = re;
		for (int j = 0; j < k; j++)
			if (inter(a, b, p[j], p[(j + 1) % k])){cnt++; break;}
	}
	pr(cnt);
	return 0;
}
