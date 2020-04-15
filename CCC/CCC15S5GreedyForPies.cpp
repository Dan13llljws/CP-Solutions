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
const int mod = 1e9 + 7, base = 131;
int n, m, a[3005], b[101], dp[2][3005][105][105];
int rec(int can, int cur, int l, int r){
	int &ret = dp[can][cur][l][r];
	if (ret) return ret; // computed
	if (cur == n + 1){ // at the end
		if (l <= r){ // spares left
			if (can) return ret = b[r] + rec(0, cur, l, r - 1); // can take spare
			return ret = rec(1, cur, l + 1, r); // cannont take spare
		}
		return ret;
	}
	if (can){ // can take
		ret = max(rec(0, cur, l, r), rec(0, cur + 1, l, r) + a[cur]); // skip / take
		if (l <= r) ret = max(ret, rec(0, cur, l, r - 1) + b[r]); // take spare
		return ret;
	}
	ret = rec(1, cur + 1, l, r); // skip
	if (l <= r) ret = max(ret, rec(1, cur, l + 1, r)); // insert spare
	return ret;
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	m = re;
	for (int i = 1; i <= m; i++) b[i] = re;
	sort(b + 1, b + m + 1);
	pr(rec(1, 1, 1, m));
	return 0;
}
