#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c , d, steps, nSteps = 0, bSteps = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &steps);
    bool excute = true;
    int n = steps;
    while(n > 0 && excute){
        int x = a, y = b;
        while(x > 0 && excute){
            nSteps++;
            n--;
            x--;
            if(n == 0) excute = false;
        }
        while(y > 0 && excute){
            nSteps--;
            n--;
            y--;
            if(n == 0) excute = false;
        }
    }
    excute = true;
    n = steps;
    while(n > 0 && excute){
        int x = c, y = d;
        while(x > 0 && excute){
            bSteps++;
            n--;
            x--;
            if(n == 0) excute = false;
        }
        while(y > 0 && excute){
            bSteps--;
            n--;
            y--;
            if(n == 0) excute = false;
        }
    }
    if (nSteps == bSteps) printf("Tied");
    else if (nSteps > bSteps) printf("Nikky");
    else printf("Byron");
    return 0;
}