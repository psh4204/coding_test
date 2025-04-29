/* 평벙한 배낭
https://www.acmicpc.net/problem/12865

배낭을 최대한 가성비있게 싸려한다
- N개의 물건은 각 무게W, 가치V를 가진다
- 무게제한은 K

가장 가성비있게 가방을 쌌을때 가지는 최대 가치는?

입력
- N (1~100) K(1~100,000)
- N줄에 거쳐 W(1~100,000) V(0~1,000)

출력
- 최대 가치

풀이
- 일단 가방을 싸보는 테이블 그려보자
- 두가지 포인트 기억하자
    - 가방을 싼다
    - 가방을 싸지 않는다
    - 현재 무게의 최대값을 구한다

6 9
5 8
4 2
3 2
1 3
1 1
5 8
ans: 13
- 

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N, g_K;
ll g_maxValue, g_kg;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_K;

    return 0;
}