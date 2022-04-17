#pragma once
#include <iostream>
#include "iterator_traits.hpp"
#include "vector.hpp"
namespace ft
{
	//?https://www.cplusplus.com/reference/iterator/InputIterator/
	struct input_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/OutputIterator/
  	struct output_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/ForwardIterator/
  	struct forward_iterator_tag : public input_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/BidirectionalIterator/
  	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
 	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/iterator/
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct base_iterator 
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category 	iterator_category;
	};
	
	//?https://www.cplusplus.com/reference/iterator/
	//?https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

	//!#Iterator
	template <typename T>
	class myiterator : public ft::base_iterator<std::random_access_iterator_tag, T> 
	{		
		public:
			typedef T         value_type;
			typedef T*   pointer;
			typedef T& reference;
			typedef myiterator<const T> const_myiterator;
			typedef ptrdiff_t difference_type;

			myiterator(pointer abc = NULL)
			{
				_ptr = abc;
			}
			myiterator(myiterator const &it)
			{
				this->_ptr = it._ptr;
			}
			myiterator &operator=(myiterator const &it)
			{
				this->_ptr = it._ptr;
				return (*this);
			}
			reference operator*()
			{
				return (*_ptr);
			}
			pointer base() const
			{
				return (_ptr);
			}
			pointer operator->() {return(_ptr);}
			myiterator& operator++() { _ptr++; return *this;}
			myiterator operator++(int)
			{                                                                                         
				myiterator abc(*this); 
				++(*this);
				return abc;
			}
			myiterator& operator--()
			{
				_ptr--;
			 	return (*this);
			}
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
				for (int i = 0;i < a;i++)
					it._ptr++;
				return (it);
			}
			template <typename S>
			difference_type operator-(const myiterator<S> &first)
			{
				return (this->_ptr - first._ptr);
			}
			reference operator[](const int &a)
			{
				return _ptr[a];
			}
			template <typename S>
			bool operator==(const myiterator<S> &it) const
			{
				return (this->_ptr == it.base());
			}

			template <typename S>
			bool operator!=(const myiterator<S>& a)
			{ 
				if (this->_ptr != a._ptr)
					return (true);
				return (false);
			}
			template <typename S>
			bool operator>(const myiterator<S>& a)
			{ 
				if (this->_ptr > a._ptr)
					return (true);
				return (false);
			}

			template <typename S>
			bool operator<(const myiterator<S>& a)
			{ 
				if (this->_ptr < a._ptr)
					return (true);
				return (false);
			}

			template <typename S>
			bool operator<=(const myiterator<S>& a)
			{ 
				if (this->_ptr <= a._ptr)
					return (true);
				return (false);
			}

			template <typename S>
			bool operator>=(const myiterator<S>& a)
			{ 
				if (this->_ptr >= a._ptr)
					return (true);
				return (false);
			}
			//?https://en.cppreference.com/w/cpp/language/cast_operator
			//?https://stackoverflow.com/questions/1307876/how-do-conversion-operators-work-in-c
			//?https://www.youtube.com/watch?v=M2D11HXlgnE
			//*Declares a user-defined conversion function that participates in all implicit and explicit conversions.
			operator const_myiterator() const
			{
				return const_myiterator(_ptr);
			}
			operator myiterator<const T>()
			{
				return myiterator<const T>(_ptr);
			}
		protected:
			pointer _ptr;
	};
	
	template <typename T>
	myiterator<T> operator-(const myiterator<T> &it, const int &a)
	{
		myiterator<T> abc(it);
		for (int i = 0; i < a; i++)
			abc--;
		return (abc);
	}
	template <typename T>
	myiterator<T> operator+(const myiterator<T> &it, const int &a)
	{
		myiterator<T> abc(it);
		for (int i = 0; i < a; i++)
			abc++;
		return (abc);
	}
	template <typename T>
	myiterator<T> operator+(const int &a, const myiterator<T> &it)
	{
		myiterator<T> abc(it);
		for(int i = 0; i < a; i++)
			abc++;
		return (abc);
	}
}
