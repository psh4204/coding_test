#include <iostream>
#include <algorithm>

using namespace std;

void swap_c(int a[], int b[])
{
	int buff = *a;
	*a = *b;
	*b = buff;
}

int partition(int data[], int left, int right)
{
	int pivot = data[left];
	int i = left+1;
	int j = right;

	while(true)
	{
		while(data[i] <= pivot && i <= right)
			i++;
		while(data[j] > pivot && j > left)
			j--;
		if(i < j)
			swap_c(&data[i], &data[j]);
		else
			break;
	}
	swap_c(&data[left], &data[j]);
	return j; 
}

void quick_sort(int data[], int left, int right)
{
	if(left < right)
	{
		int p = partition(data, left, right);
		quick_sort(data, left, p-1);
		quick_sort(data, p+1, right);
	}
}

bool linear_search(int data[], int n, int target)
{
	for(int i=0; i < n; i++)
	{
		if(data[i] == target)
			return true;
	}
	return false;
}

bool binary_search(int data[], int n, int target)
{
	int lower = 0;
	int upper = n-1;
	
	if(data[lower] > target || data[upper] < target)
		return false;

	while(lower <= upper)
	{
		int mid = (lower + upper)/2;
		if(data[mid] == target)
			return true;
		else if(data[mid] <target)
			lower = mid + 1;
		else
			upper = mid -1;
	}
	return false;
}

int main(void)
{
    int data[] = {4,2,3,5,1};
    quick_sort(data,0, sizeof(data)/sizeof(int)-1);

    for(auto n: data)
        cout << n << ", ";
    cout << endl;

	cout<< "linear_search. 3: " << linear_search(data, sizeof(data)/sizeof(int), 3) << endl;
	cout<< "binary_search. 3: " << binary_search(data, sizeof(data)/sizeof(int), 3) << endl;

	cout<< sizeof(data)/sizeof(int) << ", " << sizeof(data) << ", " << sizeof(int) << ", " << sizeof(int*) ;

    return 0;
}