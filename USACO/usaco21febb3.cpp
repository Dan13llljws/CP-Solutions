#include <bits/stdc++.h>
using namespace std;
int n; char s[105];
int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		int t = 0;
		for (int i = 1; s[i]; i++){
			if (s[i] == s[i - 1]) continue;
			if ((s[i] == 'N' && s[i - 1] == 'W') || (s[i] == 'W' && s[i - 1] == 'S')
			 || (s[i] == 'S' && s[i - 1] == 'E') || (s[i] == 'E' && s[i - 1] == 'N')) t++;
			else t--; 
		}
		if (t > 0) puts("CW");
		else puts("CCW");
	}
}
