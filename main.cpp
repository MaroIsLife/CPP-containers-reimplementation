#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include <memory>
#include <map>
#include "map.hpp"
#define TIME_FAC 5
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include <random>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))


time_t get_time(void)
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
	return (msecs_time);
}

template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		if (first1->first != first2->first || first1->second != first2->second)
			return false;
	return true;
}

//! Implement istream iterator with insert range and assign range
int main()
{


//! Find a way to swap min node with current node in delete with both children (CONST PROBLEM)
	  







bool cond(false);
		// erasing all the elements in the map;
		//{
		//    time_t start, end, diff;
		//    /*------------------ std::maps ---------------------*/
		//    std::map<int, std::string> m1;
		//    ft::map<int, std::string> ft_m1;
		//    for (size_t i = 0; i < 1e6; i++)
		//    {
		//        m1.insert(std::make_pair(i, "string2"));
		//        ft_m1.insert(ft::make_pair(i, "string2"));
		//    }

		//    start = get_time();
		//    m1.erase(m1.begin(), m1.end());
		//    end = get_time();
		//    diff = end - start;
		//    diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
		//    /*-----------------------------------------------------*/
		//    /*------------------ ft::maps ---------------------*/
		//    ualarm(diff * 1e3, 0);
		//    ft_m1.erase(ft_m1.begin(), ft_m1.end());
		//    ualarm(0, 0);
		//    /*----------------------------------------------------*/
		//}
		std::map<char, int> m;
		ft::map<char, int> ft_m;
		std::map<char, int>::iterator it;
		ft::map<char, int>::iterator ft_it;

		cond = 1;
		std::map<int, std::string> m3;
		ft::map<int, std::string> ft_m3;
		std::vector<int> vec;
		std::vector<int> ft_vec;
		std::random_device randDev;
		std::mt19937 generator(randDev());
		std::uniform_int_distribution<int> distr(0, 1e8);

		for (size_t i = 0; i < 1e6; i++)
		{
			m3.insert(std::make_pair(i, "string1"));
			ft_m3.insert(ft::make_pair(i, "string1"));
		}

	
		for (size_t i = 0; i < 1e6; ++i)
		{
			int n = distr(generator);
			int ret1 = m3.erase(n);
			int ret2 = ft_m3.erase(n);


			if (ret1 != ret2)
			{
				std::cout << "ret1 != ret2" << std::endl;
				cond = false;
				break;
			}
		}
			std::cout << "m3 size = " << m3.size() << std::endl;
			std::cout << "ft_m3 size = " << ft_m3.size() << std::endl;
		if (!m3.empty())
		{
			m3.erase(m3.begin(), m3.end());
			m3.erase(m3.begin(), m3.end());
		}
		if (!ft_m3.empty())
		{
			//std::cout << "made ithere" << std::endl;
			ft_m3.erase(ft_m3.begin(), ft_m3.end());
			ft_m3.erase(ft_m3.begin(), ft_m3.end());
		}
		cond = cond && (m3.size() == ft_m3.size() && comparemaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()));
		std::cout << "m3 size " << m3.size() << std::endl;
		std::cout << "ft_m3 size " << ft_m3.size() << std::endl;

		EQUAL(cond);

	//! Problem in DELETENODE AVL FUNCTION???















	//tmp = m._node.searchNode(m._node.root, 30);

	//tmp = m._node.root;
	//std::cout << tmp->parent->data.first << std::endl;
	//std::cout << "it->first = " << it->first << std::endl;
	//m.erase(4);

	//std::cout << m[4] << std::endl;

	//it = m.begin();
	//it++;
	//it++;
	//it--;
	//std::cout << it->first << std::endl;

	//it = m._node.searchNode(m._node.root, 3);
	//it++;
	//std::cout << it->first << std::endl;

	



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