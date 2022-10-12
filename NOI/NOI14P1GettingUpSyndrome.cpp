#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, m, t[MM], tp[MM]; char cmd[10];
int get(int i, int x){
	for (int j = 0; j < n; j++){
		if (tp[j] == 0) x &= t[j] >> i & 1;
		else if (tp[j] == 1) x |= t[j] >> i & 1;
		else x ^= t[j] >> i & 1;
	}
	return x;
}
int main(){
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s %d", cmd, t + i);
		if (cmd[0] == 'A') tp[i] = 0;
		else if (cmd[0] == 'O') tp[i] = 1;
		else tp[i] = 2;
	}
	int ans = 0; bool less = 0;
	for (int i = 30; i >= 0; i--){
		int a = get(i, 0), b = get(i, 1);
		if (a || (b && (less || m >> i & 1))) ans |= 1 << i;
		if ((a || (!a && !b)) && m >> i & 1) less = 1;
	}
	printf("%d\n", ans);
}
