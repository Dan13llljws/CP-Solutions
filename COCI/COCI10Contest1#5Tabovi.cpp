#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005;
int n, ans, a[MM], b[MM];
int main(){
	n = re;
	for (int i = 0; i < n; i++) a[i] = re;
	for (int i = 0; i < n; i++) a[i] = re - a[i];
	ans = abs(a[0]);
	for (int i = 1; i < n; i++){
		if (a[i] > 0){
			if (a[i - 1] > 0) ans += max(0, a[i] - a[i - 1]);
			else ans += a[i];
		} else {
			if (a[i - 1] < 0) ans += max(0, a[i - 1] - a[i]);
			else ans -= a[i];
		}
	}
	printf("%d\n", ans);
}
