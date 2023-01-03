#include <iostream>

using namespace std;

int main()
{
    int a[10] = {1, 5, 11, 15, 19, 26, 37, 48, 59, 61};
    int min = 0;
    int max = 10 - 1;
    int t;
    cout << "Enter the target : ";
    cin >> t;
    while (max >= min)
    {
        int mid = (min + max) / 2;
        if (a[mid] == t)
        {
            cout << "Found at index " << mid;
            break;
        }
        else if (a[mid] < t)
            min = mid + 1;
        else
            max = mid - 1;
    }
    if (max < min)
    {
        cout << "Not found";
    }
    return 0;
}
