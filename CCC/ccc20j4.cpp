#include <iostream>
using namespace std;
string a, b;
int main(){
	cin >> a >> b;
	int n = a.size(), m = b.size();
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			if (a.substr(j, m) == b)return 0 * printf("yes\n");
		b = b.substr(1, n - 1) + b[0];
	}
	return 0 * printf("no\n");
}
