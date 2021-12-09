#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{	

	
	ft::vector<int> abc(5);

	for(int i = 0;i < abc.size();i++)
		std::cout << abc[i] << std::endl;
	std::cout << "Size: " << abc.size() << " Capacity: " << abc.capacity() << std::endl;
	std::cout << "-------------" << std::endl;
	abc.resize(5);
	for(int i = 0;i < abc.size();i++)
		std::cout << abc[i] << std::endl;
	std::cout << "Size: " << abc.size() << " Capacity: " << abc.capacity() << std::endl;


  // set some content in the vector:




}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t