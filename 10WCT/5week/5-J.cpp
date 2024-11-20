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

힌트듣고 풀이
- 우선순위큐 아님 (자주사용하는 것으로 우선순위 구하면 틀림)
- Optimal 알고리즘을 사용해야함. 
    - 페이징 최소화 알고리즘 중 하나
    - 가장 나중에 사용할 페이지를 교체하는 알고리즘. (https://rob-coding.tistory.com/37)
    - 와;;
- 유의사항: 다음에 사용안할 페이지는 곧장 교체해주면 됨.
*/
#include <bits/stdc++.h>
#define MAX_NUM     101
#define IS_TEST     false
using namespace std;
int _N, _K, _ret_cnt;
vector<bool> _is_plugged_list(MAX_NUM, false);
vector<int> _plug_list;
vector<int> _multitab;

int main()
{
    cin >> _N >> _K;
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        int device;
        cin >> device;
        _plug_list.push_back(device);
    }
    for(int k_cnt = 0; k_cnt < _K; k_cnt++)
    {
        int cur_device = _plug_list[k_cnt];
        if(IS_TEST) cout << "current_dev: "<< cur_device << " // ";
        // 1. 멀티탭 구멍이 남았다면, 넣고 본다.
        if(_multitab.size() < _N)
        {
            if(_is_plugged_list[cur_device])
            {
                if(IS_TEST) cout << "ALREADY\n";
                continue;
            }
            if(IS_TEST) cout << "PUSH\n";
            _multitab.push_back(cur_device);
            _is_plugged_list[cur_device] = true;
            continue;
        }

        // 2. 멀티탭 구멍이 꽉 차있다면, 
        // 2.1. 멀티탭에 같은 기기가 꽂힌지 확인
        if(_is_plugged_list[cur_device])
        {
            if(IS_TEST) cout << "ALREADY\n";
            continue;
        } 

        // 2.2. 플러그를 뽑아야하면, Optimal 알고리즘 사용(가장 나중에 사용할 플러그부터 교체)
        int last_plug_idx = 0;  // 가장 마지막에 바뀔 플러그의 순서.
        int pull_idx = 0;           // 멀티탭에서 뽑아야할 인덱스
        for(int mt_idx = 0; mt_idx < _N; mt_idx++)
        {
            int sub_last_idx = MAX_NUM;
            for(int plug_idx = k_cnt+1; plug_idx<_K; plug_idx++)
            {
                if(_plug_list[plug_idx] == _multitab[mt_idx])
                {
                    sub_last_idx = plug_idx;
                    break;
                }
            }
            // 현재 멀티탭의 기기가 두번다시 안꽂는 거라면 바로 교체
            if(sub_last_idx == MAX_NUM)
            {
                pull_idx = mt_idx;
                break;
            }
            // 아니라면 마지막 순서 업데이트
            if(last_plug_idx > sub_last_idx) continue;
            last_plug_idx = sub_last_idx;
            pull_idx = mt_idx;
        }
        if(IS_TEST) cout << " PULL: " << _multitab[pull_idx] << " PUSH: " << cur_device << "\n";
        _is_plugged_list[_multitab[pull_idx]] = false;
        _multitab[pull_idx] = cur_device;
        _is_plugged_list[cur_device] = true;
        _ret_cnt+=1;
    }
    cout << _ret_cnt;
    return 0;
}
