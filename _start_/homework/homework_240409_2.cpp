#include <iostream>
#include <numeric>

using namespace std;

// https://www.acmicpc.net/problem/14916

// 특정 잔돈을 2원 5원만을 사용해 최소한의 동전으로 주기
// 못주면 -1

int main(void)
{
    int money = 0;
    int count = 0;
    int namuG = 0;
    cin >> money;

    if(money <= 1)
    {
        cout << -1;
        return 0;
    }
    
    while(!(money <=8 && money%2 ==0))
    {
        money -=5;
        count++;
    }
    if(money == 0)
    {
        cout<<count;
        return 0;
    }
    while(money >0)
    {
        money -=2;
        count++;
    }
    if(money<0)
    {
        cout <<-1;
        return 0;
    }
    cout << count;
    return 0;
}