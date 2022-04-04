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

	template <typename T>
	class map_iterator : public ft::map_base_iterator<std::bidirectional_iterator_tag, T> 
	{	
	public:
	typedef T Node;
	typedef typename T::value_type value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef ptrdiff_t difference_type;

	map_iterator() : ptr(NULL), root(NULL)
	{

	}
	map_iterator(T* ptr, T* root) : ptr(ptr), root(root)
	{

	}

	map_iterator(const map_iterator& it) : ptr(it.ptr), root(it.root)
	{

	}

	
	map_iterator& operator++()
	{
		ptr = ptr->inorderSuccessor(ptr);
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
		//std::cout << "root " << root->data.first << std::endl;
		//std::cout << "ptr " << ptr << std::endl;
		map_iterator tmp(*this);
		if (!ptr && root)
		{
			ptr = root->findLargest(root);
		}
		else
			--(*this);
		return (tmp);
	}
	value_type& operator*()
	{
		return (ptr->data);
	}
	value_type* operator->() const
	{
		return (&ptr->data);
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

