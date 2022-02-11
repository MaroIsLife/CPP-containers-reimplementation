#pragma once 
#include <iostream>
#include <algorithm>
#include <memory>
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	//?https://www.cplusplus.com/reference/vector/vector/?kw=vector
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
			typedef ft::myiterator<const T>  const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef ptrdiff_t difference_type;
		public:
			//!Constructors/Destructors
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				(void)alloc;
				_table = _allocator.allocate(0);
				_capacity = 0;
				_size = 0;
			}	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				(void)alloc;
				//*Using allocator construct for const data types
				_table = _allocator.allocate(n);
				for (size_t i = 0; i < n; i++)
					_allocator.construct(&_table[i], val);
				this->_capacity = n;
				this->_size = n;
			}
			template <typename InputIterator>
			void rangeContructor(InputIterator first, InputIterator last, std::input_iterator_tag)
			{
				while (first != last)
					push_back(*(first++));
			}
			template <typename InputIterator>
			void rangeContructor(InputIterator first, InputIterator last, std::random_access_iterator_tag)
			{
				 _diff = std::distance(first,last);
				_size = _diff;
				_capacity = _size;
				_table = _allocator.allocate(_diff);
				for (size_t i = 0; first != last; first++)
					_allocator.construct(&_table[i++], *first);
			}
			template <typename InputIterator> //* <-- catch-all property of templates
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type *ptr = NULL)
			{
				typename ft::iterator_traits<InputIterator>::iterator_category input; //T* = Random access iterator in iterator traits
				(void)ptr;
				(void)alloc;
				rangeContructor(first, last, input);
			}
			vector& operator= (const vector& x)
			{
				this->_table = x._table;
				this->_size = x._size;
				this->_capacity = x._capacity;
				return (*this);
			}
			vector (const vector& x)
			{
				this->_table = x._table;
				this->_size = x._size;
				this->_capacity = x._capacity;
			}
			~vector()
			{
				// _allocator.destroy(_table);
				// _allocator.deallocate(_table, _capacity);
			}
			//!Iterators:
			iterator begin()
			{
				return (iterator(_table));
			}
			iterator end()
			{
				return (iterator(&_table[_size]));
			}
			const_iterator begin() const
			{
				return (const_iterator(_table));
			}
			const_iterator end() const
			{
				return (const_iterator(&_table[_size]));
			}
			reverse_iterator rbegin()
			{
				return(reverse_iterator(this->end() - 1));
			}
			reverse_iterator rend()
			{
				return(reverse_iterator(this->begin() - 1));
			}
			const_reverse_iterator rbegin() const
			{
				return(const_reverse_iterator(&_table[_size - 1]));
			}
			const_reverse_iterator rend() const
			{
				return(const_reverse_iterator(_table));
			}
			//!Capacity:
			size_type capacity() {return (_capacity);}
			size_type size() {return (_size);}
			size_type size() const {return (_size);}
			size_type max_size(){return(_allocator.max_size());}
			void reserve (size_type n)
			{
				if (n > _capacity)
				{
					_table2 = _allocator.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
						_allocator.construct(&_table2[i],_table[i]);
					_allocator.destroy(_table);
					_allocator.deallocate(_table, _capacity);
					_allocator.allocate(n);
					for (size_t i = 0; i < _size; i++)
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
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(&_table2[i],_table[i]);
				for (size_t i = _size; i < _capacity; i++)
						_allocator.construct(&_table2[i],val);
				_size = n;
				_allocator.destroy(_table);
				_allocator.deallocate(_table, _capacity);
				_table = _allocator.allocate(_capacity);
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(&_table[i],_table2[i]);
				_allocator.destroy(_table2);
				_allocator.deallocate(_table2, _capacity / 2);
			}
			//!Modifiers
			void push_back(T n)
			{
				if (_size + 1 >= _capacity)
				{
					_table2 = _allocator.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
						_allocator.construct(&_table2[i],_table[i]);
					
					_allocator.destroy(_table);
					_allocator.deallocate(_table, _capacity);
					if (_capacity == 0)
						_capacity++;
					else
						_capacity *= 2;
					_table = _allocator.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
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
				_table[_size] = (T)0;
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
			for (size_t i = 0;i < _size;i++)
				_allocator.construct(&_table[i], val);
		}
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last, 
		  	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type *ptr = NULL)
		{
			(void)ptr;
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_diff = last - first;
			_size = _diff;
			if (static_cast<size_t>(_diff) > _capacity)
				_capacity = _diff;
			_table = _allocator.allocate(_capacity);
			for (size_t i = 0; first != last; first++)
				_allocator.construct(&_table[i++], *first);
		}
		iterator insert (iterator position, const value_type& val)
		{
			_size++;
			if (_size > _capacity)
				_capacity *= 2;
			if (_size > _capacity)
				_capacity = _size;
			_table2 = _allocator.allocate(_capacity);
			int o = 0;
			iterator it(this->begin());
			for (size_t i = 0; i < _size; i++)
			{
				if (it == position)
					_allocator.construct(&_table2[o++], val);
				it++;
				_allocator.construct(&_table2[o++], _table[i]);
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
			return (position);
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			_size+= n;
			if (_size > _capacity)
				_capacity *= 2;
			if (_size > _capacity)
				_capacity = _size;
			_table2 = _allocator.allocate(_capacity);
			int o = 0;
			iterator it(this->begin());
			for (size_t i = 0; i < _size; i++)
			{
				if (it == position)
					for (size_t k = 0; k < n; k++)
					 	_allocator.construct(&_table2[o++], val);
				it++;
				_allocator.construct(&_table2[o++], _table[i]);
			}
			_allocator.destroy(_table);
			_allocator.deallocate(_table, _capacity);
			_table = _allocator.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type *ptr = NULL)
		{
			(void)ptr;
			_diff = last - first;
			_size += _diff;
			if (_size > _capacity)
				_capacity *= 2;
			if (_size > _capacity)
				_capacity = _size;
			_table2 = _allocator.allocate(_capacity);
			int o = 0;
			iterator it(this->begin());
			for (size_t i = 0; i < _size; i++)
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
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			_allocator.destroy(_table2);
			_allocator.deallocate(_table2, _capacity);
		}
		iterator erase (iterator position)
		{
			iterator it(this->begin());
			_size--;
			int o = 0;
			for(size_t i = 0; i < _size ;i++)
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
			size_t o = 0;
			for (size_t i = 0; i < _size; i++)
			{
				if (it == first)
					for (;it != last; it++)
						o++;
				_allocator.construct(&_table2[i], _table[o++]);
				it++;
			}
			for (size_t i = 0; i < _size; i++)
				_allocator.destroy(&_table[i]);
			_allocator.deallocate(_table, _capacity);
			_size -= _diff;
			_table = _allocator.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(&_table[i], _table2[i]);
			for (size_t i = 0; i < _size; i++)
				_allocator.destroy(&_table2[i]);
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
		//!Allocator
		allocator_type get_allocator() const {return(allocator_type());}
		//!Element Access
		reference operator[](const int &a){return (_table[a]);}
		const T& operator[](const int &a) const {return (_table[a]);}
		reference at (size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("ft_vector.at is out of range");
			return(_table[n]);
		}
		const_reference at (size_type n) const
		{
			//Object should be const
			if (n >= _size)
				throw std::out_of_range("const");
			return(_table[n]);
		}
		reference front(){return(_table[0]);}
		const_reference front() const{return(_table[0]);}
		reference back(){return(_table[_size - 1]);}
		const_reference back() const{return(_table[_size - 1]);}

		private:
			pointer _table;
			pointer _table2;
			allocator_type _allocator;
			size_type _capacity;
			size_type _size;
			difference_type _diff;
	};

	//?https://www.cplusplus.com/reference/vector/vector/operators/
	//?https://www.cplusplus.com/reference/algorithm/equal/?kw=equal
	//?https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	//!#Relational Operators
	template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size()) //test this later
			return (ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
		return (false);
	}
	template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);
		else if (!ft::equal(lhs.begin(),lhs.end(),rhs.begin()))
			return (true);
		return (false);
	}
	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
	}
	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return(ft::lexicographical_compare(rhs.begin(),rhs.end(),lhs.begin(),lhs.end()));
	}
	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs == rhs || lhs > rhs)
			return (true);
		return (false);
	}
	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs == rhs || lhs < rhs)
			return (true);
		return (false);
	}
	template <class T, class Alloc>
  	void swap (const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}
