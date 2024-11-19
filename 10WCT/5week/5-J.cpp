/* 멀티탭 스케줄링
https://www.acmicpc.net/problem/1700

멀티탭플러그를 최소 횟수로 뽑는방법을 고안한다.

입력
- N K(구멍개수 1~100, 사용횟수 1~100)
- 전기용품이름넘버로된 사용순서
출력
- 플러그를 빼는 최소 횟수

풀이
- 사용순서를 맞추면서, 최소횟수로 플러그를 뽑아써야함.
- 우선순위 큐를 부분적으로 응용해야할듯
    - 멀티탭을 우선순위 큐로 두자 (사용적은 순으로 top에 두기)
- 그렇게 pop되는 횟수 카운트 하면 풀리는 문제

힌트
- 우선순위큐 아님
- Optimal 알고리즘을 사용해야함. (가장 먼 미래에 사용되는 애를 바꾸면 안됨)
    - 와;;
    - TODO: 새로짜자!!! (새 알고리즘 적용해야하니까.. ㅠㅠ)
*/
#include <bits/stdc++.h>
#define MAX_NUM 101
#define IS_TEST true
using namespace std;
int _N, _K, _ret_cnt;
vector<int> _devices(MAX_NUM);
vector<bool> _is_push_lst(false);
queue<int> _history;
vector<int> _multitab;

int main()
{
    cin >> _N >> _K;
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        int device;
        cin >> device;
        _history.push(device);
        _devices[device]+=1;
    }
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        if(IS_TEST) cout << "current_dev: "<< _history.front() << " // ";
        // 1. 멀티탭 구멍이 남으면,
        if(_multitab.size() < _N)
        {
            // 1.1. 멀티탭이 비었거나, 기기를 안꼽았다면 꼽는다
            if(_multitab.empty() || !_is_push_lst[_history.front()])
            {
                if(IS_TEST) cout << "INSERT\n";
                _multitab.push({_devices[_history.front()], _history.front()});
                _is_push_lst[_history.front()] = true;
            }
            else
                if(IS_TEST) cout << "PAUSE\n";
            _history.pop();
            continue;
        }
        // 2. 멀티탭 구멍이 꽉찼는데, 현재 기기가 멀티탭에 꼽혀있다면 그대로 둔다.
        else if(_is_push_lst[_history.front()])
        {
            if(IS_TEST) cout << "PAUSE\n";
            _history.pop();
            continue;
        }
        // 3. 새로운 기기를 꼽기위해, 멀티탭에서 다른 기기를 뽑고, 새롭게 꼽는다.
        if(IS_TEST) cout << "POP: "<< _multitab.top().second << " // INSERT: " << _history.front() << "\n";
        _is_push_lst[_multitab.top().second] = false;
        _multitab.pop();
        _multitab.push({_devices[_history.front()], _history.front()});
        _is_push_lst[_history.front()] = true;
        _history.pop();
        _ret_cnt++;
    }
    cout << _ret_cnt;
    return 0;
}