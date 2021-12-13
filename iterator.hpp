#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "vector.hpp"

namespace ft
{
	
	struct random_access_iterator_tag {};

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
		typedef ptrdiff_t difference_type;
		
		public:
			myiterator(pointer abc = NULL)
			{
				ptr = abc;
			}
			myiterator(const myiterator &it)
			{
				this->ptr = it.ptr;
			}
			reference operator*(){return (*ptr);}
			pointer operator->() {return(ptr);}
			myiterator& operator++() { ptr++; return *this;}
			myiterator operator++(int)
			{ 
				myiterator abc(*this); 
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
			myiterator &operator-=(const int &a)
			{
				for (int i = 0;i < a; i++)
					(*this)--;
				return (*this);
			}

			myiterator &operator+=(const int &a)
			{
				for (int i = 0;i < a; i++)
					(*this)++;
				return (*this);
			}

			myiterator operator+(const int &a)
			{
				myiterator<T> it(*this);
				for(int i = 0;i < a;i++)
					it.ptr++;
				return (it);
			}
			difference_type operator-(const myiterator &first)
			{
				return (this->ptr - first.ptr);
			}
			reference operator[](const int &a)
			{ 
				return ptr[a];
			}
			bool operator==(const myiterator& a)
			{ 
				if (this->ptr == a.ptr)
					return (true);
				return (false);
			}
			bool operator!=(const myiterator& a)
			{ 
				if (this->ptr != a.ptr)
					return (true);
				return (false);
			}
			bool operator>(const myiterator& a)
			{ 
				if (this->ptr > a.ptr)
					return (true);
				return (false);
			}
			bool operator<(const myiterator& a)
			{ 
				if (this->ptr < a.ptr)
					return (true);
				return (false);
			}
			bool operator<=(const myiterator& a)
			{ 
				if (this->ptr <= a.ptr)
					return (true);
				return (false);
			}
			bool operator>=(const myiterator& a)
			{ 
				if (this->ptr >= a.ptr)
					return (true);
				return (false);
			}
		private:
			pointer ptr;
	};
}
#endif