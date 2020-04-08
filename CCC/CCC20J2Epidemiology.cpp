#include <iostream>
using namespace std;
int P, N, R, tot;
int main(){
	cin >> P >> N >> R;
	for (int i = 0;;i++){
		tot += N;
		if (tot > P) return 0 * printf("%d", i);
		N *= R;
	}
	return 0;
}
