#include <bits/stdc++.h>
using namespace std;

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int q = partition(array, low, high);
        quickSort(array, low, q - 1);
        quickSort(array, q + 1, high);
    }
}

int main()
{
    int arr[] = {10, 3, 5, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    for(int e: arr){
        cout<<e<<" ";
    }
    return 0;
}