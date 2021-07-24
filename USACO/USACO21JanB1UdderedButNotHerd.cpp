#include <stdio.h>
const int MM = 1005;
char s[MM], t[MM]; int g[26], ans;
int main(){
	scanf("%s %s", s, t);
	for (int i = 0; i < 26; i++) g[s[i] - 'a'] = i;
	for (int i = 1; t[i]; i++) ans += g[t[i] - 'a'] <= g[t[i - 1] - 'a'];
	printf("%d\n", ans + 1);
}
	
