/*윤년 이면 1, 아니면 0 출력하기

윤년
- 4의 배수 년도
- 100의 배수가 아니여야함
- 400의 배수여야함
*/

#include <bits/stdc++.h>
using namespace std;
int _year = 0;
int CheckYear(int &year)
{
    if(year%4 == 0 && (year%100 || year%400 == 0))
        return 1;
    return 0;
}

int main()
{
    cin >> _year;
    cout << CheckYear(_year);
    return 0;
}