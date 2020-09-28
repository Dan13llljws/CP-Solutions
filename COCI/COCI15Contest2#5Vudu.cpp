#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n, p, a[MM], b[MM], bit[MM]; ll ans, psa[MM]; vector<ll> comp;
void update(int x){for(; x <= (int)comp.size(); x += x & -x) bit[x]++;}
int get(int x){
	int ret = 0;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	p = re; comp.push_back(0);
	for (int i = 1; i <= n; i++) psa[i] = psa[i - 1] + a[i] - p, comp.push_back(psa[i]);
	sort(comp.begin(), comp.end()); comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	update(lower_bound(comp.begin(), comp.end(), 0) - comp.begin() + 1);
	for (int i = 1; i <= n; i++){
		b[i] = lower_bound(comp.begin(), comp.end(), psa[i]) - comp.begin() + 1;
		ans += get(b[i]), update(b[i]);
	}
	printf("%lld\n", ans);
}

