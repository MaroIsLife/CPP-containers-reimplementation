#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{	

	// int data[5] = {1, 3, 4, 5,6};
	// int data2[5] = {3, 18, 4, 5,6};
	ft::vector<int> abc(5,1);
	std::vector<int> abc2(5,1);
	ft::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator it3;

	it = abc.begin();
	// abc2[1] = 99;
	it = it + 1;	
	std::cout << *it << std::endl;
	// it = abc.begin();
	// abc.push_back(10);
	// abc.push_back(99);

	// it = abc.begin();
	// // it++;
	// for(; it != abc.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// std::cout << "Size: " << abc.size() << std::endl;
	// std::cout << "Capacity: " << abc.capacity() << std::endl;

}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t