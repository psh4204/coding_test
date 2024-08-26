/* https://www.acmicpc.net/problem/12869
뮤탈리스크

뮤탈리스크1개, SCV N개.
SCV: 체력있음
뮤탈리스크는 한번에 3개유닛을 때릴수있음(-9, -3, -1)
한유닛에 연속세대 불가능
모든 SCV를 죽이기위한 최소 공격횟수 구하기

Input
- N (SCV개수 1~3)
- 각 SCV 체력들 (1~60)
Output
- SCV를 죽이기위한 최소 공격횟수

Try1
- sort해서 차례로 줘패면 되는거아님?  ... 뭐야.. 틀렸대

Try2
- 힌트봄 그냥. 너무 거지같은문제네. BFS? 왜지?
- 일단 SCV의 위치이동을 못하게 막은듯 하다. 적팀이니까..? (스타크래프트를 하는것처럼 해야하나봐..)
- 뮤탈 공격의 경우의 수를 가지고 최단거리를 구해야한다...라.. 
- 내일하자그냥

Try3
- BFS로 최단기간 도달되는 데이터를 뽑아보자.
    - visited배열: 각 hp와 도달카운트를 담는 3차원 visited 배열을 사용한다.
    - 큐: 2차원배열에서는 큐에 pair를 썼지만, 3차원 배열용으로는 튜플..대신 struct를 써본다.
        - 큐는 뭐다? 유사 멀티쓰레드다...
        - {a,b,c} , {a,b,c} ...
        - 튜플보다는 구조체가 가독성이나 확장성에 좋아서 사용한다.

*/
#include <bits/stdc++.h>
using namespace std;
int _N, _ret;
int _attack[6][3] = 
{
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,9,3},
    {1,3,9},
};
int _hp_cnt[61][61][61];  // 각 SCV의 체력마다 도달카운트를 기입한다.(hp가체를 인덱스로 사용하니까 배열크기+1)
struct scv_t
{
    int a; int b; int c;
};  // 3차원 pair인 튜플대신 구조체사용.
vector<int> _scvs= {0,0,0};

void get_attack_cnt();

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> _N;
    for(int in_cnt = 0; in_cnt < _N; in_cnt++)
    {
        int input = 0;
        cin >> input;
        _scvs[in_cnt] = input;
    }
    get_attack_cnt();

    cout << _hp_cnt[0][0][0];
    return 0;
}

void get_attack_cnt()
{
    queue<scv_t> q;
    q.push({_scvs[0],_scvs[1],_scvs[2]});
    while(!q.empty())
    {
        scv_t pre = q.front();
        q.pop();
        if(_hp_cnt[0][0][0] != 0) return;
        for(int a_idx = 0; a_idx < 6; a_idx++)
        {
            int na = pre.a-_attack[a_idx][0] < 0? 0: pre.a-_attack[a_idx][0];
            int nb = pre.b-_attack[a_idx][1] < 0? 0: pre.b-_attack[a_idx][1];
            int nc = pre.c-_attack[a_idx][2] < 0? 0: pre.c-_attack[a_idx][2];
            if(_hp_cnt[na][nb][nc] == 0 || _hp_cnt[na][nb][nc] > _hp_cnt[pre.a][pre.b][pre.c] + 1)
            {
                q.push({na,nb,nc});
                _hp_cnt[na][nb][nc] = _hp_cnt[pre.a][pre.b][pre.c] + 1;
            }
        }
    }
}
