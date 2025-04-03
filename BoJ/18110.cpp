/* solved.ac
https://www.acmicpc.net/problem/18110

문제난이도
- 0: 아무의견없음
- 30%절사평균: 의견있음

(절사평균)
- 가장 큰값과 가장 작은값을 없앤 후 평균내는것
- 30%: 가장큰 15% 가장작은 15% 없앤 값

무엇을 계산하던 반올림한다
- 반올림함수: round()

사용자 의견을 듣고 난이도를 구하라

입력
- N: 사람수
- 문제난이도들

출력
- 절사평균 (30%. 반올림)

노트:
- 반올림: round()
*/
#include<bits/stdc++.h>
using namespace std;
int g_N;
double g_zulsa, g_avg;
vector<double> g_scores;

int main()
{
    cin >> g_N;
    int loopCnt = g_N;
    if(g_N == 0)
    {
        cout << 0;
        return 0;
    }
    while(loopCnt--)
    {
        double score;
        cin >> score;
        g_scores.push_back(score);
    }
    sort(g_scores.begin(), g_scores.end());
    g_zulsa = ((double)g_N * 0.3)/2;
    g_zulsa = round(g_zulsa);
    for(int manIdx = g_zulsa; manIdx < g_N-g_zulsa; manIdx++)
        g_avg += g_scores[manIdx];
    g_avg = g_avg / (g_N-g_zulsa*2);
    g_avg = round(g_avg);
    cout << (int)g_avg;
    return 0;
}