/* https://www.acmicpc.net/problem/14497
주난의 난

주난이는 미쳐날뛰기 시작했다. 쿵쿵
주난이가 날뛸때마다 파동이 일어나는데, 4방향으로 쭉 퍼진다.
사람과 같은 장애물을 한번쓰러뜨릴때까지 쭉 퍼진다.
초콜릿을 훔친 범인(X)가 쓰러질때까지 몇번의 점프가 이루어져야하는가?

Input
- N M (1~300)
- 주난위치(x1 y1) 범인위치(x2 y2)
- 지도

Output
- 최소점프횟수

Try1
- 최단시간 = BFS
- 최대 300x300 짜리 면 단순하게 짜도 상관없을듯
- 주난의 주위의 0친구들을 어디 저장해둬야함
- 범인위치까지 닿을때까지 단순하게 BFS 해보자
*/
#include <bits/stdc++.h>
using namespace std;
int _Y, _X, _cnts;
int _dy[4] = {-1, 0, 1, 0};
int _dx[4] = {0, 1, 0, -1};
vector<vector<int>> _room;
pair<int,int> _bg;  // badguy
pair<int,int> _jn;  // 주난
vector<pair<int,int>> _zeros;   // 주난 근처 0값들
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _Y >> _X;
    _room.resize(_Y, vector<int>(_X));
    for(int y = 0; y < _Y; y++)
    {
        string input;
        getline(cin, input);
        for(int x = 0; x < _X; x++)
        {
            char in_ch = input[x];
            cin >> in_ch;
            if(in_ch == '0')
                _room[y][x] = 0;
            else if(in_ch == '1')
                _room[y][x] = 1;
            else if(in_ch == '#')
            {
                _room[y][x] = 2;
                _bg = {y,x};
            }
            else if(in_ch == '*')
            {
                _room[y][x] = 3;
                _jn = {y,x};
            }
        }
    }
    return 0;
}