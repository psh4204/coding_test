#include <bits/stdc++.h>
using namespace std;

int main()
{
    int inNum;
    cin >> inNum;
    for(int cnt = 1; cnt <= 9; cnt++)
        cout << inNum << " * " << cnt << " = " << inNum*cnt << "\n";
    
    return 0;
}