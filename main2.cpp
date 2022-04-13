#include "vector.hpp"
#include <vector>
#include <iostream>
#include "stack.hpp"
#include "map.hpp"
#include <set>
#include <map>

#include <memory>

int search(std::vector<int>& nums, int target) 
{
        
        int high = nums.size();
        int low = 0;
        int mid;
        while (low < high)
        {
			mid = (low + high) / 2;
            if (mid == target)
				return (mid);
			if (target > mid)
				low = mid + 1;
			if (target < mid)
				high = mid - 1;	
        }
        return (-1);
}

int main()
{
	//std::set<std::string> s;

	//s.insert("hello");
	//std::cout << *(s.find("hello")) << std::endl;


	ft::map<int, int> m;

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
	std::cout << m.size() << std::endl;

	return (0);
}