#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {2, 5, 6, 6, 3, 8};
    int index = search(arr, sizeof(arr)/4, 5);
    index == -1 ? cout<< "Not Found" : cout<< "Found at index"<< index;
    return 0;
}