#include <iostream>
using namespace std;
int N, L, a[51];
int main(){
	cin >> N;
	while(N--){
		cin >> L;
		for (int i = 0; i < L; i++) cin >> a[i];
		int cnt = 0;
		for (int i = 0; i < L; i++)
			for (int j = i + 1; j < L; j++)
				cnt += a[i] > a[j];
		cout << "Optimal train swapping takes " << cnt << " swaps.\n";
	}
	return 0;
}
