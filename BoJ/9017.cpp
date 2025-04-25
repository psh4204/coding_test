/* DSLR
https://www.acmicpc.net/problem/9019

계산기 레지스터는 0~ 10000미만 n을 넣을 수 있음
이런n을 저장하며 DSLR연산할때 d를 다음과같이 나눔
- n = ((d1 *10 +d2)x10 +d3)x10 +d4 = d1d2d3d4
    - 각 d1, d2, d3, d4로 나눔

계산기는 다음과 같은 연산을함
- D: n을 두배로 바꾸며, 결과값이 10000 이상일 경우 10000 모듈러 후 저장
- S: n-1을 한다.n이 0인경우 9999 가 레지스터에 저장
- L: 왼쪽으로 한칸이동 -> d2 d3 d4 d1
- R: 오른쪽으로 한칸이동 -> d4 d1 d2 d3

우리는 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램을 작성해야한다
- 최소한의 명령어들을 출력하라

입력
- Tc
- A B (0~9999)
...

출력
- DSLR 명령어조합들

풀이
- BFS문제
    - visited 우짜지
        - 음! 0~9999 까지 이미 방문했는지 체크하자
        - BFS니까 가능한거임
    - 레츠기릿
- 엄~청 많이 틀림
    - 일단, 문제 글 하나 하나 조목조목 잘 읽어봐야함 (DSLR 공식 준수)
    - 그리고 L,R 연산할때 모듈러 잘 쓰면 맞음 (string으로 하면 반드시 시간초과)
*/
#include <bits/stdc++.h>
#define MAX_NUM 10000
using namespace std;
typedef int (*CALC_HANDLER)(const int & input);
int g_TC, g_A, g_B;
typedef struct{
    int num;
    string history;
}CALC_t;

int CalcD(const int & num)
{
    int ret = num * 2;
    return ret >= MAX_NUM? ret%MAX_NUM: ret;
}
int CalcS(const int & num)
{
    if(num == 0)
        return 9999;
    return num - 1;
}
int CalcL(const int & num)
{
    return (num%1000)*10 + (num/1000);
}
int CalcR(const int & num)
{
    return (num/10) + (num%10)*1000;
}
vector<CALC_HANDLER> DslrCalcs = {CalcD, CalcS, CalcL, CalcR};
string g_DSLR = "DSLR";

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    for(int tcCnt = 0; tcCnt<g_TC; tcCnt++)
    {
        vector<int> visited(MAX_NUM, 0);
        cin >> g_A >> g_B;
        
        queue<CALC_t> calcQ;
        string answer;
        calcQ.push({g_A, ""});
        visited[g_A] = 1;
        while(!calcQ.empty())
        {
            CALC_t now = calcQ.front();
            bool isFind = false;
            calcQ.pop();
            for(int calcIdx = 0; calcIdx < 4; calcIdx++)
            {
                CALC_t next = {
                    DslrCalcs[calcIdx](now.num), 
                    now.history
                };
                if(visited[next.num] == 1)
                    continue;
                next.history += g_DSLR[calcIdx];
                if(next.num == g_B)
                {
                    isFind = true;
                    answer = next.history;
                    break;
                }
                visited[next.num] = 1;
                calcQ.push(next);
            }
            if(isFind)
                break;
        }
        cout << answer << "\n";
    } 
    return 0;
}