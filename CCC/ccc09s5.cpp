#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
struct circle{int x, y, r, b;} c[1005];
int m, n, k, cnt, ans, psa[30005];
int sqr(int x){return x * x;}
int main(){
	m = re, n = re, k = re;
	for (int i = 0; i < k; i++) c[i] = {re, re, re, re};
	for (int i = 1; i <= n; i++){
		memset(psa, 0, sizeof psa);
		for (int j = 0; j < k; j++){
			if (i < c[j].x - c[j].r || i > c[j].x + c[j].r) continue;
			int tmp = sqrt(sqr(c[j].r) - sqr(i - c[j].x)), l = max(1, c[j].y - tmp), r = min(m + 1, c[j].y + tmp + 1);
			psa[l] += c[j].b, psa[r] -= c[j].b;
		}
		for (int j = 1; j <= m; j++){
			psa[j] += psa[j - 1];
			if (psa[j] > ans) ans = psa[j], cnt = 1;
			else if (psa[j] == ans) cnt++;
		}
	}
	printf("%d\n%d\n", ans, cnt);
}

