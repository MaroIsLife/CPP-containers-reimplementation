#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include "iterator.hpp"
#include "vector.hpp"

namespace ft
{
	template <class Iterator>
	class iterator_traits // Find out later why this needs to be implemented https://www.cplusplus.com/reference/iterator/iterator_traits/
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T> 
	class iterator_traits<T*>
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T> class iterator_traits<const T*>
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
}
#endif