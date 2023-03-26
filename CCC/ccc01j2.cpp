#include <iostream>
int x, n, m;
int main(){
	scanf("%d%d", &x, &m);
	for (int i = 1; i < m; i++) 
		if (x * i % m == 1){n = i; break;}
	if (!n) puts("No such integer exists.");
	else printf("%d", n);
}
