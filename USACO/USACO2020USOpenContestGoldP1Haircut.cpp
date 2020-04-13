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
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int n; ll tot[MM], bit[MM];
void update(int pos){
	for (; pos <= n; pos += pos & -pos)	bit[pos]++;
}
ll get(int pos){
	ll ret = 0;
	for (; pos > 0; pos -= pos & -pos) ret += bit[pos];
	return ret;
}
int main(){
	n = re;
	for (int i = 0, a; i < n; i++){
		a = re + 1;
		tot[a] += i - get(a);
		update(a);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += tot[i];
		pr(ans, nl);
	}
	return 0;
}
