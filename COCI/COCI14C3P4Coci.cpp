#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define f first
#define s second
const int mod = 1e9 + 7, MM = 655;
int n, psa[MM][MM]; pii p[500005];
int main(){
	n = re;
	for (int i = 0; i < n; i++) p[i] = {re + 1, re + 1}, psa[p[i].f][p[i].s]++;
	for (int i = 1; i < MM; i++)
		for (int j = 1; j < MM; j++)
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
	for (int i = 0; i < n; i++){
		printf("%d ", psa[651][651] - psa[651][p[i].s] - psa[p[i].f][651] + psa[p[i].f][p[i].s] + 1);
		printf("%d\n", n - psa[p[i].f - 1][p[i].s - 1] - (p[i].f == 651) * (psa[1][p[i].s] - psa[1][p[i].s - 1]) - (p[i].s == 651) * (psa[p[i].f][1] - psa[p[i].f - 1][1]));
	}
}
