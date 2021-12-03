#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>

namespace ft
{

	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_table = _allocator.allocate(0);
				_capacity = 0;
				_size = 0;
			}	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_table = _allocator.allocate(n);
				for (int i = 0; i < n; i++)
				{
					_table[i] = val;
					// std::cout << _table[i] << std::endl;
				}
				this->_capacity = n;
				this->_size = n;
			}
			size_type capacity() {return (_capacity);}
			size_type size() {return (_size);}
		private:
			pointer _table;
			allocator_type _allocator;
			size_type _capacity;
			size_type _size;
	};
}

#endif