#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
private:
    unsigned int sz;
    T *arr;

public:
    DynamicArray(T n) : sz(n)
    {
        arr = new T[sz] {};
    }
    
    ~DynamicArray() {delete[] arr;}

    T& operator[] (const int i) {return arr[i];}
    const T& operator[] (const int i) const {return arr [i];}
};

int main(void)
{
    DynamicArray<int> da(5);
    da[0] = 10;
    
    return 0;
}