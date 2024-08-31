/* https://www.acmicpc.net/problem/13913
숨바꼭질4

0~100k 구간에서 수빈이와 동생은 숨바꼭질 중.
수빈이가 움직이는건 숨바꼭질2와 같은룰 (+1, -1, *2)

동생위치가 주어지면 가장 빠르게 찾는 시간이 몇인지 구하기

Input
- N K
Output
- 가장빨리찾은시간
- 어떻게 이동하는지 출력

Try1
- 최단시간 = BFS
    - 큐에는 이동계산값, 이동카운트, 이동히스토리
    - 각 값마다 visited cnt 넣자
- 이동히스토리는 스트링으로 담자

Try2
- 6% 시간초과
- 예외처리하자.
- 수빈이가 앞질러갔을땐 무조건 -1 해줘야하네

Try3
- 26% 시간초과
- visited를 잘못썼나..?
- 아.. 족같다

- history 처리가 시간이 어---마어마하게 오래걸림.
    - stack을 쓰던 string을 쓰던 복붙하는데 O(n)이라는 시간이 걸리기때문에
    - 지랄날수밖에없음
    - 그럼 어케해야할까
        - 전역변수에 리스트 쌓자. 그거로 히스토리 관리가능
        - 큐 pop하고 계산 후에 리스트에서 넣고 빼는걸 잘해야함.

도저히 안돼서 hint봄
- 내가 고민하는 부분이 맹점인 문제가맞음
    - 히스토리
- 히스토리를 Trace하는 문제는 어떻게 해야하는가?
    - prev[lr]
    - CS적으로 접근하자면 이러함
        - lr을 각 스택프레임에 저장해서 컨텍스트를 저장하고 돌아가듯,
        값 배열에 lr을 저장시켜서 돌아가게 하는거임.
    - 계산을 해서 해당 prev에 히스토리를 박아두는거임. 
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int _N, _K;
struct _gotcha_t
{
    int subin = 0;
    int move_cnt = MAX;
};

vector<int> _v(MAX+1, MAX);
vector<int> _history(MAX, MAX);
queue<_gotcha_t> _q;
_gotcha_t _ret;
deque<int> _ret_hist;

// 해당 수빈값을 visited내에 카운트와 비교후, 지금카운트가 같거나 작으면 true. 
bool is_ok_v_value(int subin, int cnt)  
{
    if(_ret.move_cnt > cnt && subin >= 0 && subin <=MAX &&_v[subin] > cnt)
    {
        _v[subin] = cnt;
        return true;
    }
    return false;
}

int calc(int c_idx, int first)
{
    if(c_idx == 0)
        return first*2;
    else if(c_idx == 1)
        return first+1;
    else if(c_idx == 2)
        return first-1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N >> _K;
    
    is_ok_v_value(_N, 0);
    _q.push({subin:_N,move_cnt:0});
    do
    {
        _gotcha_t here = _q.front(); _q.pop();
        _history.push_back(here.subin);
        if(here.move_cnt >= _ret.move_cnt)
        {
            continue;
        }
        if(here.subin == _K)
        {
            if(here.move_cnt < _ret.move_cnt)
            {
                _ret = here;
            }
            continue;
        }
        if(here.subin > _K)
        {
            // 수빈이가 동생보다 앞 질렀을 경우
            int n_subin = here.subin-1;
            if(is_ok_v_value(n_subin, here.move_cnt+1))
            {
                _q.push({subin:n_subin, move_cnt: here.move_cnt+1});
                if(_history[n_subin] == MAX)
                    _history[n_subin] = here.subin;
            }
        }
        else if(here.subin == 0)
        {
            // 수빈이가 0인경우
            int n_subin = here.subin + 1;
            if(is_ok_v_value(n_subin, here.move_cnt+1))
            {
                _q.push({subin:n_subin, move_cnt: here.move_cnt+1});
                if(_history[n_subin] == MAX)
                    _history[n_subin] = here.subin;
            }
        }
        else
        {
            // 아니면 그냥 완탐
            for(int c = 0; c < 3; c++)
            {
                int n_subin = calc(c, here.subin);
                if(is_ok_v_value(n_subin, here.move_cnt+1))
                {
                    _q.push({subin:n_subin, move_cnt: here.move_cnt+1});
                    if(_history[n_subin] == MAX)
                        _history[n_subin] = here.subin;
                }
            }
        }
    } while (!_q.empty());

    cout << _ret.move_cnt << "\n";
    for(int i = _K; i != _N && i != MAX; i = _history[i])
        _ret_hist.push_front( _history[i]);
    _ret_hist.push_back(_K);

    for(auto story: _ret_hist)
        cout << story << " ";
    return 0;
}