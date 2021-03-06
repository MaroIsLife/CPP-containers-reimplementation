#pragma once

#include <iostream>


namespace ft
{
	
	//? https://www.cplusplus.com/reference/utility/pair/?kw=pair
	template <class T1, class T2> 
	struct pair
	{
		public:
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;
		pair() : first(), second() {}
		
		operator pair<const T1, const T2> () const { return pair<const T1, const T2> (first, second); }
		template<class U, class V> 
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
		{

		}

		pair (const first_type& a, const second_type& b) : first(a), second(b) 
		{
			
		}

		pair(const pair& pr) : first(pr.first), second(pr.second)
		{
			
		}

		
		
		pair& operator= (const pair& pr)
		{
			
			first = pr.first;
			second = pr.second;
			return (*this);
		}
		void operator++()
		{
			std::cout << "++" << std::endl;
		}

	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1, class T2>
  	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
}