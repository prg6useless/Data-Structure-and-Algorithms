#include <iostream>
#include <array>

using namespace std;

int main()
{
    int values[5] = {11, 1, 3, 6, 10};
    for (int i = 1; i < 5; i++)
    {
        values[i] = values[i] + values[i - 1];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "values[" << i << "] = " << values[i] << endl;
    }
    values[0] = values[1] + values[4];
    cout << endl;
    cout << "values[0] = " << values[0] << endl;

    cout << endl;

    int array[] = {2, 3, 1, 5, 10};                // length = 20; each index will be of 4 bytes since int is 4 bytes
    int length = sizeof(array) / sizeof(array[0]); // 20/4 = 5
    int *target = new int[length];
    for (int i = 0; i < length; i++)
    {
        target[i] = array[i];
    }

    for (int i = 0; i < length; i++)
    {
        cout << "target[" << i << "] = " << target[i] << endl;
    }
}
