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
- 물건 100개면 DFS로 조합만들기 체크하기. (왜 DP문제라고 기억을하지?)
- sort로 가방이 가장 가벼우면서, Value가 높은값을 가져오자
    - 시간초과

- max값 얻는 타이밍
    - max K 혹은 아이템수 g_N까지 도달했을때 max Value값 체크
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