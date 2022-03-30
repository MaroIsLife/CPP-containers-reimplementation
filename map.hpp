#pragma once

#include <iostream>
#include "utility.hpp"
#include <functional>
#include "avl.hpp"
#include "map_iterator.hpp"
namespace ft
{
	//* Less(Sorting Map Less or Greater than) https://www.cplusplus.com/reference/functional/less/

	template < class Key,                                     
           class T,                                       
           class Compare = std::less<Key>,                     
           class Alloc = std::allocator<pair<const Key,T> >    
           >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef typename ft::map_iterator<value_type> iterator;
			typedef typename Avl<value_type>::Node Node;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;


			//? https://www.cplusplus.com/reference/map/map/value_comp/
			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			};
			
			//*Empty Constructor
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp)
			{
				this->_comp = comp;
				this->_allocator = alloc;
				_size = 0;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				this->comp = comp;
				this->alloc = alloc;
				for (; first != last; ++first)
					insert(*first);
			}

			map (const map& x)
			{
				this->comp = x.comp;
				this->alloc = x.alloc;
				this->root = x.root;
				this->size = x.size;
			}

			~map()
			{
				//clear();
			}

			map& operator= (const map& x)
			{
				if (this != &x)
				{
					//clear();
					this->comp = x.comp;
					this->alloc = x.alloc;
					this->root = x.root;
					this->size = x.size;
				}
			}
			bool empty() const
			{
				return (_size);
			}
			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (_allocator.max_size());
			}

			iterator begin()
			{
				return (iterator(_node.findSmallest(_node.root)));
			}

			pair<iterator,bool> insert (const value_type& val) 
			{
				Node *r = _node.insertNode(_node.root, val);
				if (!r)
					return (make_pair(iterator(&r->data), false));
				else
					return (make_pair(iterator(&r->data), true));
			}
			
		private:
			size_type _size;
			value_compare _comp;
			allocator_type _allocator;
			Avl<value_type> _node;
	};
}



