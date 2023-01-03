#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;

    int LeftArr[n1], RightArr[n2]; /*temporary arrays*/

    for (int i = 0; i < n1; i++)
    {
        LeftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        RightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (LeftArr[i] < RightArr[j])
        {
            arr[k] = LeftArr[i];
            k++;
            i++;
        }

        else
        {
            arr[k] = RightArr[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = LeftArr[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = RightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{

    int arr[6] = {78, 16, 45, 23, 12, 89};
    cout << "Unsorted array is : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, 5);
    cout << endl;
    cout << "Sorted array is : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}