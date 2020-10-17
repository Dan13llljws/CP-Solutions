#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
typedef long long ll;
const int MM = 2e5 + 5;
int n, v, h[MM]; ll bit[MM], ans;
void update(int pos, ll val){for (; pos <= n; pos += pos & -pos) bit[pos] = max(bit[pos], val);}
ll get(int pos){
	ll ret = 0;
	for (; pos > 0; pos -= pos & -pos) ret = max(ret, bit[pos]);
	return ret;	
} 
int main(){
	n = read();
	for (int i = 1; i <= n; i++) h[i] = read();
	for (int i = 1; i <= n; i++){
		v = read();
		ll dp = get(h[i]) + v;
		update(h[i], dp);
		ans = max(ans, dp);
	}
	printf("%lld\n", ans);
}
