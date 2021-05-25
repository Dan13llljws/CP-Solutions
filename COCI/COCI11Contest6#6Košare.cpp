#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int n, m, ans, cnt[1<<20], p[1000005];
void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}
int main(){
	n = re, m = re, p[0] = 1;
	for (int i = 0; i < n; i++){
		int k = re, mask = 0;
		while(k--) mask |= 1 << (re - 1);
		cnt[mask]++;
	}
	for (int i = 1; i <= n; i++) add(p[i], 2 * p[i - 1]);
	for (int i = 0; i < m; i++)
		for (int j = (1 << m) - 1; j; j--)
			if (j >> i & 1) cnt[j] += cnt[j ^ (1 << i)];
	for (int i = 0; i < (1 << m); i++)
		if ((m -__builtin_popcount(i)) & 1) add(ans, -p[cnt[i]]);
		else add(ans, p[cnt[i]]);
	printf("%d\n", ans);
}
