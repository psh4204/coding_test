#include <forward_list>
#include <iostream>

using namespace std;

int main(void)
{
	forward_list<int> l1{10, 20, 30, 40};
	l1.push_front(40);
	l1.push_front(50);

	for (auto &a : l1)
		cout << a << ",";
	cout << endl;

	int cnt = distance(l1.begin(), l1.end());
	cout << cnt << endl;

	l1.remove(40); // forward list 내에 40이라는 데이터 전부 삭제
	l1.remove_if([](int n)
				 { return n > 20; }); // 특정 조건(함수 혹은 람다식으로 표현)의 데이터는 전부 삭제
									  // 20보다 큰 값 삭제
	for (auto &a : l1)
		cout << a << ",";
	cout << endl;

	return 0;
}