#include <iostream>
using namespace std;

#define RANGE 20

void countsort(int arr[], int n)
{
    int i, sorted[n], cnt[RANGE+1] = {0};

    for(i = 0; i < n; i++) {
        cnt[ arr[i] ]++;
    }

    for(i = 1; i <= RANGE; i++) {
        cnt[i] += cnt[i-1];
    }

    for(i = n-1; i >= 0; i--) {
        sorted[ cnt[ arr[i] ] - 1 ] = arr[i];
        cnt[ arr[i] ]--;
    }

    for(i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {7, 2, 5, 4, 6, 12, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    countsort(arr, n);
    print(arr, n);

    return 0;
}
