#include <bits/stdc++.h>
using namespace std;
char s[5]; int dp[1<<20][2], a; string color = "RYGB";
int rec(int mask, bool turn){
	int &ret = dp[mask][turn], rem = __builtin_popcount(mask) / 2;
	if (ret != -1) return ret;
	if (!mask) return ret = 0;
	ret = 0;
	for (int i = 0; i < 20; i++){
		if (!(mask >> i & 1) || (a >> i & 1) != turn) continue;
		int tmp = 1e9;
		for (int j = i / 5 * 5; j < i / 5 * 5 + 5; j++){
			if (!(mask >> j & 1) || (a >> j & 1) == turn) continue;
			tmp = j > i ? min(tmp, rem - 1 - rec(mask ^ (1 << i) ^ (1 << j), !turn)) : min(tmp, 1 + rec(mask ^ (1 << i) ^ (1 << j), turn));
		}
		if (tmp == 1e9){
			for (int j = 0; j < 20; j++){
				if (!(mask >> j & 1) || (a >> j & 1) == turn) continue;
				tmp = min(tmp, 1 + rec(mask ^ (1 << i) ^ (1 << j), turn));
			}
		} ret = max(ret, tmp);
	}
	return ret;
}
int main(){
	while(1){
		bool flag = 0; a = 0;
		for (int i = 0; i < 10; i++){
			scanf("%s", s);
			if (s[0] == '*'){flag = 1; break;}
			a |= 1 << (color.find(s[0]) * 5 + s[1] - '0' - 1);
		}
		if (flag) break;
		memset(dp, -1, sizeof dp);
		printf("%d\n", rec((1 << 20) - 1, 1));
	}
}
