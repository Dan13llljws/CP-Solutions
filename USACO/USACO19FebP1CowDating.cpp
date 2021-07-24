#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n; double ans, cur, pre, p[MM];
int main(){
	n = re, pre = 1.0;
	for (int i = 0; i < n; i++) p[i] = re / 1e6;
	for (int i = 0, j = 0; i < n; i++){
        while(j < n && cur < 1) cur += p[j] / (1 - p[j]), pre *= (1 - p[j]), j++;
        ans = max(ans, cur * pre), cur -= p[i] / (1 - p[i]), pre /= (1 - p[i]);
	}
	ans *= 1e6;
    printf("%d\n", (int)ans);
}

