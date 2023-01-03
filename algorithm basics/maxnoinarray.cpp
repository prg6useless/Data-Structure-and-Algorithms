#include <iostream>

using namespace std;

int main()
{
    int array[5] = {56, 78, 90, 12, 34};
    int result = array[0];
    for (int i = 0; i <= 5; i++)
    {
        if (array[i] > result)
        {
            result = array[i];
        }
    }
    cout << "max no in array is " << result << endl;
}