/*https://www.acmicpc.net/problem/2852
NBA농구

골이 들어갈때마다 들어간시간과 팀을 적는 동혁이가있다.
48분동안 각팀이 몇분동안 이기고있는지 출력하는 프로그램 만들기.

Input
- 들어간 횟수 N (1~100)
- N줄의 득점정보 
    - 팀1,2 시간MM:SS (00:00 포맷. 분 00~47, 초 00~59)

Output
- 1팀이 이기고있던 시간
- 2팀이 이고고있던 시간

Try1.
- struct 만들어서 해결하자

Try2.
- 구현이 복잡하네.. 머리아프다
- 동점이 왔다갔다할때가 제일 머리쓰기 힘들었음.
*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;
typedef struct team_data_
{
    int score = 0;
    pair<int, int> winning_time = {0,0};
}team_d_t;
vector<team_d_t> _teams(2, {score:0, winning_time:{0,0}});
pair<int, int> _pre_time = {-1,-1};

pair<int, int> minus_time(pair<int,int> v_1, pair<int,int> v_2)
{
    int first = v_1.first - v_2.first;
    int second = v_1.second - v_2.second;
    if(second < 0)
    {
        first--;
        second += 60;
    }
    return {first, second};
}

pair<int, int> plus_time(pair<int,int> v_1, pair<int,int> v_2)
{
    int first = v_1.first + v_2.first;
    int second = v_1.second + v_2.second;
    if(second >= 60)
    {
        first++;
        second -= 60;
    }
    return {first, second};
}

pair<int, int> get_time(string str_time)
{  
    int min = stoi(str_time.substr(0,2));
    int sec = stoi(str_time.substr(3,5));
    return {min, sec};
}

void process_time_score(int team_id, pair<int,int> now_time)
{
    if(_teams[0].score != _teams[1].score)
    {
        // 이전 시간과 현재 시간을 가지고 winning time 계산
        int w_team = _teams[0].score > _teams[1].score ? 0 : 1;
        if(_pre_time.first != -1 || _pre_time.second !=-1)
        {
            _teams[w_team].winning_time = 
                plus_time(_teams[w_team].winning_time, 
                            minus_time(now_time, _pre_time));
        }
        _pre_time = now_time;
    }
    else if(_pre_time.first != -1 || _pre_time.second !=-1) // 동점이 됐을때. 이전 goal팀의 시간계산
    {
        int id = team_id == 1? 0: 1;
        _teams[id].winning_time = plus_time(_teams[id].winning_time, minus_time(now_time, _pre_time));
        _pre_time = {-1,-1}; // 동점이 됐을 때 초기화.
    }
}

int main()
{
    cin >> _N;
    int team_id = 0;
    string str_time;
    for(int goal_cnt = 0; goal_cnt < _N; goal_cnt++)
    {
        pair<int, int> now_time = {0,0};
        cin >> team_id >> str_time;
        now_time = get_time(str_time);
        _teams[team_id-1].score++;
        process_time_score(team_id-1, now_time);
    }
    // 48:00 처리
    process_time_score(team_id-1,{48,00});
    for(auto team : _teams)
    {
        printf("%02d:%02d\n",team.winning_time.first,team.winning_time.second);
    }

    return 0;
}