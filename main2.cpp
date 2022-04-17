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


	//ft::map<int, int> m;
	//m[0] = 1;
	//ft::map<int, int>::iterator it = m.begin();
	//ft::map<int, int>::const_iterator cit = m.end();

	//if (it == cit)
	//	std::cout << "BRRR" << std::endl;

	std::vector<int> m;
	//m[0] = true;
	std::vector<int>::iterator it = m.begin();

	std::cout << *it << std::endl;


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