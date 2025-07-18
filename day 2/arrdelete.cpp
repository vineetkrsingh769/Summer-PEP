// wap to delete an element from an array
// array={1,2,3,4,5,6}
// del index=2

#include<iostream>
using namespace std;

int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int del= 2;
    int n = 6;
    int pos = -1;

    if(del >= 0 && del< n) {
        for(int i = del; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
