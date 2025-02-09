#include <bits/stdc++.h>
using namespace std;
int _score = 0;

int main()
{
    cin >> _score;
    if(_score >= 90)
        cout << "A";
    else if(_score >= 80)
        cout << "B";
    else if(_score >= 70)
        cout << "C";
    else if(_score >= 60)
        cout << "D";
    else
        cout << "F";
    return 0;
}