#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>


class khobza_libghiti 
{
	public:
		int x;
		char c;
	khobza_libghiti()
	{
		x = 99;
	}

};

int main()
{	
	ft::vector<khobza_libghiti> abc;
	for(int i = 0; i < 10;i++)
		abc.push_back(khobza_libghiti());
	ft::vector<khobza_libghiti>::iterator it = abc.begin();
	ft::vector<khobza_libghiti>::iterator end = abc.end();
	ft::vector<khobza_libghiti> data(it,end);
	
	std::cout << abc[0].x << std::endl;
	// for(int i = 0; i < abc.size(); i++)
	// 	std::cout << abc[i] << std::endl;

	std::cout << "Size: " << data.size() << " Capacity: " << data.capacity() << std::endl;
}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t