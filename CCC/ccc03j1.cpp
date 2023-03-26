#include <iostream>
int t, s, h;
int main(){
    scanf("%d%d%d", &t, &s, &h);
    for (int i = 0; i < t; i++){
        putchar('*');
        for (int j = 0; j < s; j++) putchar(' ');
        putchar('*');
        for (int j = 0; j < s; j++) putchar(' ');
        puts("*");
    }
    for (int i = 0; i < 3 + 2 * s; i++) putchar('*');
    puts("");
    for (int i = 0; i < h; i++){
        for (int j = 0; j < 1 + s; j++) putchar(' ');
        puts("*");
    }
}
