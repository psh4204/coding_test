/* https://www.acmicpc.net/problem/10814
나이순 정렬

나이는 오름차순, 나이가 같으면 먼저가입한 순서로 정렬하라.

입력
- 회원수N (1~100,000)
- 나이 이름 (N개만큼)

출력
- 나이오름차순, 순서오름차순 으로 회원정보 출력

풀이
- 나이, 순서, 이름 으로 데이터 받아온다.
- sort와 compare로 적절히 잘 출력해본다.
*/
#include <bits/stdc++.h>
using namespace std;
struct user_t
{
    int age;
    int idx;
    string name;
};
bool compare(const user_t& first, const user_t& second)
{
    if(first.age < second.age)
        return true;
    else if(first.age > second.age)
        return false;
    else
    {
        if(first.idx < second.idx)
            return true;
        else
            return false;
    }
}
int _N;

vector<user_t> _users;

int main()
{
    cin >> _N;
    for(int n_idx = 0; n_idx <_N; n_idx++)
    {
        user_t user;
        cin >> user.age >> user.name;
        user.idx = n_idx;
        _users.push_back(user);
    }
    sort(_users.begin(), _users.end(), compare);
    for(int n_idx = 0; n_idx < _N; n_idx++)
        cout << _users[n_idx].age << " " << _users[n_idx].name << "\n";
    return 0;
}