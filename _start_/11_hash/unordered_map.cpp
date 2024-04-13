#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
    // 데이터가 중복되는지 체크
    unordered_map<string, int> persons;
    persons.insert({"0AA", 200});
    persons.insert({"ABB", 4500});
    persons.insert({"BCC", 400});
    persons["CDD"] = 2300;
    persons["DEE"] =  600;
    persons["EFF"] = 5300;

    string man = "BCC";
    if(persons.find(man) != persons.end())
        cout << man << " finded!" << endl;
    else
        cout << man << " not finded!" << endl;

    for(auto [name, price]: persons)
        cout << name << ":" << price << endl;
    
    return 0;
}