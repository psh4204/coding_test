/*https://www.acmicpc.net/problem/17071
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

Try5. hint 파악 후 다시 풂
- 레벨탐색에 대한 재이해: 최단레벨하나하나 차근차근 접근하는 알고리즘
- 플루드 필 기법: 해당하는 부분만 탐색하는 기법.(해당 레벨 만 탐색할 수 있음)

- 문제hint
    - visited가 방대해지는 문제가있음
    - 이건 미리 언니가 동생을 앞질렀을때, 그자리에서 가만히 왔다갔다 하고있는경우를 잡으면됨.
*/
#include <bits/stdc++.h>
#define MAX 500001
using namespace std;
int _SB, _SISTER;
vector<vector<int>> _v(2, vector<int>(MAX));    // visited val에서 홀-짝 까지 체크
queue<int> _q;
int _secs = 0;

bool insert_v_val(int val, int secs)
{
    if(val >= 0 && val < MAX && _v[secs%2][val] == 0)
    {
        _v[secs%2][val] = 1;
        return true;
    }
    return false;
}

int calc(int c_idx, int first)
{
    if(c_idx == 0)
    {
        return first - 1;
    }
    else if(c_idx == 1)
    {
        return first + 1;
    }
    else if(c_idx == 2)
    {
        return first * 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _SB >> _SISTER;

    if(_SB == _SISTER)
    {
        cout << 0;
        return 0;
    }

    _q.push(_SB);
    insert_v_val(_SB, _secs);
    do
    {
        int q_size = _q.size();
        _SISTER += _secs;
        // flood fill
        for(int s_idx = 0; s_idx < q_size; s_idx++)
        {
            int here = _q.front(); _q.pop();
//            cout << "subin: " << here << ", sister: " << _SISTER << ", secs: " << _secs << "\n"
            if(_SISTER > (MAX-1))
            {
                cout << -1;
                return 0;
            }
            if(_SISTER == here || _v[_secs%2][_SISTER]) // check walks.. 미리간거까지 포함
            {
                cout << _secs;
                return 0;
            }
            for(int c_idx = 0; c_idx < 3; c_idx++)
            {
                int n_subin = calc(c_idx, here);
                if(insert_v_val(n_subin,_secs+1))
                    _q.push(n_subin);
            }
        }
        _secs++;
    } while (!_q.empty());

    cout << -1;
    return 0;
}