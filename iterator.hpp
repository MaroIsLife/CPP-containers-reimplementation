#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "vector.hpp"

namespace ft
{
	
	struct random_access_iterator_tag {};


	template <class Iterator>
	class iterator_traits // Find out later why this needs to be implemented https://www.cplusplus.com/reference/iterator/iterator_traits/
	{
		// typedef typename ft::base_iterator::difference_type difference_type;
		// typedef typename ft::base_iterator::value_type value_type;
		// typedef typename ft::base_iterator::pointer pointer;
		// typedef typename ft::base_iterator::reference reference;
		// typedef typename ft::base_iterator::iterator_category iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct base_iterator 
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
	
	template <typename T>
	class myiterator : public ft::base_iterator<ft::random_access_iterator_tag, T> 
	{
		typedef T         value_type;
		typedef T*   pointer;
		typedef T& reference;
		
		public:
			myiterator(pointer abc = NULL)
			{
				ptr = abc;
			}
			reference operator*(){return (*ptr);}
			pointer operator->() {return(ptr);}
			myiterator& operator++() { ptr++; return *this;}
			myiterator operator++(int)
			{ 
				myiterator abc = *this; 
				++(*this);
				return abc;
			}
			myiterator& operator--() { ptr--; return *this;}
			myiterator operator--(int)
			{ 
				myiterator abc = *this; 
				--(*this);
				return abc;
			}
			bool operator==(const myiterator& a)
			{ 
				if (*this->ptr == *a.ptr)
					return (true);
				return (false);
			}
			bool operator!=(const myiterator& a)
			{ 
				if (*this->ptr != *a.ptr)
					return (true);
				return (false);
			}
			bool operator>(const myiterator& a)
			{ 
				if (*this->ptr > *a.ptr)
					return (true);
				return (false);
			}
			bool operator<(const myiterator& a)
			{ 
				if (*this->ptr < *a.ptr)
					return (true);
				return (false);
			}
			bool operator<=(const myiterator& a)
			{ 
				if (*this->ptr <= *a.ptr)
					return (true);
				return (false);
			}
			bool operator>=(const myiterator& a)
			{ 
				if (*this->ptr >= *a.ptr)
					return (true);
				return (false);
			}
		private:
			pointer ptr;
	};
}
#endif