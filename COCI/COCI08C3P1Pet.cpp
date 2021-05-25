#include <iostream>
using namespace std;
int id, p;
int main(){
	for (int i = 1; i <= 5; i++){
		int sum = 0;
		for (int j = 0, a; j < 4; j++) {cin >> a; sum += a;}
		if (sum > p){
			p = sum;
			id = i;
		}
	}
	cout << id << ' ' << p; 
	return 0;
}
