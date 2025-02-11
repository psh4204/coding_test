/* https://www.acmicpc.net/problem/30802
웰컴키트
- 웰컴키트(티셔츠 1장, 펜 1자루)
- 준비하기위한 주문을 할때 묶음으로 주문해야함
- 티셔츠는 6개 사이즈가있음. 같은 사이즈는 T장을 묶음으로만 주문가능
    - 티셔츠주문: T장묶음으로 만 
- 펜은 한종류로 P자루 묶음으로 주문하거나, 한자루씩 주문가능
    - 펜주문: 한묶음을 1자루, P자루 가능.

티는 '남아도 되게 줘도되는데', 신청한 사이즈대로 줘야함.
펜은 딱 참가자수 만큼 준비되어야함.

티는 T장씩 '최소 몇묶음(세트)'으로 주문해야하는지, 
펜은 P자루씩 '최대 몇묶음(세트)'으로 주문해야하는지 구하기 + '나머지는 한자루씩 몇자루'


[입력]
- 참가자수 N (1~1,000,000,000)
- 사이즈 별 신청자의 티셔츠 수 (6가지 차례로)
- 티셔츠 T장묶음 펜 P자루묶음 

[출력]
- 티셔츠를 최소 T장씩 몇묶음 주문해야하는가
- 펜을 최대 몇 묶음 씩 주문해야하는지와 몇자루씩 주문해야하는지

[풀이]
참가자수를 기준으로 주문을 시작한다.
- 티셔츠: 각 사이즈별로 남아도 되게 주문해도 되니까.
    - 각 사이즈 별 T장씩 주문횟수 카운트하면 정답.  
- 펜: 참가자수 / P. 참가주수 % P

말 진짜 어렵게 꼬아놨네..
*/

#include <bits/stdc++.h>
using namespace std;
long long _T, _P, _person, _retTN = 0;
vector<int> _tshirts(6,0);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _person;
    for(auto &tshirt : _tshirts)
        cin >> tshirt;
    cin >> _T >> _P;

    // 티셔츠 몇세트인지
    for(auto tshirt : _tshirts)
    {
        _retTN += tshirt/_T;
        _retTN += (tshirt % _T == 0) ? 0 : 1;
        // cout << (tshirt/_T) << " + " << (tshirt%_T) << "\n";
    }
    cout << _retTN << "\n";

    // 펜 몇세트, 몇자루인지
    cout << _person/_P << " " << _person%_P;

    return 0;
}