#include <iostream>
using namespace std;
int s, m, l;
int main(){
	cin >> s >> m >> l;
	cout << (s + m * 2 + l * 3 >= 10 ? "happy" : "sad");
	return 0;
}
