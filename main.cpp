#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{	

	
	std::vector<int> abc(10);
	std::vector<int>::iterator it;
	// for(int i = 0; i < 10; i++)
	// 	abc.push_back(i);
	it = abc.begin();
	it++;
	it++;
	abc.insert(it,3,99);
	for(int i = 0; i < 10; i++)
		std::cout << abc[i] << std::endl;
	std::cout << "Size: " << abc.size() << " Capacity: " << abc.capacity() << std::endl;



}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t