#pragma once


namespace ft
{

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for(int i = 0; first1 != last1; first1++) // Finish other Equal prototypes
		{
			if (*first1 != *first2)
				return (false);
			first2++;
		}
		return (true);
	}
}
