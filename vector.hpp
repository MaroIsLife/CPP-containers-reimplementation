#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <algorithm>
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
			//#Constructors
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
					_allocator.construct(&_table[i],val);
					// _table[i] = val;
				this->_capacity = n;
				this->_size = n;
			}
			template <class InputIterator>
			vector (iterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				_diff = last - first;
				_size = _diff;
				_capacity = _size;
				_table = _allocator.allocate(_diff);
				for (int i = 0; first != last; first++)
				{
					_allocator.construct(&_table[i++],*first);
				}
					// _table[i++] = *first;
			}
			//#Iterators:
			iterator begin()
			{
				return(iterator(_table));
			}
			iterator end()
			{
				return(iterator(&_table[_size]));
			}
			//#Capacity:
			size_type capacity() {return (_capacity);}
			size_type size() {return (_size);}
			size_type max_size(){return(_allocator.max_size());}
			void reserve (size_type n)
			{
				if (n > _capacity)
				{
					_table2 = _allocator.allocate(_capacity);
					for (int i = 0; i < _size; i++)
						_allocator.construct(&_table2[i],_table[i]);
					_allocator.destroy(_table);
					_allocator.deallocate(_table, _capacity);
					_allocator.allocate(n);
					for (int i = 0; i < _size; i++)
						_allocator.construct(&_table[i],_table2[i]);
					_capacity = n;
				}
			}
			bool empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n == _size)
					return;
				while (n > _capacity)
					_capacity *= 2;
				_table2 = _allocator.allocate(_capacity);
				for (int i = 0; i < _size; i++)
					_allocator.construct(&_table2[i],_table[i]);
					// _table2[i] = _table[i];
				// std::copy(this->begin(),this->end(),_table2);
				for (int i = _size; i < _capacity; i++)
						_allocator.construct(&_table2[i],val);
					// _table2[i] = val;
				_size = n;
				_allocator.destroy(_table);
				_allocator.deallocate(_table, _capacity);
				_table = _allocator.allocate(_capacity);
				for (int i = 0; i < _size; i++)
					_allocator.construct(&_table[i],_table2[i]);
				// 	_table[i] = _table2[i];
				// std::copy(iterator(&_table2[0]),iterator(&_table2[_size]),_table);
				_allocator.destroy(_table2);
				_allocator.deallocate(_table2, _capacity / 2);
			}
			//#Modifiers
			void push_back(T n)
			{
				if (_size + 1 >= _capacity)
				{
					_table2 = _allocator.allocate(_capacity);
					for (int i = 0; i < _size; i++)
						_allocator.construct(&_table2[i],_table[i]);
					
					_allocator.destroy(_table);
					_allocator.deallocate(_table, _capacity);
					if (_capacity == 0)
						_capacity++;
					else
						_capacity *= 2;
					_table = _allocator.allocate(_capacity);
					for (int i = 0; i < _size; i++)
						_allocator.construct(&_table[i],_table2[i]);
					_allocator.destroy(_table2);
					_allocator.deallocate(_table2, _capacity / 2);
				}
				_allocator.construct(&_table[_size], n);
				_size++;
			}
			void pop_back()
			{
				if (_size == 0)
					return;
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
				_allocator.construct(&_table[i], val);
		}
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last)
		{
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_diff = last - first;
			_size = _diff;
			if (_diff > _capacity)
				_capacity = _diff;
			_table = _allocator.allocate(_capacity);
			for (int i = 0; first != last; first++)
				_allocator.construct(&_table[i++], *first);
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
					_allocator.construct(&_table2[o++], val);
				it++;
				_allocator.construct(&_table2[o++], _table[i]);
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (int i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
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
						_allocator.construct(&_table2[o++], val);
				it++;
				_allocator.construct(&_table2[o++], _table[i]);
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (int i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			_diff = last - first;
			if (_diff > _capacity)
				_capacity = _diff + _size;
			else
				_capacity *= 2;
			_size += _diff;
			_table2 = _allocator.allocate(_capacity);
			int o = 0;
			iterator it(this->begin());
			for (int i = 0; i < _size; i++)
			{
				if (it == position)
					for (; first != last; first++)
						_allocator.construct(&_table2[o++], *first);
				it++;
				_allocator.construct(&_table2[o++], _table[i]);
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (int i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
		}
		iterator erase (iterator position)
		{
			iterator it(this->begin());
			_size--;
			int o = 0;
			for(int i = 0; i < _size ;i++)
			{
				if (it == position)
					o++;
				_allocator.construct(&_table[i], _table[o++]);
				it++;
			}
			return (position);
		}
		iterator erase (iterator first, iterator last)
		{
			_diff = last - first;
			_table2 = _allocator.allocate(_capacity);
			iterator it(this->begin());
			for (int i = 0;i < _size;i++)
			{
				if (it == first)
					for (;it != last; it++)
						i++;
				_allocator.construct(&_table2[i], _table[i]);
				it++;
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_size -= _diff;
			for (int i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
			return (first);
		}
		void swap (vector& x)
		{
			// std::swap(*this,x);
			pointer tmp = x._table;
			size_type tmp_capacity = x._capacity;
			size_type tmp_size = x._size;

			x._table = this->_table;
			x._capacity = this->_capacity;
			x._size = this->_size;

			this->_table = tmp;
			this->_capacity = tmp_capacity;
			this->_size = tmp_size;
						
		}
		void clear()
		{
			_allocator.destroy(_table);
			_size = 0;
		}
		//#Allocator
		allocator_type get_allocator() const {return(allocator_type());}
		//#Element Access
		reference operator[](const int &a){return (_table[a]);}
		reference at (size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("ft_vector.at is out of range");
			return(_table[n]);
		}
		const_reference at (size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("const");
			return(_table[n]);
		}
		reference front(){return(_table[0]);}
		const_reference front() const{return(_table[0]);}
		reference back(){return(_table[_size]);}
		const_reference back() const{return(_table[_size]);}
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