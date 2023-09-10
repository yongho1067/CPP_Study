#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}

	v.clear();

	// 클리어를 하여도 capacity는 유지됨
	cout << v.size() << " " << v.capacity() << endl;

	
}

