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

class A
{
	public:
	operator bool()
	{
		std::cout << "BOOOOL" << std::endl;
		return (true);
	}
};

//! Fix Assign and Insert with Enable_if (Input Iterator)
int main()
{  
	ft::vector<int> abc;
	ft::vector<int>::iterator it;
	
	for (int i = 0; i < 10;i++)
		abc.push_back(i);
	it = abc.begin();
	std::cout << distance(it, it + 3) << std::endl;	
	// it = it + 3;
	// data.insert(it,abc.begin(),abc.end());
	// it = it - 1;

	// for(int i = 0; i < data.size();i++)
	// 	std::cout << data[i] << std::endl;
	std::cout << "Size: " << abc.size() << " Capacity: " << abc.capacity() << std::endl;
	// system("leaks a.out");

}


//*Iterator Operators
//https://docs.microsoft.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//*ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t

//*Red Black Tree
//http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap14.htm

//*AVL trees
//https://www.youtube.com/watch?v=-9sHvAnLN_w

//*Const Correctness 
//https://isocpp.org/wiki/faq/const-correctness#overview-const