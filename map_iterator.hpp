#pragma once

namespace ft
{


template <typename T>
class map_iterator
{	
	public:
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;

	typedef ptrdiff_t difference_type;

	map_iterator() : ptr(NULL)
	{

	}
	map_iterator(T* ptr) : ptr(ptr)
	{
	}
	map_iterator(const map_iterator& it) : ptr(it.ptr) 
	{

	}
	map_iterator& operator++()
	{
		ptr++;
		return (*this);
	}
	map_iterator operator++(int)
	{
		map_iterator tmp(*this);
		++(*this);
		return (tmp);
	}
	map_iterator& operator--()
	{
		ptr--;
		return (*this);
	}
	map_iterator operator--(int)
	{
		map_iterator tmp(*this);
		--(*this);
		return (tmp);
	}
	value_type& operator*()
	{
		return (ptr->data);
	}
	pointer operator->() const
	{
		return (ptr);
	}
	bool operator==(const map_iterator& it) const
	{
		if (ptr == it.ptr)
			return (true);
		return (false);
	}
	bool operator!=(const map_iterator& it) const
	{
		if (ptr != it.ptr)
			return (true);
		return (false);
	}
	bool operator>(const map_iterator& it) const
	{
		if (ptr > it.ptr)
			return (true);
		return (false);
	}
	bool operator<(const map_iterator& it) const
	{
		if (ptr < it.ptr)
			return (true);
		return (false);
	}
	bool operator<=(const map_iterator& it) const
	{
		if (ptr <= it.ptr)
			return (true);
		return (false);
	}
	bool operator>=(const map_iterator& it) const
	{
		if (ptr >= it.ptr)
			return (true);
		return (false);
	}
	private:
	value_type *ptr;
};

}

