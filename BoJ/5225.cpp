/* IOIOI
https://www.acmicpc.net/problem/5525

IOIOI ... OI 형태로 된 Pn이라 함
- n+1개의 I, n개의 O

주어진 문자열 S에서 Pn이 몇개 나오는지 확인하라

입력
- n M (1~1,000,000)
- S

출력
- 개수 카운트

풀이
- 그냥 카운팅하면 되는거 아님?
- 특별한 알고리즘 없어도 될거같은데..;;
- I O I 체크할때 스택으로 정상체크 해야할 듯
    - 첫 I 받으면 start
    - O, I 받으면 체크 1카운트
    - 만약 규칙에서 벗어난다면 마지막으로 받은거는 뱉음
    - 카운팅 후 dp배열에 저장
    - 마지막 정답체크때 dp배열의 값 체크 할거임
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
char g_input;
struct {
    int nCnt;
    bool isCntStart = false;
    stack<char> stk; // size = 1은 무조건 O 드가있음
}g_IOI;
long long g_correctCnt = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    for(int inCnt = 0; inCnt < g_M; inCnt++)
    {
        cin >> g_input;
        if(g_IOI.isCntStart == true)
        {
            // pass 조건
            if(g_IOI.stk.size() == 0 && g_input == 'O')
            {
                g_IOI.stk.push(g_input);
            }
            else if(g_IOI.stk.size() == 1 && g_input == 'I')
            {
                g_IOI.nCnt++;
                g_IOI.stk.pop();
            }
            // fail 조건
            else
            {
                // 카운트값 체크
                g_IOI.isCntStart = false;
                if(g_IOI.nCnt >= g_N)
                    g_correctCnt += (g_IOI.nCnt - g_N + 1);
                if(!g_IOI.stk.empty())
                    g_IOI.stk.pop();
                g_IOI.nCnt = 0;
            }
        }
        if(g_IOI.isCntStart == false && g_input == 'I')
            g_IOI.isCntStart = true;
    }
    // 마지막 IOI 체크
    if(g_IOI.nCnt >= g_N)
        g_correctCnt += (g_IOI.nCnt - g_N + 1);
    
    cout << g_correctCnt;
    return 0;
}