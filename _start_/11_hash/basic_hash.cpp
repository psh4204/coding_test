#include <iostream>
#include <vector>

using namespace std;

class hash_set
{
private:
    int sz;
    std::vector<int> data;

public:
    hash_set(int n): sz(n), data(sz,-1){} // 초기화. 사이즈를 받은 후 그만큼 -1로 채운다.
    int hash(int key){return key%sz;} // 해싱함수. 키값을 인덱스로 하는 벡터
    void insert(int value){data[hash(value)] = value;} // 값을 해싱하여 해당 키에 맞게 벡터에 들어간다.
    bool find(int value){return data[hash(value)] == value;} // 해당 값을 해싱하여 값이 있는지 확인
    void erase(int value){data[hash(value)]= -1;} // 해당 값을 -1로 채운다.

    void print()
    {
        for(auto n : data)
            std::cout << n << ", ";
        std::cout<<endl;
    }
};

int main(void)
{
    hash_set num_set(7);
    num_set.insert(10);
    num_set.insert(15);
    num_set.insert(20); // 6
    num_set.insert(55); // 6. 마지막에 들어간 값이 덮어씌워지네..
    num_set.insert(100);

    num_set.print();

    return 0;
}