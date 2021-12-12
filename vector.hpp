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
		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc)
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
			size_type max_size(){return(_allocator.max_size());}
			void resize (size_type n, value_type val = value_type())
			{
				if (n == _size)
					return;
				while (n > _capacity)
					_capacity *= 2;
				_table2 = _allocator.allocate(_capacity);
				for (int i = 0; i < _size; i++)
					_table2[i] = _table[i];
				_size = n;
				for (int i = 0; i < _size; i++)
					_table2[i] = val;
				_allocator.destroy(_table);
				_allocator.deallocate(_table, _capacity);
				_table = _allocator.allocate(_capacity);
				for (int i = 0; i < _size; i++)
					_table[i] = _table2[i];
				_allocator.destroy(_table2);
				_allocator.deallocate(_table2, _capacity / 2);
			}
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
					for (int i = 0; i < _size; i++)
						_table[i] = _table2[i];
					_allocator.destroy(_table2);
					_allocator.deallocate(_table2, _capacity / 2);
				}
				_table[_size] = n;
				_size++;
			}
			void pop_back()
			{
				if (_size == 0)
					return ;
				_table[_size] = 0; 
				_size--;
			}
		void assign (size_type n, const value_type& val)
		{	
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			if (n > _capacity)
				_capacity = n;
			_table = _allocator.allocate(_capacity);
			_size = n;
			for (int i = 0;i < _size;i++)
				_table[i] = val;
		}
  		void assign (iterator first, iterator last)
		{
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_diff = last - first;
			_size = _diff;
			if (_diff > _capacity)
				_capacity = _diff;
			_table = _allocator.allocate(_capacity);
			for (int i = 0; first != last; first++)
				_table[i++] = *first;
		}
		iterator insert (iterator position, const value_type& val)
		{
			_size++;
			if (_size > _capacity)
				_capacity *= 2;
			_table2 = _allocator.allocate(_capacity);
			int o = 0;
			iterator it(this->begin());
			for (int i = 0; i < _size; i++)
			{
				if (it == position)
					_table2[o++] = val;
				it++;
				_table2[o++] = _table[i];
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (int i = 0; i < _size; i++)
				_table[i] = _table2[i];
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
			return (position);
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			_size+= n;
			while (_size > _capacity)
				_capacity *= 2;
			_table2 = _allocator.allocate(_capacity);
			int o = 0;
			iterator it(this->begin());
			for (int i = 0; i < _size; i++)
			{
				if (it == position)
					for (int k = 0; k < n; k++)
						_table2[o++] = val;
				it++;
				_table2[o++] = _table[i];
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (int i = 0; i < _size; i++)
				_table[i] = _table2[i];
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
		}

		
		allocator_type get_allocator() const {return(allocator_type());}
		reference operator[](const int &a){return (_table[a]);}
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