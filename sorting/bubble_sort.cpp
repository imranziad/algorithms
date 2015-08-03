#include <iostream>
using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int arr[], int n)
{
    int i, j;
    bool swapped;

    for(i = 0; i < n-1; i++)
    {
        swapped = false;

        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = true;
                Swap(&arr[j], &arr[j+1]);
            }
        }

        if(swapped == false)
            break;
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

    bubble(arr, n);
    print(arr, n);

    return 0;
}

