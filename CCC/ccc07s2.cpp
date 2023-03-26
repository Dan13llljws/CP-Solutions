#include <bits/stdc++.h>
using namespace std; // stupid solve wtfff
void bubbleSortArray(int arr[][3], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j][0] * arr[j][1] * arr[j][2] > arr[j + 1][0] * arr[j + 1][1] * arr[j + 1][2]){
                int temp[3] = {arr[j][0], arr[j][1], arr[j][2]};
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j][2] = arr[j + 1][2];
                arr[j + 1][0] = temp[0];
                arr[j + 1][1] = temp[1];
                arr[j + 1][2] = temp[2];
            }
        }
    }
}
int fitIndex(int box[][3], int item[3], int n){
    for (int i = 0; i < n; i++){
        if (box[i][0] >= item[0] && box[i][1] >= item[1] && box[i][2] >= item[2]) return i;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int boxes[n][3];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            cin >> boxes[i][j];
        }
        sort(boxes[i], boxes[i] + 3);
    }
    bubbleSortArray(boxes, n);
    int m;
    cin >>m;
    int items[m][3];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 3; j++){
            cin >> items[i][j];
        }
        sort(items[i], items[i] + 3);
    }
    for (int i = 0; i < m; i++){
        if (fitIndex(boxes, items[i], n) == -1) cout <<"Item does not fit." <<endl;
        else {
            int index = fitIndex(boxes, items[i], n);
            cout << boxes[index][0] * boxes[index][1] * boxes[index][2] <<endl;
        }
    }
    return 0;
}