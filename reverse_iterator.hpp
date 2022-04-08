#pragma once
#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	//!#Reverse Iterator
	//?https://www.cplusplus.com/reference/iterator/reverse_iterator/

	template <typename iterator>
	class reverse_iterator
	{
		
		public:
			typedef iterator iterator_type;
			typedef typename ft::iterator_traits<iterator>::pointer	pointer;
			typedef typename ft::iterator_traits<iterator>::reference reference;
			typedef typename ft::iterator_traits<iterator>::value_type	value_type;
			typedef typename ft::iterator_traits<iterator>::iterator_category iterator_category;
			typedef ptrdiff_t difference_type;

			explicit reverse_iterator(iterator x = NULL)
			{
				it = x;
			}
			template <class Iter>
  			reverse_iterator (reverse_iterator<Iter> const &rev_it) : it(rev_it.base())
			{
				
			}
			iterator base() const
			{
				return (it);
			}
			reference operator*() const
			{
				iterator it2(it);
				--it2;
				return (*it2);
			}
			template <class Iter>
			reverse_iterator& operator=(reverse_iterator<Iter> const &rev_it)
			{
				this->it = rev_it.base();
				return (*this);
			}
			pointer operator->() const
			{
				//iterator it2(it);
				//--it2;
				return (&(operator*()));
				//return &(*(it2));
			}
			reverse_iterator& operator++()
			{
				--it;
				return (*this);
			}

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
				this->it = this->it + a;
				return (*this);
			}
			reverse_iterator &operator+= (difference_type n)
			{
				this->it = this->it - n;
				return (*this);
			}
			reverse_iterator operator+ (difference_type n) const
			{
				reverse_iterator<iterator> it(*this);
				this->it = this->it - n;
				return (it);
			}
			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator<iterator> it(*this);
				for (int i = 0;i < n; i++)
					it--;
				return (it);
			}
			reference operator[](const int &a)
			{
				iterator it2(it);
				it2--;
				return (it2[a]);
			}
			const iterator& operator[](const int &a) const
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
				if (this->it < a.it)
					return (true);
				return (false);
			}
			bool operator<(const reverse_iterator& a)
			{ 
				if (this->it > a.it)
					return (true);
				return (false);
			}
			bool operator<=(const reverse_iterator& a)
			{ 
				if (this->it >= a.it)
					return (true);
				return (false);
			}
			bool operator>=(const reverse_iterator& a)
			{ 
				if (this->it <= a.it)
					return (true);
				return (false);
			}
		private:
			iterator it;
	};
	template <typename T>
	reverse_iterator<T> operator-(const reverse_iterator<T> &it, const int &a)
	{
		reverse_iterator<T> abc(it);

		for (int i = 0; i < a; i++)
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
	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
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