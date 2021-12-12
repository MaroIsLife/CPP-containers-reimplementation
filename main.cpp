#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{	

	ft::vector<int> oneten;
		for(int i =1; i <= 3;i++)
			oneten.push_back(i);
	ft::vector<int> abc(10);
	ft::vector<int>::iterator it;
	// for(int i = 0; i < 10; i++)
	// 	abc.push_back(i);
	it = abc.begin();
	it++;
	it++;
	abc.insert(it,oneten.begin(),oneten.end());
	for(int i = 0; i < 20; i++)
		std::cout << abc[i] << std::endl;
	std::cout << "Size: " << abc.size() << " Capacity: " << abc.capacity() << std::endl;



}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t