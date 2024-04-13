#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

class hash_set
{
private:
    int sz;
    std::vector<std::list<int>> data; // list 값을 

public:
    hash_set(int n): sz(n), data(sz){} // 초기화.
    int hash(int key){return key%sz;} // 해싱함수. 키값을 인덱스로 하는 벡터
    void insert(int value){data[hash(value)].push_back(value);} // 값을 해싱하여 해당 키에 맞게 벡터에 들어간다.
    bool find(int value)
    {
        auto& entries = data[hash(value)]; // 해당 값을 해싱하여 리스트를 가져온다.
        return std::find(entries.begin(), entries.end(), value) != entries.end(); // find함수로 리스트의 끝값(null)과 같지 않은지 체크
    } 
    void erase(int value)
    {
        auto& entries = data[hash(value)]; // 해싱하여 리스트 들고옴.
        auto it = std::find(entries.begin(), entries.end(), value); 
        if(it != entries.end()) // 리스트에 해당 이터레이터가 있는지 체크 후 삭제
            entries.erase(it); 
    } 

    void print()
    {
        int i = 0;
        for(auto m : data)
        {
            std::cout<< i++ << " : ";
            for(auto n : m)
                std::cout<< n << ", " ;
            std::cout<<endl;
        }
    }
};

int main(void)
{
    hash_set num_set(7);
    num_set.insert(10);
    num_set.insert(15);
    num_set.insert(20); // 6
    num_set.insert(55); // 6
    num_set.insert(100);

    num_set.print();

    cout<<"is 20 in num_set? "<<num_set.find(20)<<endl;

    return 0;
}