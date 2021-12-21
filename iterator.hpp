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
			typedef ptrdiff_t difference_type;

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
				for (int i = 0;i < a;i++)
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
		for(int i = 0; i < a; i++)
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

	//!#Reverse Iterator
	//?https://www.cplusplus.com/reference/iterator/reverse_iterator/

	template <typename T>
	class reverse_iterator
	{
		typedef T         value_type;
		typedef T*   pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		
		
		public:
			explicit reverse_iterator(ft::myiterator<T> x = NULL)
			{
				it = x;
			}
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) //! check why function isn't called
			{
				this->it = rev_it;
			}
			ft::myiterator<T> base() const
			{
				ft::myiterator<T> it2(it);
				return (it2);
			}
			reference operator*()
			{
				return (*it);
			}
			reverse_iterator& operator=(const myiterator<T> &it1)
			{
				this->it = it1;
			}
			pointer operator->() 
			{
				return &(*it);
			}
			reverse_iterator& operator++() { it--; return *this;}
			reverse_iterator operator++(int)
			{ 
				reverse_iterator abc(*this); 
				this->it--;
				return abc;
			}
			reverse_iterator& operator--() { it++; return *this;}
			reverse_iterator operator--(int)
			{ 
				reverse_iterator abc = *this; 
				this->it++;
				return abc;
			}
			reverse_iterator &operator-=(const int &a)
			{
				for (int i = 0;i < a; i++)
					this->it--;
				return (*this);
			}

			reverse_iterator &operator+=(const int &a)
			{

				for (int i = 0;i < a; i++)
					this->it++;
				return (*this);
			}
	
			reverse_iterator operator+(const int &a)
			{
				reverse_iterator<T> it(*this);
				for(int i = 0;i < a;i++)
					it++;
				return (it);
			}
			difference_type operator-(const reverse_iterator &first)
			{
				return (this->it - first.it);
			}
			reference operator[](const int &a)
			{ 
				return it[a];
			}
			const T& operator[](const int &a) const
			{ 
				return it[a];
			}
			bool operator==(const reverse_iterator& a)
			{ 
				if (this->it == a.it)
					return (true);
				return (false);
			}
			bool operator!=(const reverse_iterator& a)
			{ 
				if (this->it != a.it)
					return (true);
				return (false);
			}
			bool operator>(const reverse_iterator& a)
			{ 
				if (this->it > a.it)
					return (true);
				return (false);
			}
			bool operator<(const reverse_iterator& a)
			{ 
				if (this->it < a.it)
					return (true);
				return (false);
			}
			bool operator<=(const reverse_iterator& a)
			{ 
				if (this->it <= a.it)
					return (true);
				return (false);
			}
			bool operator>=(const reverse_iterator& a)
			{ 
				if (this->it >= a.it)
					return (true);
				return (false);
			}
		private:
			ft::myiterator<T> it;
	};

	template <typename T>
	reverse_iterator<T> operator-(const reverse_iterator<T> &it, const int &a)
	{
		reverse_iterator<T> abc(it);

		for(int i = 0; i < a; i++)
			abc--;
		return (abc);
	}
	template <typename T>
	reverse_iterator<T> operator+(const reverse_iterator<T> &it, const int &a)
	{
		reverse_iterator<T> abc(it);
		for (int i = 0; i < a; i++)
			abc++;
		return (abc);
	}
	template <typename T>
	reverse_iterator<T> operator+(const int &a, const reverse_iterator<T> &it)
	{
		reverse_iterator<T> abc(it);

		for (int i = 0; i < a; i++)
			abc++;
		return (abc);
	}

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		for (Distance i = 0; i < n; i++)
			it++;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type mydiff = last - first;

		return (mydiff);
	}
}
