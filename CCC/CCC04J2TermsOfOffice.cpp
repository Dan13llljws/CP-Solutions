#include <iostream>
int x, y;
int main(){
	scanf("%d%d", &x, &y);
	for (; x <= y; x += 60)
		printf("All positions change in year %d\n", x);
}
