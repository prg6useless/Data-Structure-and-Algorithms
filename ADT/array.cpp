#include <iostream>

using namespace std;

// array using pointer

int main()
{
    float a[4];
    float *ptr;

    ptr = &a[2];

    *ptr = 3.14;

    ptr++;

    *ptr = 9.0;

    ptr = ptr - 3;

    *ptr = 6.0;

    ptr += 1;

    *ptr = 7.0;

    ptr = ptr + 3;

    *ptr = 3.16;

    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;
}