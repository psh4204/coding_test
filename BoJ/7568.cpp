/* 덩치
https://www.acmicpc.net/problem/7568

몸무게 x, 키 y 인사람들끼리 덩치비교를 한다
- 키와 몸무게가 더 큰사람이 반드시 덩치가 큰편이고,
- 키와 몸무게 둘다 안크면 덩치가 더 크다고 할 수 없다

본인보다 더 큰사람이 나타나면 덩치등수 + 1이 된다

각 사람들의 스펙을 받았을때 각자 덩치등수를 구해본다

입력
- N (사람수 2 ~ 50)
- x y (10 ~ 200)

풀이
- 간단한 탐색문제
- 각 사람 한명씩 뽑아서 스펙비교를 한다.
    - 그 후 둘다 더큰사람이 나타났을 때 덩치점수 + 1을 한다
    - (말장난) 아예 두개다 큰놈이 덩치를 큰놈으로 인식 해야한다
*/
#include <bits/stdc++.h>
using namespace std;
struct Man_t{
    int cm;
    int kg;
    int point = 1;
};

int g_N;
vector<Man_t> g_mans;

void CompareWithMan(Man_t & first, Man_t & second)
{
    int firstWinCnt = 0, secondWinCnt = 0;
    if(first.cm > second.cm)
        firstWinCnt++;
    else if(first.cm < second.cm)
        secondWinCnt++;
    
    if(first.kg > second.kg)
        firstWinCnt++;
    else if(first.kg < second.kg)
        secondWinCnt++;
    
    if(firstWinCnt == 2)
        second.point++;
    else if(first.cm == 2)
        first.point++;
}

int main()
{
    cin >> g_N;
    g_mans.resize(g_N);
    for(int manIdx = 0 ; manIdx < g_N; manIdx++)
        cin >> g_mans[manIdx].kg >> g_mans[manIdx].cm;
    
    for(int mainIdx = 0 ; mainIdx < g_N; mainIdx++)
    {
        for(int subIdx = 0; subIdx < g_N; subIdx++)
        {
            if(mainIdx == subIdx)   continue;
            CompareWithMan(g_mans[mainIdx], g_mans[subIdx]);
        }
    }

    for(auto man: g_mans)
        cout << man.point << " ";
    cout << "\n";
    return 0;
}