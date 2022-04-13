/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:45:42 by nwakour           #+#    #+#             */
/*   Updated: 2022/03/22 18:46:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
//#include "iterator.hpp"
#include "vector.hpp"
#include "utility.hpp"
// #include "rb_tree.hpp"
#include <memory>
#include <set>

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		// std::cout << "constuct " << i << "\n";
		this->l = new char('a');
	};
	virtual ~B() {
		// std::cout << "destroy " << i << "\n";
		delete this->l;
		this->l = nullptr;
	};
	B (const B& x)
	{
		this->i = x.i;
		this->l = new char('a');
		// std::cout << "copy " << i << "\n";
	}
	B &operator=(const B& copy)
	{
		this->i = copy.i;
		this->l = new char('a');
		// std::cout << "assignement " << i << "\n";
		return (*this);
	}
};

// class A : public B {
// public:
// 	A():B(){};
// 	A(const B* ex){
// 		this->l = new char(*(ex->l));
// 		this->i = ex->i;
// 		if (ex->i == -1) throw "n";
// 	}
// 	~A() {
// 		// delete this->l;
// 		this->l = nullptr;
// 	};
// };

int main()
{
	std::vector<B> vv;
	B cp(15);
	for (size_t i = 0; i < 10; ++i)
	{
		vv.push_back(B(i + 10));
	}
	
	//for (size_t size = 0; size < 10; ++size)
	//{
	//	for (size_t diff = 0; diff < size; ++diff)
	//	{
	//		for (size_t n = 0; n < vv.size(); ++n)
	//		{
	//			for (size_t nn = 0; nn < vv.size(); ++nn)
	//			{
	//				if (n >= nn)
	//					continue;
	//				for (size_t cap = 0; cap < 10; ++cap)
	//				{
	//					std::vector<B> v1;
	//					v1.reserve(cap);
	//					for (size_t i = 0; i < size; ++i)
	//					{
	//						v1.push_back(B(i));
	//					}
	//					v1.insert(v1.begin() + diff, vv.begin() + n, vv.begin() + nn);
	//					ft::vector<B> v2;
	//					v2.reserve(cap);
	//					for (size_t i = 0; i < size; ++i)
	//					{
	//						v2.push_back(B(i));
	//					}
	//					v2.insert(v2.begin() + diff, vv.begin() + n, vv.begin() + nn);
	//					if (v1.size() != v2.size() || v1.capacity() != v2.capacity())
	//					{
	//						std::cout << "cap/size" << std::endl;
	//						std::cout << cap << " "<< size << " " << diff << " " << n << " " << nn << std::endl;
	//						return (0);
	//					}
	//					for (size_t i = 0; i < v1.size(); i++)
	//					{
	//						if (v1[i].i != v2[i].i)
	//						{
	//							std::cout << cap << " "<< size << " " << diff << " " << n << " " << nn << std::endl;
	//							return (0);
	//						}	
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	//for (size_t size = 0; size < 10; ++size)
	//{
	//	for (size_t diff = 0; diff < size; ++diff)
	//	{
	//		for (size_t n = 0; n < 10; ++n)
	//		{
	//				for (size_t cap = 0; cap < 10; ++cap)
	//				{
	//					std::vector<B> v1;
	//					v1.reserve(cap);
	//					for (size_t i = 0; i < size; ++i)
	//					{
	//						v1.push_back(B(i));
	//					}
	//					v1.insert(v1.begin() + diff, n, cp);
	//					ft::vector<B> v2;
	//					v2.reserve(cap);
	//					for (size_t i = 0; i < size; ++i)
	//					{
	//						v2.push_back(B(i));
	//					}
	//					std::cout << cap << " "<< size << " " << diff << " " << n << std::endl;
	//					v2.insert(v2.begin() + diff, n, cp);
	//					//if (v1.size() != v2.size() || v1.capacity() != v2.capacity())
	//					//{
	//					//	std::cout << "cap/size" << std::endl;
	//					//	std::cout << cap << " "<< size << " " << diff << " " << n  << std::endl;
	//					//	return (0);
	//					//}
	//					for (size_t i = 0; i < v1.size(); i++)
	//					{
	//						if (v1[i].i != v2[i].i)
	//						{
	//							std::cout << cap << " "<< size << " " << diff << " " << n << std::endl;
	//							return (0);
	//						}
							
	//					}
	//				}
	//		}
	//	}
	//}
	
	//for (size_t size = 0; size < 10; ++size)
	//{
	//	for (size_t diff = 0; diff < size; ++diff)
	//	{
	//				for (size_t cap = 0; cap < 10; ++cap)
	//				{
	//					std::vector<B> v1;
	//					v1.reserve(cap);
	//					for (size_t i = 0; i < size; ++i)
	//					{
	//						v1.push_back(B(i));
	//					}
	//					v1.insert(v1.begin() + diff, cp);
	//					ft::vector<B> v2;
	//					v2.reserve(cap);
	//					for (size_t i = 0; i < size; ++i)
	//					{
	//						v2.push_back(B(i));
	//					}
	//					v2.insert(v2.begin() + diff, cp);
	//					if (v1.size() != v2.size() || v1.capacity() != v2.capacity())
	//					{
	//						std::cout << "cap/size" << std::endl;
	//						std::cout << cap << " "<< size << " " << diff << " "  << std::endl;
	//						return (0);
	//					}
	//					for (size_t i = 0; i < v1.size(); i++)
	//					{
	//						if (v1[i].i != v2[i].i)
	//						{
	//							std::cout << cap << " "<< size << " " << diff << " " << std::endl;
	//							return (0);
	//						}
							
	//					}
	//				}
	//	}
	//}
	 std::vector<B> v1;
	// v1.reserve(30);
	 for (size_t i = 0; i < 1; ++i)
	 {
	 	v1.push_back(B(i+1));
	 }
	 std::cout << "************" << std::endl;


	 v1.insert(v1.begin(), 1, cp);
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	 std::cout << "************" << std::endl;
	 for (size_t i = 0; i < v1.size(); ++i)
	 {
	 	std::cout << v1[i].i << " ";
		
	 }
	 std::cout << "\n";
	return(0);
}
