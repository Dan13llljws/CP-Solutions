#include <bits/stdc++.h>
using namespace std;
char str[102]; int n;
int main(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	int r= 0;
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) r = i;
	for (int i = 1; i <= r; i++)
		for (int j = i; j <= n; j += r)
			putchar(str[j]);
	return 0;
}
