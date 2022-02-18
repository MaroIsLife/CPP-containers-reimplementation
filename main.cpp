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


std::string& asmae(std::string &a)
{
	return a;
}


//! Fix Assign and Insert with Enable_if (Input Iterator)
//! Implement istream iterator with insert range and assign range
int main()
{




	// std::vector<int> v1(arr,arr+9);
	// std::vector<int>::reverse_iterator it(v1.rend());

	// std::cout << *it << std::endl;

	std::string arr[9] = {"1","2","3","4","5","6","7","8","9"};
	std::vector<int> v(3, 4);
	ft::vector<int> my_v(3, 4);
	std::vector<int>::reverse_iterator rit(v.end()), rit_1(v.end() - 1);
    ft::vector<int>::reverse_iterator my_rit(my_v.end()), my_rit1(my_v.end() - 1);
	

	std::cout << (my_rit - my_rit1) << std::endl;
	std::cout << (rit - rit_1) << std::endl;
	if (((my_rit - my_rit1) == (rit - rit_1)) && ((my_rit1 - my_rit) == (rit_1 - rit)))
		std::cout << "same" << std::endl;
	else
		std::cout << "not same" << std::endl;

	// if((my_rit[0] = 5) == 5)
	// 	std::cout << "5 = true" << std::endl;
	std::cout << *my_rit << std::endl;
	std::cout << *my_rit1 << std::endl;
	std::cout << "my_rit: " << &(*my_rit) << std::endl;
	std::cout << "my_rit: " << &(*my_rit1) << std::endl;
	std::cout << *rit << std::endl;
	std::cout << *rit_1 << std::endl;
	std::cout << "rit: " << &(*rit) << std::endl;
	std::cout << "rit_: " << &(*rit_1) << std::endl;
	

    // if ((&(*(2 + my_rit)) == &(*(1 + my_rit1))) && (&(*(2 + rit)) == &(*(1 + rit_1))))
	// 	std::cout << "True" << std::endl;
	// ft::vector<std::string> ft_v1(arr, arr + 9);

 
	// std::vector<std::string> v(arr, arr + 9);

        // ft::vector<std::string> ft_v1(3, "string2");
				
		//    std::cout << *rit << std::endl;//ft_res += *rit;
        // for (ft::vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit) // fill c_ft_res from const ft_v1
        //     c_ft_res += *rit;
	// std::cout << c_ft_res << std::endl;
	// ft::reverse_iterator<std::vector<int>::iterator> my_rit(v.end());

	// my_rit++;
	// std::cout << *my_rit << std::endl;
	// if (*my_rit == *(v.end() - 1))
	// 	;
	// std::vector<int> abc;
	// std::vector<int>::iterator it;
	// while (it != data.end())
	// 	std::cout << *(it++) << std::endl;
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