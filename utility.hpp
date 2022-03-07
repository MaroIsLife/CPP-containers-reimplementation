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
		pair()
		{
			first = T1();
			second = T2();
		}
		template<class U, class V> 
		pair (const pair<U,V>& pr)
		{
			first = pr.first;
			second = pr.second;
		}
		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}
		pair (const first_type& a, const second_type& b)
		{
			first = a;
			second = b;
		}
	};
	template <class T1, class T2>
  	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
}