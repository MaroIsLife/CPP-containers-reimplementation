#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <memory>

int main()
{	

	int data[5] = {1, 3, 4, 5,6};
	int data2[5] = {3, 18, 4, 5,6};
	ft::vector<int>::iterator it(data);
	ft::vector<int>::iterator it2(data2);

	
	if (it < it2)
		std::cout << "True" << std::endl;


}