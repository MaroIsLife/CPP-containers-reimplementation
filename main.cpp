#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include <memory>



// template<typename Input>
// void test(Input a,typename std::enable_if<!std::is_integral<Input>::value,
//                                   Input>::type* = nullptr)
// {
// 	std::cout << "input" << std::endl;
// 	std::cout << a[1] << std::endl;
// }


int main()
{

	ft::vector<int> ac(10,3);
	ft::vector<int> ab(13,3);

	
	// ft::vector<int> abc(10,7);

	// ft::vector<int> data(7);
	// ft::vector<int> abc(10,3);


	// data.swap(abc);
	// for(int i = 0; i < 10;i++)
	// 	data.push_back(i);
	// for(int i = 0; i < data.size();i++)
	// 	std::cout << data[i] << std::endl;
	// std::cout << "Size: " << data.size() << " Capacity: " << data.capacity() << std::endl;
}


//Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t