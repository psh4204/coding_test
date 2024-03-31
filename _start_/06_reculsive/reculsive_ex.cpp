#include <iostream>
#include <chrono>

using namespace std;

int main(void)
{
    int count = 3000;
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    auto msec = chrono::duration<double>(end-start).count() * 1000; 
    cout<< "reculsive: " << msec << "ms" <<endl; 

    return 0;
}
