#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i=0; i< size -1; i++){
        for(int j=0; j<size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j +1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[]= {3, 2, 7, 1, 9, 6, 8};
    bubbleSort(arr, sizeof(arr)/4);
    for(int i=0; i< sizeof(arr)/4; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}