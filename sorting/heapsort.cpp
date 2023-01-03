#include <iostream>

using namespace std;

// heap sort chai bujeko xaina

void swap(int arr[], int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[i] < arr[l])
        largest = l;

    if (r < n && arr[largest] < arr[r])
        largest = r;

    if (largest != i)
    {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    // int startIdx = n - 1;  /* this is also correct */
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    build_heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr, i, 0);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[6] = {78, 16, 45, 23, 12, 89};

    int n = 6;

    cout << "Unsorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);

    cout << endl;

    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}