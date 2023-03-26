#include <iostream>
using namespace std;
int main()
{
    int order[3];
    for (int i = 0; i < 3; i++){
        cin >>order[i];
    }
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            if (order[i] > order[j]){
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
    string abc;
    cin >>abc;
    for (int i = 0; i < 3; i++){
        if (abc[i] == 'A') cout <<order[0]<<"\t";
        if (abc[i] == 'B') cout <<order[1]<<"\t";
        if(abc[i] == 'C')cout <<order[2]<<"\t";
    }

    return 0;
}