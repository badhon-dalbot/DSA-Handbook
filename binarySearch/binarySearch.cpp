#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int low = 0; 
    int high = size -1;
    int mid = (high + low) / 2;
    while (low < high)
    {
        if(arr[mid] == key)
        return mid;
        else if(arr[mid] < key){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {2, 3, 6, 7, 9};
    int index = binarySearch(arr, sizeof(arr)/4, 6);
    index != -1 ? cout<< "Found at " << index : cout<< "Not Found"; 
    return 0;
}