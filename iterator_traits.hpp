#pragma once
#include "iterator.hpp"
#include "vector.hpp"

//?https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
//?https://en.cppreference.com/w/cpp/iterator/iterator_traits
//?https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/
//?https://www.cplusplus.com/reference/iterator/iterator_traits/

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T> 
	class iterator_traits<T*>
	{
		public:
		typedef  ptrdiff_t difference_type;
		typedef  T value_type;
		typedef  T* pointer;
		typedef  T& reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};

	template <class T> 
	class iterator_traits<const T*>
	{
		public:
		typedef ptrdiff_t difference_type;
		typedef  T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};
}
