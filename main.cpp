#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{
	// ft::vector<int> abc;
	// ft::vector<int> abc(1);
	int data[5] = {1, 3, 4, 5,6};
	ft::iterator<int> it(data);

	
	std::cout << *it << std::endl;





}