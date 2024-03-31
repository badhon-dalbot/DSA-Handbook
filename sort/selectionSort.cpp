#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int size){
    for(int i=0; i< size -1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[] = {4, 2, 1, 7,9, 8};
    selectionsort(arr, sizeof(arr)/4);
    for(int i=0; i< 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}