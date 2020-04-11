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
int n, m, x[101], y[101], sm[101], sv[101], pm[101], pv[101];
bool check(int a){
	int tot = 0; 
	for (int i = 0; i < n; i++){
		int dp = INF, need = a * x[i] - y[i];
		for (int j = 0; j * pm[i] <= m; j++){
			int q = 0;
			if (j * sm[i] < need) q = (need - j * sm[i] + sv[i] - 1) / sv[i];
			dp = min(dp, j * pm[i] + q * pv[i]);
		}
		tot += dp;
	}
	return tot <= m;
}
int main(){
	n = re, m = re; 
	for (int i = 0; i < n; i++) read(x[i], y[i], sm[i], pm[i], sv[i], pv[i]);
	int l = 0, r = m / n; 
	while(l < r){
		int mid = l + r + 1 >> 1; 
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	pr(l);
	return 0;
}
