#include <iostream>

using namespace std;

int main(void)
{
    int* ptr = new int[3] {0x00, };
    ptr[0] = 10;
    ptr[1] = 20;

    for(int i = 0; i < 3; i++)
    {
        cout << ptr[i] << endl;
    }

    delete [] ptr; // 해제
    ptr = nullptr; // 해제 후 null

    return 0;
}