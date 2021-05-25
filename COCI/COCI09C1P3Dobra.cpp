#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[101]; int n, cnt, b[101]; ll ans; bool flag; vector<int> v; string vow = "AEIOU";
int main(){
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; i++){
		if (s[i] == '_') cnt++, v.push_back(i);
		else if ((int)vow.find(s[i]) != -1) b[i] = 1;
		if (s[i] == 'L') flag = 1;
	}
	for (int mask = 0; mask < (1 << cnt); mask++){
		for (int i = 0; i < cnt; i++)
			b[v[i]] = mask >> i & 1;
		bool flag2 = 1;
		for (int i = 2; i < n; i++){
			int tot = b[i - 2] + b[i - 1] + b[i];
			if (tot == 0 || tot == 3){flag2 = 0; break;}
		}
		if (flag2){
			ll cur = 1, tmp = 1;
			for (int i = 0; i < cnt; i++)
				if (mask >> i & 1) cur *= 5, tmp *= 5;
				else cur *= 21, tmp *= 20;
			if (!flag) cur -= tmp;
			ans += cur;
		}
	}
	printf("%lld", ans);
}
