#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>




int main()
{
	// std::vector<int> abc(10,3);
	ft::vector<int> data(7);
	ft::vector<int> abc(10,3);


	data.swap(abc);
	// for(int i = 0; i < 10;i++)
	// 	data.push_back(i);
	// for(int i = 0; i < data.size();i++)
	// 	std::cout << data[i] << std::endl;
	std::cout << "Size: " << data.size() << " Capacity: " << data.capacity() << std::endl;
}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t