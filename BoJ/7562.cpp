/* https://www.acmicpc.net/problem/7562
나이트이동

체스판에 나이트가 원하는위치에 가려면 최소몇번을 움직이여야할까?

입력
- TC
- 채스판_변의_길이
- 나이트_위치
- 이동_위치
- (반복..)
출력
- 각TC마다 최소이동 리스트

풀이
- 최소움직임 = BFS (Q)
- visited는 없이 그냥 채스판에다가 숫자입력하는거로 해서 중복경로 최소화하자
- 최종target칸에는 -1 표시 후 -1찾는 bfs 만들자.

1
4
0 0
3 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct kn{
    int y;
    int x;
    int fp; // foot_print
}knight_t;
int _tc;
int _dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int _dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

inline int get_min_load(knight_t kn, vector<vector<int>>& board)
{
    int ret = 0;
    queue<knight_t> q;
    // Check target
    if(board[kn.y][kn.x] == -1)
        return 0;
    kn.fp = 0;
    board[kn.y][kn.x] = kn.fp;
    q.push(kn);
    do
    {
        knight_t here = q.front();
        q.pop();
        for(int n_idx = 0; n_idx < 8; n_idx++)
        {
            knight_t n_kn;
            n_kn.y = _dy[n_idx] + here.y;
            n_kn.x = _dx[n_idx] + here.x;
            n_kn.fp = here.fp + 1;
            if(n_kn.y >= board.size() || n_kn.x >= board.size() ||
                n_kn.y < 0 || n_kn.x < 0 || (board[n_kn.y][n_kn.x] > 0 && board[n_kn.y][n_kn.x] <= n_kn.fp))
                continue;
            // Check target
            if(board[n_kn.y][n_kn.x] == -1)
            {
                ret = n_kn.fp;
                break;
            }
            board[n_kn.y][n_kn.x] = n_kn.fp;
            q.push(n_kn);
        }
    } while (q.size() && ret == 0);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _tc;
    for(int tc_cnt = 0; tc_cnt < _tc ; tc_cnt++)
    {
        int side;
        knight_t knight;
        knight_t target;
        cin >> side;
        cin >> knight.y >> knight.x;
        cin >> target.y >> target.x;
        vector<vector<int>> board(side,vector<int>(side,0));
        board[target.y][target.x] = -1;
        cout << get_min_load(knight, board) << "\n";
    }
    return 0;
}