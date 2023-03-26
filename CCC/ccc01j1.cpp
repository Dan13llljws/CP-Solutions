#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < min(i * 2 - 1, 2 * n - i * 2 + 1); j++) putchar('*');
		for (int j = 0; j < n - min(i * 2 - 1, 2 * n - i * 2 + 1); j++) putchar(' ');
		for (int j = 0; j < n - min(i * 2 - 1, 2 * n - i * 2 + 1); j++) putchar(' ');
		for (int j = 0; j < min(i * 2 - 1, 2 * n - i * 2 + 1); j++) putchar('*');
		puts("");
	}
}
