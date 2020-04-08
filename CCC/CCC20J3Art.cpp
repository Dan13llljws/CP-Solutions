#include <iostream>
#include <algorithm>
using namespace std;
int n, x1 = 1e9, x2, y1 = 1e9, y2;
int main(){
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; i++){
		scanf("%d,%d", &x, &y);
		x1 = min(x1, x - 1), x2 = max(x2, x + 1), y1 = min(y1, y - 1), y2 = max(y2, y + 1);
	}
	printf("%d,%d\n%d,%d", x1, y1, x2, y2);
	return 0;
}
