#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {89, 45, 67, 23, 90, 12, 34, 56, 78, 10};
    int i, key, n = 10;
    cout << "Enter the key to be searched: ";
    cin >> key;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "found at index " << i << endl;
            break;
        }
    }
    if (i == n)
        cout << "not found" << endl;
    return 0;
}