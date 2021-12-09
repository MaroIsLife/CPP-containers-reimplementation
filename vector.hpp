#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include "iterator.hpp"
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
			typedef ft::myiterator<T> iterator;
			typedef ptrdiff_t difference_type;
			// typedef ft::iterator(T);

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
					_table[i] = val;
				this->_capacity = n;
				this->_size = n;
			}
			vector (iterator first, iterator last, const allocator_type& alloc = allocator_type())
			{
				_diff = last - first;
				_size = _diff;
				_capacity = _size;
				_table = _allocator.allocate(_diff);
				for (int i = 0; first != last; first++)
					_table[i++] = *first;
			}
			iterator begin()
			{
				return(iterator(_table));
			}
			iterator end()
			{
				return(iterator(&_table[_size]));
			}
			size_type capacity() {return (_capacity);}
			size_type size() {return (_size);}
			void push_back(T n)
			{
				if (_size + 1 >= _capacity)
				{
					_table2 = _allocator.allocate(_capacity);
					for (int i = 0; i < _size; i++)
						_table2[i] = _table[i];
					_allocator.destroy(_table);
					_allocator.deallocate(_table, _capacity);
					if (_capacity == 0)
						_capacity++;
					else
						_capacity *= 2;
					_table = _allocator.allocate(_capacity);
					for(int i = 0; i < _size; i++)
						_table[i] = _table2[i];
					_allocator.destroy(_table2);
					_allocator.deallocate(_table2, _capacity / 2);
				}
				_table[_size] = n;
				_size++;
			}
		private:
			pointer _table;
			pointer _table2;
			allocator_type _allocator;
			size_type _capacity;
			size_type _size;
			difference_type _diff;
	};
}

#endif