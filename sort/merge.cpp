#include <bits/stdc++.h>
using namespace std;
void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int Left[n1 + 1];
    int Right[n2 + 1];
    int i, j;
    for (i = 0; i < n1; i++)
    {
        Left[i] = array[left + i];
    }
    Left[i] = INT_MAX;

    for (j = 0; j < n2; j++)
    {
        Right[j] = array[mid + 1 + j];
    }
    Right[j] = INT_MAX;
    i = 0;
    j = 0;
    for (int k = left; k <= right; k++)
    {
        if (Left[i] < Right[j])
        {
            array[k] = Left[i];
            i++;
        }
        else
        {
            array[k] = Right[j];
            j++;
        }
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int array[] = {18, 23, 56, 24, 37, 26, 28, 48};
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    mergeSort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}