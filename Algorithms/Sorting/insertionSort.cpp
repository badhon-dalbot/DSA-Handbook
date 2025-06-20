#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[i];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {3, 5, 2, 4, 1, 9, 7, 8};
    insertionSort(arr, sizeof(arr) / 4);
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}