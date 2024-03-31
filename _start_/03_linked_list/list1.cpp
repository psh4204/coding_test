#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	list<int> l1;
	l1.push_back(11);
	l1.push_back(20);

	list<int> l2{10, 20, 30, 40};

	for (auto &a : l2)
	{
		cout << a << ", ";
	}
	cout << endl;

	l2.splice(l2.end(), l1); // 이어 붙이기. l2.end()에 l1을 이어붙여라. 10,20,30,40,11,22,
							 // l1은 delete 된다.
	for (auto &a : l2)
	{
		cout << a << ", ";
	}
	cout << endl;

	l2.sort(); // 오름차순 sort.
	for (auto &a : l2)
	{
		cout << a << ", ";
	}
	cout << endl;

	l2.unique(); // 중복값 제거
	for (auto &a : l2)
	{
		cout << a << ", ";
	}
	cout << endl;

	return 0;
}