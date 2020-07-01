#include <iostream>
int a, b, cnt = 1;
int main(){
	scanf("%d%d", &a, &b);
	puts("Sun Mon Tue Wed Thr Fri Sat");
	for (int i = 1; i < a; i++, cnt++) printf("    ");
	for (int i = 1; i <= b; i++, cnt++){
		if (i < 10) printf("  %d", i);
		else printf(" %d", i);
		putchar(!(cnt%7) || i == b ? '\n' : ' ');
	}
}
