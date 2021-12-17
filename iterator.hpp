#pragma once
#include <iostream>
#include "vector.hpp"

namespace ft
{
	//?https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
	struct random_access_iterator_tag {};

	//?https://www.cplusplus.com/reference/iterator/iterator/
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
				ptr = abc;
			}
			myiterator(const myiterator &it)
			{
				this->ptr = it.ptr;
			}
			reference operator*()
			{
				return (*ptr);
			}
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
				ptr = abc;
			}
			reverse_myiterator(const reverse_myiterator &it)
			{
				this->ptr = it.ptr;
			}
			reference operator*()
			{
				return (*ptr);
			}
			pointer operator->() {return(ptr);}
			reverse_myiterator& operator++() { ptr--; return *this;}
			reverse_myiterator operator++(int)
			{ 
				reverse_myiterator abc(*this); 
				this->ptr--;
				return abc;
			}
			reverse_myiterator& operator--() { ptr++; return *this;}
			reverse_myiterator operator--(int)
			{ 
				reverse_myiterator abc = *this; 
				this->ptr++;
				return abc;
			}
			reverse_myiterator &operator-=(const int &a)
			{
				for (int i = 0;i < a; i++)
					this->ptr++;
				return (*this);
			}

			reverse_myiterator &operator+=(const int &a)
			{
				for (int i = 0;i < a; i++)
					this->ptr--;
				return (*this);
			}
	
			reverse_myiterator operator+(const int &a)
			{
				reverse_myiterator<T> it(*this);
				for(int i = 0;i < a;i++)
					it.ptr--;
				return (it);
			}
			difference_type operator-(const reverse_myiterator &first)
			{
				return (this->ptr - first.ptr);
			}
			reference operator[](const int &a)
			{ 
				return ptr[a];
			}
			bool operator==(const reverse_myiterator& a)
			{ 
				if (this->ptr == a.ptr)
					return (true);
				return (false);
			}
			bool operator!=(const reverse_myiterator& a)
			{ 
				if (this->ptr != a.ptr)
					return (true);
				return (false);
			}
			bool operator>(const reverse_myiterator& a)
			{ 
				if (this->ptr > a.ptr)
					return (true);
				return (false);
			}
			bool operator<(const reverse_myiterator& a)
			{ 
				if (this->ptr < a.ptr)
					return (true);
				return (false);
			}
			bool operator<=(const reverse_myiterator& a)
			{ 
				if (this->ptr <= a.ptr)
					return (true);
				return (false);
			}
			bool operator>=(const reverse_myiterator& a)
			{ 
				if (this->ptr >= a.ptr)
					return (true);
				return (false);
			}
		private:
			pointer ptr;
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
