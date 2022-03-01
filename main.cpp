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


		std::string str, ft_str;
		
		ft::vector<std::string>::size_type s, ft_s;
		ft::vector<std::string>::size_type c, ft_c;
		ft::vector<std::string>::iterator ft_it;
		std::vector<std::string>::iterator it;
		bool cond;





		std::vector<std::string> v(20, "string");
			ft::vector<std::string> ft_v(20, "string");

			v.insert(v.begin() + 10, 15, "hello");
			ft_v.insert(ft_v.begin() + 10, 15, "hello");

			str.clear();
			ft_str.clear();
			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();
			for (size_t i = 0; i < v.size(); ++i)
				str += v[i];
			for (size_t i = 0; i < ft_v.size(); ++i)
				ft_str += ft_v[i];
			cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));

		std::cout << "after insert valid_it: " << &v[0] << std::endl;
		std::cout << "my begin: " << &(*ft_v.begin()) << std::endl;
		std::cout << "My Size: " << ft_s << std::endl;
		std::cout << "Their size: " << s << std::endl;
		std::cout << "My capacity: " << ft_c << std::endl;
		std::cout << "Their capacity: " << c << std::endl;
		std::cout << "My string: " << ft_str << std::endl;
		std::cout << "Their string: " << str << std::endl;
		// std::cout << "My iterator: " << *ft_it << std::endl;
		// std::cout << "Their iterator: " << *it << std::endl;
		
		cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));		
		std::cout << "cond: " << cond << std::endl;
		// if ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())))
		// 	std::cout << "true" << std::endl;
		// else
		// 	std::cout << "false" << std::endl;

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
