#include <iostream>
using namespace std;

void _merge(int arr[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(i = 0; i < n2; i++)
        R[i] = arr[m + i + 1];

    i = j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i];
            i++;
        }
        else
        {
            arr[k++] = R[j];
            j++;
        }
    }

    while(i < n1)
    {
        arr[k++] = L[i];
        i++;
    }

    while(j < n2)
    {
        arr[k++] = R[j];
        j++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        _merge(arr, l, m, r);
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
    int arr[] = {17, 45, 35, 23, 5, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n-1);
    print(arr, n);

    return 0;
}
