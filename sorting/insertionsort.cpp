#include <iostream>

using namespace std;

int main()
{
    int a[6] = {78, 16, 45, 23, 12, 89};
    int n = 6;

    cout << "Unsorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }

    cout << endl;

    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}