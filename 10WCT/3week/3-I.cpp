/* https://www.acmicpc.net/problem/17071
숨바꼭질5

수빈이는 동생이랑 숨바꼭질 중(0 ~ 500k)
수빈 움직이기: -1, +1, *2
동생 움직이기: +1.. 가속(+1, +2, +3 ...)
- 동생은 움직이는데 가속이 붙는다.

수빈이가 동생을 찾는시간중에 가장 빠른 시간을 보여라.

Input
- 수빈 동생
Output
- 가장빠르게 찾는시간

Try1
- 히스토리, 이상한 카운트없는 깔끔한 문제
- 단! 시간이 0.25초. 백트래킹을 매우 깔끔하게 해야한다.
- BFS와 예외처리 많이해줘서 시간초과없이 잘풀어보자

Try2
- 동생이 움직이는 문제라 제대로 안풀린다.
- (힌트)
    - 정석적으로 같이 움직였을 때
    - 수빈이가 먼저 도착해서 기다리는 경우 (현재턴과 홀짝체크 중요)
        - flood fill 기법으로 각 turn마다 정확한 큐를 쌓는거 중요
*/
#include <bits/stdc++.h>
#define MIN 0
#define MAX 500001
using namespace std;
int _N, _K;

struct hs_t
{
    int dist = 0;
    int secs = 0;
    int sister = 0;
};
hs_t _ret = {dist: 0, secs:MAX};
vector<int> _v(MAX, MAX);
queue<hs_t> _q;

int sb_walk(int idx, int first)
{
    if(idx = 0)
        return first - 1;
    else if(idx = 1)
        return first * 2;
    else if(idx = 2)
        return first + 1;
}

bool check_visited_value(int val, int cnt)
{
    if(val >= 0 && val < MAX && _v[val] >= cnt)
    {
        _v[val] = cnt;
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _K;
    _ret.dist = MAX;
    _q.push({_N, 0, _K});
    do
    {
        hs_t here = _q.front(); _q.pop();
        int sister = here.sister + here.secs;
        if(sister >= 500000) sister = 500000;

        if(here.secs >= _ret.secs)  continue;
        // cout << "subin:" << here.dist <<", sister:" << sister << ", ret:" << _ret.secs << "\n";
        if(here.dist == sister)
        {
            if(here.secs < _ret.secs)
            {
                _ret = here;
                cout << "(CATCH)subin:" << here.dist <<", sister:" << sister << ", ret:" << _ret.secs << "\n";
                continue;
            }
        }
        // // 동생이 수빈이 뒤에 있다면?
        // if(here.dist > sister + here.secs)17
        // {
        //     int n_subin = here.dist -1;
        //     if(check_visited_value(n_subin, here.secs+1))
        //     {
        //         _q.push({n_subin, here.secs+1, sister});
        //         continue;
        //     }
        // }
        for(int calc = 0; calc < 3; calc++)
        {
            int n_subin = sb_walk(calc, here.dist);
            if(check_visited_value(n_subin, here.secs+1))
                _q.push({n_subin, here.secs+1, sister});
        }
    } while (!_q.empty());
    if(_ret.secs == MAX)    _ret.secs = -1;
    cout << _ret.secs;
    return 0;
}