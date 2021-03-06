#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <stdlib.h>
#include <string>
#include <deque>
#include <sys/time.h>
#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

long get_time()
{
	struct timeval	time;
	long long		t;
	gettimeofday(&time, NULL);
	t = (time.tv_usec) + (time.tv_sec * 1000000);
	return t;
}

int main() 
{

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;
	std::cout << "============================ start test vector =====================================" << std::endl;
	{
		long start = get_time();
		for(int i = 0; i < 1e6; i++)
		{
			vector_int.push_back(i);
		}
		long now = get_time() - start;
		std::cout << "time vector === > " << now / 1e6 << std::endl;
		std::cout << "vector int size ==> " << vector_int.size() << " vector int capacity " << vector_int.capacity() << std::endl;
	}
	{
		for (int i = 0; i < COUNT; i++)
		{
			vector_buffer.push_back(Buffer());
		}

		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer[idx].idx = 5;
		}
		ft::vector<Buffer>().swap(vector_buffer);
	}
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			std::cout << idx << std::endl;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "error is ===> " << e.what() << std::endl;
	}
	
	std::cout << "============================ start test map =====================================" << std::endl; 
	ft::map<int, int> new_map;
	long start = get_time();
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}
	long now = get_time() - start;
	std::cout << "time map === > " << now / 1e6 << std::endl;
	std::cout << "map size ==> " << map_int.size() << std::endl;
	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	ft::map<int, int>::iterator it = map_int.begin();
	std::cout << "size before swap ==> " << map_int.size() << " map min value " << it->first << std::endl;
	std::cout << "swap  map " << std::endl;
	new_map.swap(map_int);
	ft::map<int, int>::iterator it2 = new_map.begin();
	std::cout << "size after swap ==> " << map_int.size() << std::endl;
	std::cout << "new map size ==> " << new_map.size() << "  new map min value " << it2->first <<  std::endl;
	{
		ft::map<int, int> copy = map_int;
	}

	std::cout << "============================ start test stack =====================================" << std::endl; 
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it << "\n";
	}
	std::cout << "stack size ==> " << iterable_stack.size() << std::endl;
	std::cout << std::endl;
	return (0);
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
