#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{	

	
	ft::vector<int> abc2;
	for(int i = 0; i < 6; i++)
		abc2.push_back(i);

	ft::vector<int> abc(abc2.begin(),abc2.end());
	ft::vector<int>::iterator it;

	it = abc.begin();

	for (int i = 0 ; it != abc.end() ; it++)
	{
		std::cout << "it: " << *it << std::endl;
	}



}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t