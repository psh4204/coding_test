#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    set<int> odds {1, 7, 3, 5, 11}; // 자동으로 오름차순 정렬됨
    set<int, greater<>> evens {6,12,8,4}; //자동으로 내림차순 정렬됨
    evens.insert(15);
    evens.insert(8);
    
    // 4가 set에 없다면 set.end 리턴된다.
    if(evens.find(4)!= evens.end()) 
        cout << "4 is even!!" << endl;
    else
        cout << "4 is not even!!" << endl;

    for(auto o : odds)
        cout<< o << ", ";
    cout<<endl;

    for(auto e : evens)
        cout<< e << ", ";
    cout<<endl;

    //
    // 복합적인 값을 set에 저장해보자
    // pair 클래스는 특정 타입 두개를 묶어 사용할 때 사용하는 클래스
    //
    // set<pair<string,int>> managers = {{"Soso", 22},{"AaAa", 12},{"HaHa", 58},{"UuUu", 42},};
    using psi = pair<string,int>;
    set<psi> managers = {{"Soso", 22},{"AaAa", 12},{"HaHa", 58},{"UuUu", 42},};
    managers.insert(make_pair("George",35));

    psi a = {"Soso", 22};
    if(managers.find(a)!= managers.end()) 
        cout << "Soso is manager!!" << endl;
    else
        cout << "Soso is not manager!!" << endl;
    return 0;
}