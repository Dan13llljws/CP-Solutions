#include <bits/stdc++.h>
using namespace std;
int main()
{
    int j, a;
    cin >> j >> a;
    int jerseys[j + 1];
    int number[a];
    char sizes[a];
    int maxCount = 0;
    for (int i = 0; i < j; i++){
        char x;
        cin >> x;
        jerseys[i + 1] = x;
    }
    for (int i = 0; i < a; i++){
        cin >> sizes[i] >> number[i];
    }
    for (int i = 0; i < a; i++){
        //cout << ss << "\t" << mm << "\t" << ll << "\t" << maxCount << "\t" << number[i] << "\t" << num[number[i]] <<endl;
        if(jerseys[number[i]] <= sizes[i]){
            maxCount++;
            jerseys[number[i]] = 100;
        }
    }
    cout << maxCount <<endl;

    return 0;
}