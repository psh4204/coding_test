/*
https://www.acmicpc.net/problem/1629
곱셈

A를 B번 곱한 후 C로 나눈 나머지 값 출력 (시간0.5초)

Input
- A B C (각 int형 범위)

Output
- 나머지 값

Try1
- 수학문제네. 잘못 곱하면 long long도 금방 도달할거임. 그래서 C를 중간에 써야할 수 밖에 없는데,
- 수학식을 세워보자.
- N*N*N ... % C = (N*N)%C*N%C ... 
- 이렇게 for문 짜면 끝날듯
==> 시간초과

Try2
- int 최대값을 받았을때를 기준으로 2회 제곱계산 후 나머지 계산하는 형식으로 진행하겠음.
==> 시간초과

Try3
- _A와 _C가 같은경우는 어차피 나머지가 없을거니까 0 리턴함
- 나머지값으로 제곱하면서 값 구해도 답 나올거같음
    - A가 C보다 작은 경우 더커질때까지 _A를 제곱해서 키움. 그리고 그것에 맞게 잘 처리
    - A가 C보다 큰경우. 바로 나머지값 구해서 제곱해서 값 처리.
==> 틀렸습니다.

Try4
- (힌트) a * a -> A. A * A = a^2 * a^2.
    - 뭐 어쩌라는거야
- B값을 log2B로 줄일 수 있음.
- 2억번 루프돌리는걸 log2 2억 이런식으로 줄여버릴 수 있음... (중학교 다시가자그냥)
*/
#include <bits/stdc++.h>
using namespace std;
int _A =0, _B = 0, _C = 0;

long long calc_ret(long long a, long long b)
{
    long long ret = 0;
    if(b == 1) return a % _C;
    ret = calc_ret(a, b/2);
    ret = (ret * ret) % _C;
    if(b % 2 == 1) // 현재 b가 홀수일 경우 한번 더 곱해준다. (a*a) = 짝수B. (a*a*a) = 홀수B. 
        ret =  ret * a % _C;
    return ret;
}

int main()
{
    long long ret = 1;
    cin >> _A >> _B >> _C;
    ret = calc_ret(_A, _B);
    cout << ret;
    return 0;
}