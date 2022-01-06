#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
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
//! Implement istream iterator with insert range and assign range
int main()
{
	  
	// int arr[9] = {1,2,3,4,5,6,7,8,9};
	// std::vector<int> abc;
	// std::vector<int>::iterator it;
	// std::vector<int> data(arr, arr + 9);
	// std::vector<int>::reverse_iterator rit(data.rend());
	// for (;rit != data.rbegin(); rit--)
	// 	std::cout << *rit << std::endl;
	// ft::vector<int> data((std::istream_iterator<int>(std::cin)),std::istream_iterator<int>());
	//enter + ctrl D
	// for (int i = 1; i < 10;i++)
	// 	abc.push_back(i);
	// abc.insert(abc.begin() + 2, 40,3);
	// std::cout << *it << std::endl;
	// if (it == it2)
	// 	std::cout << "true" << std::endl;
	
	// data.insert(it,abc.begin(),abc.end());
	// it = it - 1;

	// for(size_t i = 0; i < data.size();i++)
	// 	std::cout << data[i] << std::endl;
	// std::cout << "Size: " << data.size() << " Capacity: " << data.capacity() << std::endl;
	// system("leaks a.out");

	 {
		ft::vector<int> a;
		a.push_back(5);
		// std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
		a.push_back(9);
		//std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
		a.push_back(8);
		a.push_back(1);
		//std::cout << " my BEFOR size org ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
		a.push_back(7);
		// a.push_back(10);
		// a.push_back(90);
		// a.reserve(a.size() + 1);
		// a.reserve(5);
		std::cout << " my v BEFOR size  ==>  " << a.size() << "    " << " BEFOR capasity ==> " << a.capacity() << std::endl;
		//std::cout << " BEFOR size my v ==>  " << a.size() << "    " << " BEFOR capasity my v ==> " << a.capacity() << std::endl;
		ft::vector<int>::iterator it =   a.begin();
		ft::vector<int>::iterator  rt =   a.erase(it  + 1, a.end() - 2);
		std::cout << "test return ==> " <<  *rt  << std::endl; 
		std::cout << " AFTER size my v  ==>  " << a.size() << "    " << " AFTER capasity my v==> " << a.capacity() << std::endl;
		for (it = a.begin(); it != a.end(); it++)
			std::cout << "element my v ==> " << *it << std::endl;
		std::cout << "test return ==> " <<  *rt  << std::endl; 
  }

}


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