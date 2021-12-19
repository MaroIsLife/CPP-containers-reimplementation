#pragma once
#include <iostream>
#include "vector.hpp"
namespace ft
{
	//?https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
	struct input_iterator_tag {};
  	struct output_iterator_tag {};
  	struct forward_iterator_tag : public input_iterator_tag {};
  	struct bidirectional_iterator_tag : public forward_iterator_tag {};
 	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/iterator/
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct base_iterator 
	{
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
	class myiterator : public ft::base_iterator<ft::random_access_iterator_tag, T> 
	{
		typedef T         value_type;
		typedef T*   pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		
		public:
			myiterator(pointer abc = NULL)
			{
				_ptr = abc;
			}
			myiterator(const myiterator &it)
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
			pointer operator->() {return(_ptr);}
			myiterator& operator++() { _ptr++; return *this;}
			myiterator operator++(int)
			{ 
				myiterator abc(*this); 
				++(*this);
				return abc;
			}
			myiterator& operator--() { _ptr--; return *this;}
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
					it._ptr++;
				return (it);
			}
			difference_type operator-(const myiterator &first)
			{
				return (this->_ptr - first._ptr);
			}
			reference operator[](const int &a)
			{
				return _ptr[a];
			}
			bool operator==(const myiterator& a)
			{ 
				if (this->_ptr == a._ptr)
					return (true);
				return (false);
			}
			bool operator!=(const myiterator& a)
			{ 
				if (this->_ptr != a._ptr)
					return (true);
				return (false);
			}
			bool operator>(const myiterator& a)
			{ 
				if (this->_ptr > a._ptr)
					return (true);
				return (false);
			}
			bool operator<(const myiterator& a)
			{ 
				if (this->_ptr < a._ptr)
					return (true);
				return (false);
			}
			bool operator<=(const myiterator& a)
			{ 
				if (this->_ptr <= a._ptr)
					return (true);
				return (false);
			}
			bool operator>=(const myiterator& a)
			{ 
				if (this->_ptr >= a._ptr)
					return (true);
				return (false);
			}
			//?https://en.cppreference.com/w/cpp/language/cast_operator
			//?https://stackoverflow.com/questions/1307876/how-do-conversion-operators-work-in-c
			//?https://www.youtube.com/watch?v=M2D11HXlgnE
			//*Declares a user-defined conversion function that participates in all implicit and explicit conversions.
			operator myiterator<const T>() const
			{
				return myiterator<const T>(_ptr);
			}
		private:
			pointer _ptr;
	};
	
	template <typename T>
	myiterator<T> operator-(const myiterator<T> &it, const int &a)
	{
		myiterator<T> abc(it);

		for(int i = 0; i < a; i++)
			abc--;
		return (abc);
	}
	template <typename T>
	myiterator<T> operator+(const myiterator<T> &it, const int &a)
	{
		myiterator<T> abc(it);

		for(int i = 0; i < a; i++)
			abc++;
		return (abc);
	}

	//!#Reverse Iterator
	template <typename T>
	class reverse_myiterator : public ft::base_iterator<ft::random_access_iterator_tag, T> 
	{
		typedef T         value_type;
		typedef T*   pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		
		
		public:
			reverse_myiterator(pointer abc = NULL)
			{
				_ptr = abc;
			}
			reverse_myiterator(const reverse_myiterator &it)
			{
				this->_ptr = it._ptr;
			}
			reference operator*()
			{
				return (*_ptr);
			}
			pointer operator->() {return(_ptr);}
			reverse_myiterator& operator++() { _ptr--; return *this;}
			reverse_myiterator operator++(int)
			{ 
				reverse_myiterator abc(*this); 
				this->_ptr--;
				return abc;
			}
			reverse_myiterator& operator--() { _ptr++; return *this;}
			reverse_myiterator operator--(int)
			{ 
				reverse_myiterator abc = *this; 
				this->_ptr++;
				return abc;
			}
			reverse_myiterator &operator-=(const int &a)
			{
				for (int i = 0;i < a; i++)
					this->_ptr++;
				return (*this);
			}

			reverse_myiterator &operator+=(const int &a)
			{
				for (int i = 0;i < a; i++)
					this->_ptr--;
				return (*this);
			}
	
			reverse_myiterator operator+(const int &a)
			{
				reverse_myiterator<T> it(*this);
				for(int i = 0;i < a;i++)
					it._ptr--;
				return (it);
			}
			difference_type operator-(const reverse_myiterator &first)
			{
				return (this->_ptr - first._ptr);
			}
			reference operator[](const int &a)
			{ 
				return _ptr[a];
			}
			bool operator==(const reverse_myiterator& a)
			{ 
				if (this->_ptr == a._ptr)
					return (true);
				return (false);
			}
			bool operator!=(const reverse_myiterator& a)
			{ 
				if (this->_ptr != a._ptr)
					return (true);
				return (false);
			}
			bool operator>(const reverse_myiterator& a)
			{ 
				if (this->_ptr > a._ptr)
					return (true);
				return (false);
			}
			bool operator<(const reverse_myiterator& a)
			{ 
				if (this->_ptr < a._ptr)
					return (true);
				return (false);
			}
			bool operator<=(const reverse_myiterator& a)
			{ 
				if (this->_ptr <= a._ptr)
					return (true);
				return (false);
			}
			bool operator>=(const reverse_myiterator& a)
			{ 
				if (this->_ptr >= a._ptr)
					return (true);
				return (false);
			}
			operator reverse_myiterator<const T>() 
			{
				return reverse_myiterator<const T>(_ptr);
			}
		private:
			pointer _ptr;
	};

	template <typename T>
	reverse_myiterator<T> operator-(const reverse_myiterator<T> &it, const int &a)
	{
		reverse_myiterator<T> abc(it);

		for(int i = 0; i < a; i++)
			abc--;
		return (abc);
	}
	template <typename T>
	reverse_myiterator<T> operator+(const reverse_myiterator<T> &it, const int &a)
	{
		reverse_myiterator<T> abc(it);

		for(int i = 0; i < a; i++)
			abc++;
		return (abc);
	}
}
