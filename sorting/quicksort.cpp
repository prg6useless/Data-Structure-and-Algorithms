#include <iostream>
#include <string>

using namespace std;

// void swap(string arr[], int left, int right)
void swap(int arr[], int left, int right)
{
    int temp;
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

// int partition(string arr[], int left, int right)
int partition(int arr[], int left, int right)
{
    // string pivot = arr[right];
    int pivot = arr[right]; /*pivot element chosen as the right most element of the array*/

    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, right); /*now pivot element is in its correct position*/
    return i + 1;
}

// void quickSort(string arr[], int left, int right)
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotpos = partition(arr, left, right); /*to get the position of pivot*/

        quickSort(arr, left, pivotpos - 1);
        quickSort(arr, pivotpos + 1, right);
    }
}

int main()
{

    // string arr[6] = {"raja", "govinda", "raj", "hi", "hiq", "govind"};
    int arr[6] = {78, 16, 45, 23, 12, 89};
    cout << "Unsorted array is : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    quickSort(arr, 0, 5);
    cout << endl;
    cout << "Sorted array is : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}