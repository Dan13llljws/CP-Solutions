#include <iostream>
int pos = 1, n;
int main(){
    while(scanf("%d", &n)){
        if (!n) return 0 * puts("You Quit!");
        if (pos + n <= 100) pos += n;
        if (pos == 54) pos = 19;
        if (pos == 90) pos = 48;
        if (pos == 99) pos = 77;
        if (pos == 9) pos = 34;
        if (pos == 40) pos = 64;
        if (pos == 67) pos = 86;
        printf("You are now on square %d\n", pos);
        if (pos == 100) return 0 * puts("You Win!");
    }
}
