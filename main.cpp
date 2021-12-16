#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include <memory>


template <class T>
void do_stuff(T& t, typename ft::enable_if<!ft::is_integral<T>::value,T>::type *test = NULL) {
  std::cout << "do_stuff integral\n";
    // an implementation for integral types (int, char, unsigned, etc.)
}


void do_stuff(char a)
{
	std::cout << "do\n";
}

// template <class T>
// void do_stuff(T& t, typename std::enable_if<false,T>::type* = nullptr) {
// 		std::cout << "do_stuff class\n";
//     // an implementation for class types
// }

// template<typename Input>
// void test(Input a,typename std::enable_if<!std::is_integral<Input>::value,
//                                   Input>::type* = nullptr)
// {
// 	std::cout << "input" << std::endl;
// 	std::cout << a[1] << std::endl;
// }


int main()
{

	int ab = 1;
	do_stuff(ab);
	ft::vector<int> abc(10,3);

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