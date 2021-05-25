#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, k, p; ll ans; map<pii, int> mp; unordered_map<int, int> xx, yy, cntx, cnty;
void updx(int x, int v){
	ans += cnty[xx[x]] - cnty[xx[x] ^ v];
	xx[x] ^= v, cntx[xx[x] ^ v]--, cntx[xx[x]]++;
}
void updy(int y, int v){
	ans += cntx[yy[y]] - cntx[yy[y] ^ v];
	yy[y] ^= v, cnty[yy[y] ^ v]--, cnty[yy[y]]++;
}
int main(){
	n = re, k = re, p = re, cntx[0] = cnty[0] = n;
	for (int i = 0; i < k; i++){
		int r = re, c = re, v = re;
		mp[{r, c}] = v;
		updx(r, v); updy(c, v);
	}
	while(p--){
		int r = re, c = re, nr = re, nc = re, v = mp[{r, c}];
		updx(r, v); updy(c, v); updx(nr, v); updy(nc, v);
		mp[{r, c}] ^= v, mp[{nr, nc}] ^= v;
		printf("%lld\n", ans);
	}
}
