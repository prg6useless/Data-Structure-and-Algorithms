#include <iostream>

using namespace std;

void swap(int arr[], int j, int i)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selectionSort(int arr[], int n)
{
    // for descending order
    /*for (int i = 1; i < n; i++) // n-1 because we are comparing with next element
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }*/

    for (int i = 0; i < n - 1; i++) // n-1 because we are comparing with next element
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr, j, i);
            }
        }
    }
}

int main()
{
    // int n;
    // cout << "enter lenght of array :" << endl;
    // cin >> n;

    // for now, n = 6
    int n = 6;
    int arr[n] = {78, 16, 45, 23, 12, 89};

    cout << "Unsorted array is : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    selectionSort(arr, n);

    cout << endl;
    cout << "Sorted array is : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}