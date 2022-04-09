#pragma once

#include <iostream>
#include "utility.hpp"
#include <functional>
#include "avl.hpp"
#include "map_iterator.hpp"
#include "algorithm.hpp"
#include "reverse_iterator.hpp"
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
			typedef typename Avl<value_type>::Node Node;
			typedef typename ft::map_iterator<Node, value_type> iterator;
			typedef typename ft::map_iterator<Node, const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
				(void)alloc;
				_size = 0;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp)
			{
				(void)alloc;
				_size = 0;
				//for (; first != last; ++first)
				//	this->insert(*first);
				insert(first, last);
			}

			map (const map& x) : _comp(x._comp)
			{
				this->_allocator = x._allocator;
				this->_node = x._node;
				this->_size = x._size;
			}

			~map()
			{
				//clear();
			}

			map& operator= (const map& x)
			{
				if (this != &x)
				{
					clear();
					this->_comp = x._comp;
					this->_allocator = x._allocator;
					this->_node = x._node;
					this->_size = x._size;
				}
				return (*this);
			}

			bool empty() const
			{
				return (_size == 0);
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
				return (iterator(_node.findSmallest(_node.root), _node.root));
			}

			const_iterator begin() const
			{
				return (const_iterator(_node.findSmallest(_node.root), _node.root));
			}

			iterator end()
			{
				return (iterator(NULL, _node.root));
			}

			const_iterator end() const
			{
				return (const_iterator(NULL, _node.root));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			mapped_type& operator[] (const key_type& k)
			{
				
				Node *tmp = _node.searchNode(_node.root, k);
				if (tmp)
					return (tmp->data.second);
				else
				{
					insert(ft::make_pair(k, mapped_type()));
					//if (k == 47)
					//	std::cout << "Made it here\n";
					//std::cout << _node.root->data.first << std::endl;
					//std::cout << "Mapped " << _node.searchNode(_node.root, k) << std::endl;
					//return (_node.searchNode(_node.root, k)->data.second);
					int *a = new int(12);
					return (*a);
				}
			}
		
			iterator find (const key_type& k)
			{
				return (iterator(_node.searchNode(_node.root, k),_node.root));
			}
			const_iterator find(const key_type& k) const
			{
				return (const_iterator(_node.searchNode(_node.root, k),_node.root));
			}

			//pair<iterator, bool> insert (const value_type& val) 
			//{
			//	_size++;
			//	Node *n = _node.insertNode(_node.root, val, _node.root);
			//	Node *r = _node.searchNode(_node.root, val.first);
			//	std::cout << &r->parent << std::endl;	
			//	if (!n)
			//		return (make_pair(iterator(&r->data), false));
			//	else
			//		return (make_pair(iterator(&r->data), true));
			//}

			pair<iterator, bool> insert(const value_type& val) 	//* Insert node always get the root address (cuz recursive) so i used search node
			{
				_size++; 
				if (!(_node.insertNode(_node.root, val, NULL)))
					return (ft::make_pair(iterator((_node.searchNode(_node.root, val.first)), _node.root), false));
				else
					return (ft::make_pair(iterator((_node.searchNode(_node.root, val.first)), _node.root), true));
			}

	

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				_size++;
				if (!(_node.insertNode(_node.root, val, NULL)))
					return (iterator(_node.searchNode(_node.root, val.first), _node.root));
				else
					return (iterator(_node.searchNode(_node.root, val.first), _node.root));
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				for (; first != last; ++first)
					this->insert(*first);	
			}

			size_type count (const key_type& k) const
			{
				size_type count = 0;
				_node.count_key(_node.root, k, count); //* Count will always be either 1 or 0 hint key fl map is unique
				return (count);
			}
			
			void clear()
			{
				_node.destroyAllNodes(_node.root);
				_size = 0;
			}

			void swap (map& x)
			{
				std::swap(this->_comp, x._comp);
				std::swap(this->_allocator, x._allocator);
				std::swap(this->_node, x._node);
				std::swap(this->_size, x._size);
			}
			
			void erase (iterator position)
			{
				_node.deleteNode(_node.root, position->first);
				_size--;
			}

			size_type erase (const key_type& k)
			{
				size_type count = 0;
				Node *tmp = _node.searchNode(_node.root, k);
				if (!(empty()) && tmp)
				{
					_node.deleteNode(_node.root, k);
					_size--;
					count++;
				}
				return (count);
			}
			void erase (iterator first, iterator last)
			{
				for (; first != last; first++)
					erase(first);
			}

			key_compare key_comp() const
			{
				key_compare _key_comp;
				return (_key_comp);
			}

			value_compare value_comp() const
			{
				value_compare _value_comp(key_comp());
				return (_value_comp);
			}

			allocator_type get_allocator() const
			{
				return (_allocator);
			}
			iterator lower_bound (const key_type& k)
			{
				iterator it = begin();
				iterator end = this->end();
				--end;
				if (k > end->first)
					return (iterator());
				end = this->end();
				while (it != end)
				{
					if (it->first >= k)
						return (it);
					it++;
				}
				return (it);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();
				const_iterator end = this->end();
				--end;
				if (k > end->first)
					return (const_iterator());
				end = this->end();
				while (it != end)
				{
					if (it->first >= k)
						return (it);
					it++;
				}
				return (it);
			}

			iterator upper_bound(const key_type& k)
			{
				iterator it = begin();
				iterator end = this->end();
				--end;
				if (k > end->first)
					return (iterator());
				end = this->end();
				while (it != end)
				{
					if (it->first > k)
						return (it);
					else if (it->first == k)
						return (++it);
					it++;
				}
				return (it);
			}

			const_iterator upper_bound(const key_type& k) const
			{
				const_iterator it = begin();
				const_iterator end = this->end();
				--end;
				if (k > end->first)
					return (const_iterator());
				end = this->end();
				while (it != end)
				{
					if (it->first > k)
						return (it);
					else if (it->first == k)
						return (++it);
					it++;
				}
				return (it);
			}

			pair<iterator,iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
				
			Avl<value_type> _node;
		private:
			size_type _size;
			allocator_type _allocator;
			value_compare _comp;
	};

	template <class Key, class T, class Compare, class Alloc>
  	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
  	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
  	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{

		return (!(rhs < lhs));
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
 	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
 	{
		 x.swap(y);
 	}
}

