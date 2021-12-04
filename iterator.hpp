#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>


namespace ft
{
	// template <class Category, class T, class Distance = ptrdiff_t,
	// 		class Pointer = T*, class Reference = T&>
	template <class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		// typedef Category  iterator_category;
		
		public:
			iterator(pointer abc)
			{
				ptr = abc;
			}
			reference operator*(){return (*ptr);}
			pointer operator->() {return(ptr);}
			iterator& operator++() { ptr++; return *this;}
			iterator operator++(int)
			{ 
				iterator abc = *this; 
				++(*this);
				return abc;
			}  
		private:
			pointer ptr;
	};
}
#endif