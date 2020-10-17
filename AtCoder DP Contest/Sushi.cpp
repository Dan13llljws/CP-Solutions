#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, cnt[4]; double dp[305][305][305];
double rec(int a, int b, int c){
	if (!a && !b && !c) return 0;
	double &ret = dp[a][b][c];
	if (ret > 0.0) return ret;
	int t = a + b + c; ret = 1.0 * n / t;
	if (a) ret += 1.0 * a / t * rec(a - 1, b, c);
	if (b) ret += 1.0 * b / t * rec(a + 1, b - 1, c);
	if (c) ret += 1.0 * c / t * rec(a, b + 1, c - 1);
	return ret;
}
int main(){
	n = read();
	for (int i = 0; i < n; i++) cnt[read()]++;
	printf("%.9f", rec(cnt[1], cnt[2], cnt[3]));
} 
