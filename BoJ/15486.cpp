/* 퇴사2
https://www.acmicpc.net/problem/15486

N일의 상담스케줄(걸리는시간 T일, Pay)을 받았을때,
N일안에 가장 많이 벌 수 있는 Pay 합을 구하라

입력
- N
- Day Pay
- ...

출력
- MaxPaySum

풀이
- 0. dp에 해당 Day의 칸은, 가장 큰 Pay를 가지고있다는 설정하에 진행
- 1. Day 후에 Pay를 받는다는 점
- 2. 상담을 건너뛸 수도 있음
- 3. 상담을 안받아도, 이미 있는 값이 더 크면 유지 (이월)
- 순방향으로 보는게 더 좋음. 그래도 풀림 (역방향으로했다가 머리 터짐)

[Note]
- (4시간동안 답찾기에 혈안이었음. 수없이 틀린듯.. )
- 결국 다음 포인트를 못집어서 못푼거였음
    - "돈을 받는 시점은 일을 다한 후"
    - "상담을 무시할 수 있음"
- 이걸 dp로 풀어나가면 O(n)에 풀수있었음 (최초 접근방식이 거의 정답이었다..)
*/
#include <bits/stdc++.h>
using namespace std;
struct Work_t{
    int day;
    int pay; 
};
vector<Work_t> g_works(1500001);
vector<long long> g_paySums(1500001); // 현재 금액은 항상 최고치
int g_N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    for(int inCnt = 0; inCnt< g_N; inCnt++)
    {
        cin >> g_works[inCnt].day >> g_works[inCnt].pay;
    }
    for(int nowDay = 0; nowDay < g_N; nowDay++)
    {
        int nPayDay = 0; // nextPayDay = 돈받는 날

        // 상담을 받는 경우
        if(g_works[nowDay].day + nowDay <= g_N)
        {
            nPayDay = nowDay+g_works[nowDay].day;
            g_paySums[nPayDay] = 
                max(g_works[nowDay].pay + g_paySums[nowDay], g_paySums[nPayDay]);
        }
        // 상담을 받지 않는 경우
        nPayDay = nowDay+1;
        g_paySums[nPayDay] = max(g_paySums[nowDay], g_paySums[nPayDay]);
    }
    cout << g_paySums[g_N];
    return 0;
}