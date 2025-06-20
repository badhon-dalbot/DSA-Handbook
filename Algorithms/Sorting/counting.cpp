#include <bits/stdc++.h>
using namespace std;

void countSort(int array[], int size)
{
    int output[100];
    int count[100];
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
        cout << output[i] << " ";
    cout << endl;
}

int main()
{
    int array[] = {2, 4, 6, 2, 1, 5, 6, 8};
    int n = sizeof(array) / sizeof(array[0]);
    countSort(array, n);
}