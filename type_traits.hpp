#pragma once
#include <iostream>
#include <type_traits>
#include "vector.hpp"
#include "iterator.hpp"

//Enable if
//SFINAE = Substitution failure is not an error 
//https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
//https://riptutorial.com/cplusplus/example/3777/enable-if

//Type Traits
//https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp

namespace ft
{


	template<bool Cond, class T = void> 
	struct enable_if 
	{

	};
	template<class T> 
	struct enable_if<true, T> 
	{
		typedef T type; 

	};
	
}
