#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 515;
int n, psa[MM][MM], g[MM][MM]; unordered_map<ll,vector<int>> ans;
ll hsh(int a, int b, int c, int d){return 1e9 * a + 1e6 * b + 1e3 * c + d;}
int get(int a, int b, int c, int d){return psa[c][d] - psa[c][b - 1] - psa[a - 1][d] + psa[a - 1][b - 1];}
int rec(int a, int b, int c, int d){
	if (a == c && b == d) return 0;
	int mx = (a + c) >> 1, my = (b + d) >> 1;
	vector<int> res = {rec(a, b, mx, my), rec(a, my + 1, mx, d), rec(mx + 1, b, c, my), rec(mx + 1, my + 1, c, d)};
	vector<int> sum = {get(a, b, mx, my), get(a, my + 1, mx, d), get(mx + 1, b, c, my), get(mx + 1, my + 1, c, d)};
	int ret = 1e9;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			if (i == j) continue;
			int tmp = 0;
			for (int k = 0; k < 4; k++)
				if (k ^ j && k ^ i) tmp += res[k];
			tmp += sum[i] + (c - a + 1) * (c - a + 1) / 4 - sum[j];
			if (ret > tmp){
				ret = tmp; vector<int> vec(4, 2);
				vec[i] = 0, vec[j] = 1, ans[hsh(a, b, c, d)] = vec;
			}
		}
	return ret;
}
void fil(int a, int b, int c, int d){
	if (a == c){g[a][b] = psa[a][b] - psa[a - 1][b] - psa[a][b - 1] + psa[a - 1][b - 1]; return;}
	int mx = (a + c) >> 1, my = (b + d) >> 1;
	vector<int> v = ans[hsh(a, b, c, d)], aa = {a, a, mx + 1, mx + 1}, bb = {b, my + 1, b, my + 1}, cc = {mx, mx, c, c}, dd = {my, d, my, d}; 
	for (int i = 0; i < 4; i++)
		if(v[i] == 2) fil(aa[i], bb[i], cc[i], dd[i]);
		else for (int j = aa[i]; j <= cc[i]; j++)
			for (int k = bb[i]; k <= dd[i]; k++)
				g[j][k] = v[i];
}
int main(){
	scanf("%d", &n); getchar();
	for (int i = 1; i <= n; i++, getchar())
		for (int j = 1; j <= n; j++)
			psa[i][j] = getchar() - '0' + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
	printf("%d\n", rec(1, 1, n, n)); fil(1, 1, n, n);
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= n; j++) printf("%d", g[i][j]);
}
