#include <iostream>
using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection(int arr[], int n)
{
    int i, j, idx;

    for(i = 0; i < n; i++)
    {
        idx = i;

        for(j = i+1; j < n; j++)
        {
            if(arr[idx] > arr[j])
                idx = j;
        }

        Swap(&arr[idx], &arr[i]);
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection(arr, n);
    print(arr, n);

    return 0;
}

