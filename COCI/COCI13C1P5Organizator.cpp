#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, x, a[2000005], maxa; ll ans;
int main(){
	n = re;
	for (int i = 0; i < n; i++) x = re, a[x]++, maxa = max(maxa, x);
	for (int i = 1; i <= maxa; i++){
		int cnt = 0;
		for (int j = i; j <= maxa; j += i) cnt += a[j];
		if (cnt > 1) ans = max(ans, 1LL * cnt * i);
	}
	printf("%lld", ans);
}

