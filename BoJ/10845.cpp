/* 큐
https://www.acmicpc.net/problem/10845

정수형 큐를 만들어본다
- push X
- pop: front 삭제. 삭제할거없으면 -1
- size: 큐 정수 개수
- empty: 큐가 비어있으면 1 아니면 0
- front: 큐의 앞부분 출력. 없으면 -1
- back: 큐의 가장 뒤부분 출력. 없으면 -1

입력
- 명령어수 N
- N개의 명령어들 (정수는 1 ~ 100,000)

출력
- 각 명령어 출력값들

풀이
- 원형큐 만들어서 해보고싶긴한데, 자료구조공부시간이 아니기때문에 빠르게 해치우자

복습
- .substr() : subString()
- stoi() : string to int
- .find() : return idx or string::npos
- getline(cin, str): 한 라인을 다받음. 카운트꼬일수있음
*/
#include <bits/stdc++.h>
using namespace std;
queue<int> g_Q;
int g_N;
string g_input;
enum Q_INST {
    QPUSH = 0,
    QPOP,
    QSIZE,
    QEMPTY,
    QFRONT,
    QBACK,
};
unordered_map<int,string> g_inst = {
    {QPUSH,"push"},
    {QPOP,"pop"},
    {QSIZE,"size"},
    {QEMPTY,"empty"},
    {QFRONT,"front"},
    {QBACK,"back"},
};

void QueueHandler(string & input)
{
    for(int instIdx = 0; instIdx < g_inst.size(); instIdx++)
    {
        if(g_inst[instIdx] != input)
            continue;
        switch(instIdx)
        {
            case QPUSH:
            {
                int inNum;
                cin >> inNum;
                g_Q.push(inNum);
                break;
            }
            case QPOP:
            {
                if(g_Q.empty())
                    cout << -1 << "\n";
                else
                {
                    cout << g_Q.front() << "\n"; 
                    g_Q.pop();
                }
                break;
            }
            case QSIZE:
            {
                cout << g_Q.size() << "\n";
                break;
            }
            case QEMPTY:
            {
                cout << g_Q.empty() << "\n";
                break;
            }
            case QFRONT:
            {
                if(g_Q.empty())
                    cout << -1 << "\n";
                else
                    cout << g_Q.front() << "\n";
                break;
            }
            case QBACK:
            {
                if(g_Q.empty())
                    cout << -1 << "\n";
                else
                    cout << g_Q.back() << "\n";
                break;
            }
            default:
                break;
        }
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        cin >> g_input;
        QueueHandler(g_input);
    }
    return 0;
}