#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void _swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void quicksort(int arr[], int pivot, int r)
{
    if(pivot >= r)
        return ;

    int i = pivot + 1;
    int j = r; int cnt = 0;

    while(i <= j)
    {
        while(i <= r && arr[i] < arr[pivot])
            cnt++,i++;
        while(arr[j] > arr[pivot])
            cnt++,j--;
        if(i < j)
        {
            _swap(arr[i], arr[j]);
            print(arr, 8);
        }
    }

    _swap(arr[pivot], arr[j]);
    quicksort(arr, pivot, j-1);
    quicksort(arr, j+1, r);
}

int main()
{
    int arr[] = {8,7,6,4,5,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    quicksort(arr, 0, n-1);
    print(arr, n);

    return 0;
}

