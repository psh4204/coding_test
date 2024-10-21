/* https://www.acmicpc.net/problem/5052
전화번호 목록

번호 목록이 일관성 있는지 체크하시오.
전화번호 목록 일관성 유지 = 번호가 다른번호에 접두어이면 안됨 (911 , 91125 <- NO, 97525 <-YES)

입력
- 테스트케이스 수 t (1~50)
- 전화번호 수 n (1~10000)
- 전화번호리스트 (번호길이 1~10, 동일한 번호 없음)

출력
- 일관성 = YES
- 아니면 = NO

풀이
- t, n0, 리스트0, n1, 리스트1 ... 받을 수 있음
- 어떠한 번호가 접두사로 들어가면 안된다고 하니까, String으로 받은 후에 sort해서 나열.
- 앞의 숫자와 뒤의숫자 서로 비교 후 같다면 틀림, 다르면 continue.
*/
#include <bits/stdc++.h>
using namespace std;
int _t, _n;

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    cin >> _t;
    for(int t_idx = 0; t_idx <_t; t_idx++)
    {
        vector<string> str_nums;
        cin >> _n;
        for(int n_idx = 0; n_idx < _n; n_idx++)
        {
            string str_num;
            cin >> str_num;
            str_nums.push_back(str_num);
        }
        // sort
        sort(str_nums.begin(), str_nums.end());

        // // [[TEST]]
        // for(auto n: str_nums)
        //     cout << n << " ";
        // cout << "\n";
        if(str_nums.size() == 1)
        {
            cout << "YES\n";
            continue;
        }
        bool is_yes = true;
        for(int n_idx = 0; n_idx < _n-1; n_idx++)
        {
            if(str_nums[n_idx][0] != str_nums[n_idx+1][0]) continue;
            if(str_nums[n_idx].length() == str_nums[n_idx+1].length()) continue;
            if(str_nums[n_idx].length() > str_nums[n_idx+1].length()) continue;
            // cout << str_nums[n_idx+1].substr(0, str_nums[n_idx].length()) << "TESTEST\n";
            if(str_nums[n_idx] == str_nums[n_idx+1].substr(0, str_nums[n_idx].length()))
            {
                is_yes = false;
                break;
            }
        }
        if(is_yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}