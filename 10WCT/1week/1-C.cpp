/*
2979: 트럭주차
트럭 3대, 트럭주차비용 계산.
- 트럭주차 수에 따라 요금할인.
- 1대할때 1분에 A원, 2대 1분에 B원, 3대 1분에 C원.
- A,B,C 와 minute 주어지면 요금 계산하기

input
- A B C = 1~100
- 차1번 도착시간 떠난시간 = 1~100
- 차2번 도착시간 떠난시간 = 1~100
- 차3번 도착시간 떠난시간 = 1~100

해석
- cin(스페이스,엔터로 값을 받음) 으로 각 값을 받은 후 바로 카운트배열에 저장
- 카운트배열 계산 후 값 출력

오답-풀이
- cin으로 받을땐 UART처럼 무조건 타입이 string, char가 아닌, 입력받을 파라미터의 타입형태임
- 시작(이상), 끝(미만)을 기억하라
- 모듈화도 좋지만, 입력받자마자 한번에 처리하는 것처럼 효율적으로 코드작성하는것을 해야한다.
- Test Print 같은 것은 "제발" 지우고 제출하자..
*/
#include <bits/stdc++.h>
using namespace std;

int _abc_money[4] = {0,};
int _park_cnt[100] = {0,};
int _ret = 0;

void input()
{
    // A,B,C 입력
    cin >> _abc_money[1] >> _abc_money[2] >> _abc_money[3];
    for(int truck = 0; truck < 3; truck++)
    {
        // 시작시간 끝시간 받은 후 바로 카운트배열 카운트.
        int start_time, end_time =0;
        cin >> start_time >> end_time;
        for(start_time ; start_time < end_time; start_time++)
        {
            _park_cnt[start_time]++;
        }
    }
}

void calc_and_print()
{
    for(auto parked_truck: _park_cnt)
        _ret += parked_truck*_abc_money[parked_truck];
    cout << _ret;
}

int main()
{
    input();
    calc_and_print();

    return 0;
}