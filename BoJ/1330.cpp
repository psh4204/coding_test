/*https://www.acmicpc.net/problem/1330
두수비교하기
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first, second, ret;
    cin >> first >> second;
    ret = first - second;
    if(ret == 0) cout << "==";
    else if(ret > 0 ) cout << ">";
    else if (ret < 0) cout << "<";
    return 0;
}