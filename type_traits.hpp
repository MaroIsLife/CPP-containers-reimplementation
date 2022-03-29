#pragma once
#include <iostream>
#include <type_traits>
#include "vector.hpp"
#include "iterator.hpp"


//!Type Traits
//?https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp

namespace ft
{

	//!Enable if
	//*SFINAE = Substitution failure is not an error 
	//?https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
	//?https://riptutorial.com/cplusplus/example/3777/enable-if
	template<bool Cond, class T = void> 
	struct enable_if
	{
		// typedef T type;

	};
	template<class T> 
	struct enable_if<true, T> 
	{
		typedef T type; 

	};

	//?https://www.cplusplus.com/reference/type_traits/integral_constant/
	
	template <typename T, T v>
	struct integral_constant
	{
		const static T value = v;
		typedef T value_type;
		typedef integral_constant type;
		integral_constant()
		{
			return (v);
		}
	};
	
	//?https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral
	template <typename T> 
	struct is_integral : public integral_constant<bool,false>
	{};

	template <> 
	struct is_integral<char> : public integral_constant<bool,true>
	{};

	template <> 
	struct is_integral<char16_t> : public integral_constant<bool,true>
	{};
	
	template <> 
	struct is_integral<char32_t> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<wchar_t> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<signed char> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<long int> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<long long int> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<unsigned char> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<unsigned short int> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<unsigned int> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<unsigned long int> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<unsigned long long int> : public integral_constant<bool,true>
	{};
	template <> 
	struct is_integral<int> : public integral_constant<bool,true>
	{};
}
