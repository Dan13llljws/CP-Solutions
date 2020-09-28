#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, bit[MM], cnt[MM]; 
void update(int x, int v){for (; x < MM; x += x & -x) bit[x] += v;}
int get(int x){
	int ret = 0;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++){
		int l = re, r = re, a = get(l), b = get(r);
		printf("%d\n", a + b - cnt[l] - cnt[r]);
		update(l + 1, 1), update(r, -1), cnt[l] = a, cnt[r] = b;
	}
}

