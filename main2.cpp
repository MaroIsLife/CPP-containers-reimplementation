#include "vector.hpp"
#include <vector>
#include <iostream>
#include "stack.hpp"
#include <set>

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
	std::set<std::string> s;

	s.insert("hello");
	std::cout << *(s.find("hello")) << std::endl;

	return (0);
}