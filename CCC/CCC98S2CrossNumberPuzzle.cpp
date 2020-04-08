#include <bits/stdc++.h>
using namespace std;
int cb(int x){return x * x * x;}
int main(){
	for (int i = 1000; i <= 9999; i++){
		int sum = 0;
		for (int j = 1; j < i; j++)
			if (i % j == 0) sum += j;
		if (sum == i) cout << i << ' ';
	}
	cout << endl;
	for (int i = 100; i <= 999; i++){
		int a = i % 10, b = i / 10 % 10, c = i / 100;
		if (cb(a) + cb(b) + cb(c) == i) cout << i << ' ';
	}
	return 0;
}
