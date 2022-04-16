#include "vector.hpp"
#include <vector>
#include <iostream>
#include "stack.hpp"
#include "map.hpp"
#include <set>
#include <map>

#include <memory>



int main()
{
	//std::set<std::string> s;

	//s.insert("hello");
	//std::cout << *(s.find("hello")) << std::endl;


	ft::map<int, int> m;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::const_iterator cit;

	if (it == cit)
		std::cout << "BRRR" << std::endl;

	m[1] = 2;
	m[2] = 3;
	m[3] = 4;
	m[4] = 5;
	m[5] = 6;
	m[6] = 7;
	m[7] = 8;
	m[8] = 9;
	m[9] = 10;

	m.erase(m.begin(), m.end());

	//std::cout << m._node.root->left->data.first << std::cout << std::endl;
	//std::cout << m._node.find(m._node.root, 4)->data.first << std::cout << std::endl;
	//std::cout << m.find(18)->first << std::endl;

	//for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	std::cout << it->first << std::endl;
	//}
	//std::cout << m.size() << std::endl;

	return (0);
}