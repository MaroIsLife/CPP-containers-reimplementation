#pragma once

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct map_base_iterator 
	{
		public:
			//typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category 	iterator_category;
	};

	template <typename T, typename V>
	class map_iterator : public ft::map_base_iterator<std::bidirectional_iterator_tag, T> 
	{	
	public:
	typedef T Node;
	typedef V value_type;
	typedef value_type& reference;
	typedef value_type* pointer;
	typedef ptrdiff_t difference_type;
	typedef map_iterator<T, const V> const_map_iterator;
	typedef std::bidirectional_iterator_tag iterator_category;

	map_iterator() : ptr(NULL), root(NULL) {}

	map_iterator(T* ptr) : ptr(ptr), root(ptr) {}


	map_iterator(T* ptr, T* root) : ptr(ptr), root(root) {}
	

	map_iterator(const map_iterator& it) : ptr(it.ptr), root(it.root) {}

	~map_iterator(){}

	operator const_map_iterator() //Explicit conversion to const iterator
	{
		return const_map_iterator(ptr, root);
	} 

	map_iterator& operator=(const map_iterator& it)
	{
		ptr = it.ptr;
		root = it.root;
		return (*this);
	}


	map_iterator& operator++()
	{
		if (ptr->right)
		{
			ptr = ptr->right;
			while (ptr->left)
				ptr = ptr->left;
		}
		else
		{
			Node *tmp = ptr->parent;
			while (tmp && tmp->right == ptr)
			{
				ptr = tmp;
				tmp = tmp->parent;
			}
			ptr = tmp;
		}
		//ptr = ptr->inorderSuccessor(ptr);
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
		if (!ptr && root)
			ptr = root->findLargest(root);
		else
			ptr = ptr->parent;
		return (*this);
	}
	map_iterator operator--(int)
	{
		map_iterator tmp(*this);
		if (!ptr && root)
			ptr = root->findLargest(root);
		else
			--(*this);
		return (tmp);
	}

	value_type& operator*() const
	{
		return (ptr->data);
	}

	value_type* operator->() const
	{
		return (&operator*());
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
	Node *ptr;
	Node *root;
};

}

