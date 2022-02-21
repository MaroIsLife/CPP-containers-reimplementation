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

//! Fix Assign and Insert with Enable_if (Input Iterator)
//! Implement istream iterator with insert range and assign range
int main()
{

	//! Fix resize
	




	// std::vector<int> v1(arr,arr+9);
	// std::vector<int>::reverse_iterator it(v1.rend());

	// std::cout << *it << std::endl;

	std::string arr[9] = {"1","2","3","4","5","6","7","8","9"};


	std::string ft_sit1;
	ft::vector<std::string> ft_v1(10, "string2");
	ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
	ft_valid_it = ft_v1.begin();
	ft_valid_eit = ft_v1.end();

	// ft_v1.resize(25);
	ft_v1.pop_back();

	
	std::cout << ft_v1.capacity() << std::endl;
	std::cout << ft_v1.size() << std::endl;
	// for(int i = 0; i < 10; i++)
	// {
	// 	std::cout << ft_v1[i] << std::endl;
	// }
	// ft_v1.reserve(51);
	// ft_v1.assign(100, "string1");	
	// for (; ft_valid_it != ft_valid_eit; ft_valid_it++)
	// 		ft_sit1 += *ft_valid_it;



	//ft::vector<int> data((std::istream_iterator<int>(std::cin)),std::istream_iterator<int>());
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

//* Destroy vs Deallocate
//https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator