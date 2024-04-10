#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<string, int> fruits;
    fruits.insert({"apple", 1000});
    fruits.insert({"banana", 1000});
    fruits.insert({"orange", 1000});
    fruits["oragne"] = 4000;
    fruits["sleepy"] = 4000;
    fruits["bord"] = 4000;
    fruits.erase("orange");

    for(const auto p: fruits)
        cout<< p.first << " is " << p.second << "won." << endl;
    for(auto [name, price] : fruits)
        cout<< name << " is " << price << "won." << endl;

    return 0;
}