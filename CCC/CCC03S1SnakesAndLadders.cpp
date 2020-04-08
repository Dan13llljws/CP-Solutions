#include <iostream>
using namespace std;
int pos = 1;
int main(){
    while(1){
        int n; cin >> n;
        if (!n){
            cout << "You Quit!\n";
            return 0;
        }
        if (pos + n <= 100) pos += n;
        if (pos == 54) pos = 19;
        if (pos == 90) pos = 48;
        if (pos == 99) pos = 77;
        if (pos == 9) pos = 34;
        if (pos == 40) pos = 64;
        if (pos == 67) pos = 86;
        cout << "You are now on square " << pos << '\n';
        if (pos == 100) {
            cout << "You Win!\n";
            return 0;
        }
    }
}