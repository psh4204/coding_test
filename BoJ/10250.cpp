/* ACM 호텔
고객의 생각
-> 정문에서 부터 걸어서 짧은거리 선호
-> 엘레베이터 이동거리는 생각X. 걷는거리가 같으면 아래층 선호.

Y X 인원 이렇게 주어지면 마지막번째 손님을 몇호에 배정해야하는가?

[입력]
TC
Y X 사람
...

[출력]
YYXX
YXX
...

TC

6
6 12 10
30 50 72
1 100 10
100 1 10
2 50 10
1 1 1

402
1203
111
1001
205
101
*/

#include <bits/stdc++.h>
using namespace std;
int _tc;

int main()
{
    cin >> _tc;
    while (_tc--) {
        int y, x, people;
        cin >> y >> x >> people;

        int yy = (people % y == 0) ? y : people % y;
        int xx = (people % y == 0) ? people / y : people / y + 1;
        printf("%d%02d\n", yy, xx);
    }
    return 0;
}