#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, tot; ll e;
struct M{
	int a[50][50];
	M operator *(M b){
		M c = M();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					c.a[i][k] = (c.a[i][k] + 1LL * a[i][j] * b.a[j][k] % mod) % mod;
		return c;
	}
} a, ans;
int main(){
	scanf("%d%lld", &n, &e);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a.a[i][j]);
	for (int i = 0; i < n; i++) ans.a[i][i] = 1;
	while(e){
		if (e & 1) ans = ans * a;
		e >>= 1, a = a * a;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tot = (tot + ans.a[i][j]) % mod;
	printf("%d\n", tot);
}

