#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include <memory>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#include <map>

//! Implement istream iterator with insert range and assign range
int main()
{

    std::map<std::string, int> m;
	std::map<std::string, int>::iterator it;

	// for(int i = 0; i < 10; i++)
	// {
	// 	m[std::to_string(i)] = i;
	// }

	std::cout << m["5"] << std::endl;
	// system("leaks a.out");
}

//! step one: implement BST (right child is greater than parentand left child is less than parent right child)


//*Iterator Operators
//https://docs.microsostd.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//*ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t

//*Red Black Tree
//http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap14.htm

//*AVL trees
//https://www.youtube.com/watch?v=-9sHvAnLN_w

//*Const Correctness 
//https://isocpp.org/wiki/faq/const-correctness#overview-const

//* Istream iterator
//https://www.cplusplus.com/reference/iterator/istream_iterator/

//* Destroy vs Deallocate
//https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator
