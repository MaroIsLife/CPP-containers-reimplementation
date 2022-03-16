#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include <memory>
#include <map>
#include "avl.hpp"
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))



//! Implement istream iterator with insert range and assign range
int main()
{

	//Avl<int> test(10);

	
	//std::cout << test.getLeftHeight(test.root) << std::endl;
	//std::cout << test.getRightHeight(test.root) << std::endl;
	//std::cout << test.getBalance(test.root) << std::endl;

	Avl<int> test;

	test.insertNode(test.root, 30);
	test.insertNode(test.root, 20);
	test.insertNode(test.root, 2);
	test.insertNode(test.root, 3);
	test.insertNode(test.root, 1);

	test.deleteNode(test.root, 2);

	//std::cout << test.getLeftHeight(test.root) << std::endl;

	test.searchNode(test.root, 3);

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
//https://www.guru99.com/avl-tree.html (very good)
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
