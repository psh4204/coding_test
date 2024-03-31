#include <iostream>
#include <chrono>

using namespace std;

int sum_reculsive(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum_reculsive(n-1);
    }
}

int sum_iteractive(int n)
{
    int ret = 0;
    do
    {
        ret +=n;
    } while (n--);
    return ret;
}

int main(void)
{
    int count = 3000;
    auto start = chrono::system_clock::now();
    do
    {
        (void)sum_reculsive(1000);  
    }while(count--);
    auto end = chrono::system_clock::now();
    auto msec = chrono::duration<double>(end-start).count() * 1000; 
    cout<< "reculsive: " << msec << "ms" <<endl; 
    
    start = chrono::system_clock::now();
    count = 3000;
    do
    {
        (void)sum_iteractive(1000);
    }while(count--);
    end = chrono::system_clock::now();
    msec = chrono::duration<double>(end-start).count() * 1000;
    cout<< "iteractive: " << msec << "ms" <<endl;
    return 0;
}

/*
reculsive: 23.1839ms
iteractive: 2.9993ms
*/