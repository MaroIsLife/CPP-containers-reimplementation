#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include <memory>
#include <map>
#include "map.hpp"
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))



template <class T>
int compare(T const &x, T const &y)
{
	if (std::less<T>())
	{
		std::cout << "Yes" << std::endl;
	}
	return (0);
}

//! Implement istream iterator with insert range and assign range
int main()
{

	ft::map<int, int> m;
	ft::map<int, int>::iterator it;
	ft::pair<ft::map<int, int>::iterator, bool> ret;


	ret = m.insert(ft::make_pair(1, 2));
	ret = m.insert(ft::make_pair(2, 2));
	//it = ret.first;
	it = m.begin();
	it++;
	std::cout << it->first << std::endl;

	



	//it = m.begin();

	

	
	//std::cout << test.getLeftHeight(test.root) << std::endl;
	//std::cout << test.getRightHeight(test.root) << std::endl;
	//std::cout << test.getBalance(test.root) << std::endl;

	//ft::map<int,int> test;

	


	//std::cout << ab() << std::endl;

	//std::cout << test.getLeftHeight(test.root) << std::endl;

	//! Use geeksforgeeks avl
	//test.searchNode(test.root, 10);
	//std::cout << test.getHeight(test.root) << std::endl;
	//std::cout << test.getBalance(test.root) << std::endl;
	//test.root->left = new Node<int>(13);
	//test.insertNode(test.root, 3);
	//test.insertNode(test.root, 10);
	//test.insertNode(test.root, 6);



	//std::cout << ab->data << std::endl;
	//std::cout << std::string::npos << std::endl;
    // std::map<std::string, int> m;
	// std::map<std::string, int>::iterator it;

	// for(int i = 0; i < 10; i++)
	// {
	// 	m[std::to_string(i)] = i;
	// }

	// std::cout << m["5"] << std::endl;
	// system("leaks a.out");
}

//*Iterator Operators
//https://docs.microsostd.com/en-us/cpp/standard-library/iterator-operators?view=msvc-170

//*ptrdiff_t
//https://stackoverflow.com/questions/4377308/c-size-t-or-ptrdiff-t

//*Red Black Tree
//http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap14.htm

//*AVL trees
//https://www.youtube.com/watch?v=-9sHvAnLN_w

//*Const Correctness 
//https://isocpp.org/wiki/faq/const-correctness#overview-const

//*Istream iterator
//https://www.cplusplus.com/reference/iterator/istream_iterator/

//*Destroy vs Deallocate
//https://stackoverflow.com/questions/26667026/difference-between-destroy-destructor-deallocate-in-stdallocator

//*Introduction to trees
//https://www.programiz.com/dsa/trees
//https://www.softwaretestinghelp.com/trees-in-cpp/

//*Avl
//https://www.guru99.com/avl-tree.html (very good to understand rotations)
//https://simplesnippets.tech/what-is-avl-tree-data-structure-all-avl-operations-with-full-code/ (Very Good)
//https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/
//https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
//https://www.softwaretestinghelp.com/avl-trees-and-heap-data-structure-in-cpp/
//https://www.geeksforgeeks.org/avl-trees-containing-a-parent-node-pointer/

//*Avl (Vids)
//https://www.youtube.com/watch?v=vRwi_UcZGjU
//https://www.youtube.com/watch?v=otiDcwZbCo4
//https://www.youtube.com/watch?v=u3OVSkuOdqI (Very Good)
//https://www.youtube.com/watch?v=otiDcwZbCo4

//*Avl Visualizer
//https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

//* Avl Traversal
//https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
//https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/

//* Rebind
//https://stackoverflow.com/questions/22384231/is-use-of-allocatorrebind-required-by-c-standard