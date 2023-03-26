#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, m; ll ans; pii p[100005];
int main(){
	n = re, m = re;
	for (int i = 0; i < n; i++) p[i] = {re, re};
	sort(p, p + n);
	for (int i = 0; i < n; i++) ans += max(0, p[i].second - p[i + 1].second);
	printf("%lld\n", ans);
}
