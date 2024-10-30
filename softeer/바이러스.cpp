/* 바이러스
바이러스는 숙주몸에서 1초당 P배 씩 증가.
K마리가 있다면, N초 후 총 몇마리의 바이러스로 불어날까?

입력
- K P N (바이러스수 1~10^8. 증가율 1~10^8, 총시간 1~10^6)

출력
- ( 총 바이러스 수 % 1000000007 )을 구하라.

풀이
- K*P
*/ 

#include<bits/stdc++.h>
using namespace std;

long long _K, _P, _N, _answer = 1;

int main(int argc, char** argv)
{
    cin >> _K >> _P >> _N;
    _answer = _K;
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        _answer = (_answer * _P)% 1000000007;
    cout << _answer;
    return 0;
}