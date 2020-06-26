#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, k, ans, arr[MM], fac[MM], inv[MM];
int fpow(int a, int b){
	int ret = 1;
	while(b){
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod, b >>= 1;
	}
	return ret;
}
int choose(int a, int b){return 1LL * fac[a] * inv[b] % mod * inv[a - b] % mod;}
int main(){
	n = re, k = re, fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) arr[i] = re;
	for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[n] = fpow(fac[n], mod - 2);
	for (int i = n - 1; i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	sort(arr + 1, arr + n + 1);
	for (int i = k; i <= n; i++) ans = (ans + 1LL * arr[i] * choose(i - 1, k - 1) % mod) % mod;
	printf("%d\n", ans);
}

