#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input;
    cin >> input;
    for(int lineCount = 0; lineCount < input; lineCount++)
    {
        for(int starCount = 0; starCount <= lineCount; starCount++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}