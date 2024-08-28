/* https://www.acmicpc.net/problem/12851
숨바꼭질 2

선 0~ 10k.
수빈이 위치 N, 동생위치 K.
수빙니는 걷거나 순간이동가능.
- 걷기: -1 or +1
- 순간이동: 2*x
위치가 주어졌을때 가장 빠른 시간으로로 찾는 방법이 몇가 지인지 구하라

Input
- N K

Output
- 가장빠른탐색시간
- 방법의 수

Try1
- + - *2 이 세가지 방향으로 완탐해야함.
- 이 완탐은 DFS로 해야할듯. // 저 세가지 조건을 섞어써야하니까.
- 일단 무식하게 풀어보자
- 틀림

Try2
- "최단" 이라했으니까 BFS를 써보자
-- 메모리초과

Try3
- 보완된 코드를 DFS로 짜보자
- 시간초과

Try4
- vistied 배열을 써보자. 이거 안되면 hint보자
---> 시간초과..

... BFS 한번더 해보고 진짜진짜 hint보자
- 39%. BFS 맞았고 vistied 쓰는거 맞았다.

*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int _N, _K;
struct gotch_t
{
    int subin = 0;      // 수빈 위치
    int catch_cnt = 0;  // 잡으러가는시간
    int cnts = 0;   // 최소카운트의 경우의수
};
gotch_t _gotcha = {subin: 0, catch_cnt: MAX, cnts:0};
vector<int> _vv(MAX + 1, MAX);  // 0~ 10000 values and cnt.

int calc(int c_idx, int first)
{
    if(c_idx == 0)
        return first + 1;
    else if(c_idx == 1)
        return first * 2;
    else if(c_idx == 2)
        return first - 1;
}

bool check_vv(int subin, int cnt)
{
    if(_vv[subin] >= cnt)
    {
        _vv[subin] = cnt;
        return true;
    }
    return false;
}

void catch_her_bfs()
{
    queue<gotch_t> q;
    q.push({_N, 0});
    check_vv(_N, 0);
    
    do
    {
        gotch_t here = q.front(); q.pop();
        if(here.subin == _K)
        {
            if(here.catch_cnt == _gotcha.catch_cnt)
                _gotcha.cnts++;
            else if(_gotcha.catch_cnt > here.catch_cnt)
            {
                _gotcha.catch_cnt = here.catch_cnt;
                _gotcha.cnts = 1;
            }
            //cout << _gotcha.catch_cnt << ", " << _gotcha.cnts << "\n";
            continue;
        }
        else
        {
            if(here.catch_cnt > _gotcha.catch_cnt)    continue;
            for(int c_i = 0; c_i < 3; c_i++)
            {
                int n_subin = calc(c_i, here.subin);
                if(n_subin <= MAX && n_subin >= 0 && check_vv(n_subin, here.catch_cnt+1))
                {
                    q.push({n_subin, here.catch_cnt+1});
                }
            }
        }
    } while (!q.empty());
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _K;
    catch_her_bfs();
    cout << _gotcha.catch_cnt << '\n';
    cout << _gotcha.cnts << '\n';    
    return 0;
}