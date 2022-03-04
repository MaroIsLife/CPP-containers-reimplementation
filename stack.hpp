#pragma once 
#include "vector.hpp"
#include "iterator.hpp"

namespace ft
{
	//?https://en.cppreference.com/w/cpp/container/stack
	//?https://www.cplusplus.com/reference/stack/stack/?kw=stack
	template <class T, class Container = ft::vector<T> > class stack
	{
		public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

		explicit stack (const container_type& ctnr = container_type())
		{
			c = ctnr;
		}
		void push (const value_type& val)
		{
			c.push_back(val);
		}
		void pop ()
		{
			c.pop_back();
		}
		reference top ()
		{
			return c.back();
		}
		const_reference top () const
		{
			return c.back();
		}
		bool empty () const
		{
			return c.empty();
		}
		size_type size () const
		{
			return c.size();
		}
		protected:
			Container c;

		template <class B, class C>
		friend bool operator== (const stack<B,C>& lhs, const stack<B,C>& rhs);
		template <class B, class C>
		friend bool operator!= (const stack<B,C>& lhs, const stack<B,C>& rhs);
		template <class B, class C>
		friend bool operator<  (const stack<B,C>& lhs, const stack<B,C>& rhs);
		template <class B, class C>
		friend bool operator<= (const stack<B,C>& lhs, const stack<B,C>& rhs);
		template <class B, class C>
		friend bool operator>  (const stack<B,C>& lhs, const stack<B,C>& rhs);
		template <class B, class C>
		friend bool operator>= (const stack<B,C>& lhs, const stack<B,C>& rhs);
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs.c == rhs.c);
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}	
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}