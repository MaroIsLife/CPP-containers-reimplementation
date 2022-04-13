#pragma once

#include <iostream>

#include "map.hpp"
//?Difference between Binary Tree, Binary Search Tree and AVL Tree
//* Binary tree is a tree data structure in which each node has at most two children (It has no rules)
//* Binary Search Tree is a Binary tree in which the value of each node is greater than or equal to the value of the node to its left and less than or equal to the value of the node to its right.
//* AVL Tree Is a BT and a Binary Search Tree but it is balanced, It is a self-balancing Binary Search Tree, We use Rotations to balance the tree.

//?Nodes
//* Small nodes goes to the left, large or equal nodes goes to the right
//* Leaf Node = a Node with no children

//?Heights
//* Height of each tree path,   Root node = 0
//* No Node = Height = -1
//* Single node = Height = 0 (many AVLs count Root node as 1 height)
//* Two nodes = Height = 1
//* Three nodes = Height = 2...
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot3.png

//?Balance factor
//* The balance factor is known as the difference between the height of the left subtree and the right subtree. (How many nodes are in each Path)
//! Balance Factor(n) = H(left subtree) - H(right subtree)
//* Allowed values of BF are –1, 0, and +1, any values other than these are not allowed (Unbalanced tree)
//* If the balance factor is 0, it means that the left and right subtrees are of equal height
//* If the balance factor is -1, it means that the right subtree is taller than the left subtree
//* If the balance factor is +1, it means that the left subtree is taller than the right subtree
//* If the balance factor is +2, it means that the left subtree is 2 levels higher than the right subtree
//* If the balance factor is -2, it means that the right subtree is 2 levels higher than the left subtree

//?Rotations
//* To make the AVL Tree balance itself, when inserting or deleting a node from the tree, rotations are performed
//* There are four types of rotations: Left-Left, Left-Right, Right-Right, and Right-Left
//!https://www.youtube.com/watch?v=u3OVSkuOdqI

//?Left-Left
//* The left-left rotation is performed when the balance factor of the node is −2
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot4.png

//?Right-Right
//* The right-right rotation is performed when the balance factor of the node is +2  
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot5.png

//?Right-Left
//* The right-left rotation is performed when the balance factor of the node is −1
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot6.png

//?Left-Right
//* The left-right rotation is performed when the balance factor of the node is +1
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot7.png

//?Insertion
//* Insert operation is almost the same as in simple binary search trees.
//* After every insertion we balance the height of the tree. Insert operation takes O(log n) worst time complexity.

//*Step 1: Insert the new node in the tree (Using the same insertion algorithm as in BST)
//*Step 2: Once the node is added the balance factor of each node is updated (The balance factor of every node is updated)
//*Step 3: Now  check if any node violates the Balance factor

//* If BF(node) = +2 and BF(node -> left-child) = +1, perform LL rotation.
//* If BF(node) = -2 and BF(node -> right-child) = 1, perform RR rotation.
//* If BF(node) = -2 and BF(node -> right-child) = +1, perform RL rotation.
//* If BF(node) = +2 and BF(node -> left-child) = -1, perform LR rotation.
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot8.png

//? Deletion
//* Deletion is almost the same as in simple binary search trees.

//*Step 1: Find the element in the tree
//*Step 2: If the element is found, delete the element
//*Step 3: Once the element is deleted, balance the height of the tree

//* There are two cases for deletion:

//* Case 1 deleting from the right subtree:
//* 1A If BF(node) = +2 and BF(node -> left-child) = +1, perform LL rotation.
//* 1B If BF(node) = +2 and BF(node -> left-child) = -1, perform LR rotation.
//* 1C If BF(node) = +2 and BF(node -> left-child) = 0, perform LL rotation.
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot9.png


//* Case 2 deleting from the left subtree:
//* 2A If BF(node) = -2 and BF(node -> right-child) = -1, perform RR rotation.
//* 2B If BF(node) = -2 and BF(node -> right-child) = +1, perform RL rotation.
//* 2C If BF(node) = -2 and BF(node -> right-child) = 0, perform RR rotation.
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot10.jpg

//? Predecessor of a node
//* Predecessors can be described as the node that would come right before the node you are currently at.
//* To find the predecessor of the current node, look at the right-most/largest leaf node in the left subtree.

//? Successor of a Node
//* Successors can be described as the node that would come right after the the current node.
//* To find the successor of the current node, look at the left-most/smallest leaf node in the right subtree.

template <typename T>
class Node 
{
	public:
		typedef T value_type;
		typedef const T const_value_type;
		value_type data;
		int height;
		Node *right;
		Node *left;
		Node *parent;

		Node() : data(0), height(1), right(NULL), left(NULL), parent(NULL)
		{
			
		}

		Node(T n) : data(n), height(1), right(NULL), left(NULL), parent(NULL)
		{
			
		}

		Node(value_type data,
		int height,
		Node *right,
		Node *left,
		Node *parent) : data(data), height(height), right(right), left(left), parent(parent)
		{
			
		}
		

		operator const_value_type() //Explicit conversion to const iterator
		{	
			return const_value_type();
		} 

		Node *inorderSuccessor(Node *r)
		{
			if (!r)
				return (r);
			else
			{
				if (r->right)
				{
					r = r->right;
					while (r->left)
						r = r->left;
				}
				else
				{
					Node *p = r->parent;
					while (p && r == p->right)
					{
						r = p;
						p = p->parent;
					}
					r = p;
				}
			}
			return (r);
		}

		const Node *inorderSuccessor(const Node *r) const
		{
			if (!r)
				return (r);
			else
			{
				if (r->right)
				{
					r = r->right;
					while (r->left)
						r = r->left;
				}
				else
				{
					const Node *p = r->parent;
					while (p && r == p->right)
					{
						r = p;
						p = p->parent;
					}
					r = p;
				}
			}
			return (r);
		}

		Node *inorderPredecessor(Node *r)
		{
			if (!r)
				return (r);
			else
			{
				if (r->left)
				{
					r = r->left;
					while (r->right)
						r = r->right;
				}
				else
				{
					Node *p = r->parent;
					while (p && r == p->left)
					{
						r = p;
						p = p->parent;
					}
					r = p;
				}
			}
			return (r);
		}

		Node *findSmallest(Node *r)
		{
			if (!r->left)
				return (r);
			return (findSmallest(r->left));
		}

		Node *findLargest(Node *r)
		{
			if (!r->right)
				return (r);
			return (findLargest(r->right));
		}

		const Node *findSmallest(const Node *r) const
		{
			if (!r->left)
				return (r);
			return (findSmallest(r->left));
		}

		const Node *findLargest(const Node *r) const
		{
			if (!r->right)
				return (r);
			return (findLargest(r->right));
		}

	Node *inorder_succ(Node *r)
	{
		while (!r->left)
			r = r->left;
		return r;
	}
};

template <typename T, typename comp>
class Avl
{
	public:
		typedef T value_type;
		typedef Node<value_type> Node;
		Node *root;
		comp comp_;
		bool deleted;
		typedef typename value_type::first_type key_type;
		typedef typename value_type::second_type mapped_type;
		typedef std::allocator<ft::pair<const key_type, mapped_type> > Alloc;
		typedef typename Alloc::template rebind<Node>::other  alloc_type;
		alloc_type alloc;

		Avl()
		{
			root = NULL;
		}

		Avl(T n)
		{
			//root = new Node(n);
			root = alloc.allocate(1);
			alloc.construct(root, Node(n));
		}

		~Avl()
		{
			//destroyAllNodes(root);

		}

		void destroyAllNodes(Node *r)
		{
			if (!r)
				return ;
				destroyAllNodes(r->left);
				destroyAllNodes(r->right);
				//delete r;
				//alloc.destroy(r);
				alloc.deallocate(r, 1);
				r = NULL;
		}

		void parent_correction(Node *&n, Node *p)
		{
			if (!n)
				return ;
			parent_correction(n->right, n);
			n->parent = p;
			parent_correction(n->left, n);
		}
		
		int getBalance(Node *r)
		{
			if (!r)
				return (0);
			return (getHeight(r->left) - getHeight(r->right));
		}
		//int getBalance(Node *&r)
		//{
		//	if (r->right && r->left)
		//		return (r->left->height - r->right->height);
		//	else if (!r->right && r->left)
		//		return (r->left->height);
		//	else if (r->right && !r->left)
		//		return -(r->right->height);
		//	return (1);
		//}

		Node *newNode(const value_type &data)
		{
			return (new Node(data));
		}

		Node *searchNode(Node *r, const key_type data)
		{
			if (!r)
				return (NULL);
			if (r->data.first == data)
				return (r);
			if (comp_(data, r->data.first)) // data < r->data.first
				return (searchNode(r->left, data));
			else
				return (searchNode(r->right, data));
			return (r);
		}

		Node *insertNode(Node *&r, const value_type &data, Node *parent) //https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
		{	
			if (!r)
			{
				r = alloc.allocate(1);
				alloc.construct(r, Node(data));
				r->parent = parent;
				//root = getHeadNode(r);
				return (r);
				//return (tmp);
			}
			else if (data.first == r->data.first)
				return (NULL);
			else if (comp_(data.first, r->data.first)) //(data.first < r->data.first) 
			{
				r->left = insertNode(r->left, data, r);
				//tmp = insertNode(r->left, data, r);
			}
			else if (comp_(r->data.first, data.first)) //(data.first > r->data.first)
			{
				r->right = insertNode(r->right, data, r);
				//tmp = insertNode(r->right, data, r);

			}
			int bf = getBalance(r);
			r->height = std::max(getHeight(r->left), getHeight(r->right)) + 1;
		
			if (bf > 1 && r->left && comp_(data.first, r->left->data.first))   // data.first < r->left->data.first https://www.softwaretestinghelp.com/avl-trees-and-heap-data.first-structure-in-cpp/
			{
				//std::cout << "Rotate Right" << std::endl;
				r = rotateRight(r);
			}
			else if (bf < -1 && r->right && comp_(r->right->data.first, data.first)) //data.first > r->right->data.first
			{
				//std::cout << "Rotate Left" << std::endl;
				r = rotateLeft(r);
			}
			else if (bf > 1 && r->left && comp_(r->left->data.first, data.first)) // Data.first > r->left->data.first
			{
				//std::cout << "bf " << bf << std::endl;
				//std::cout << "left right\n";
				r->left = rotateLeft(r->left);
				r = rotateRight(r);
			}
			else if (bf < -1 && r->right && comp_(data.first, r->right->data.first)) // data.first < r->right->data.first
			{
				//std::cout << "Right Left\n";
				r->right = rotateRight(r->right);
				r = rotateLeft(r);
			}

			if (r->left)
				r->left->parent = r;
			if (r->right)
				r->right->parent = r;
			return (r);
		}

		Node *deleteNode(Node *&r, const key_type &data) //https://www.geeksforgeeks.org/avl-tree-set-2-deletion/?ref=lbp
		{
			if (!r)
				return (NULL);
			else if (comp_(data, r->data.first)) //Data < r->data.first
				r->left = deleteNode(r->left, data);
			else if (comp_(r->data.first, data)) //Data > r->data.first
				r->right = deleteNode(r->right, data);
			else //* Changed from else if r->first == data to else since it access a deleted node in recursivity which results in a heap use after free 
			{
				if (!r->left && !r->right)
				{
					//delete r;
					alloc.destroy(r);
					alloc.deallocate(r, 1);
					r = NULL;
				}
				else if (!r->left && r->right)
				{
					Node *tmp;

					tmp = r->right;
					
					//delete r;
					alloc.destroy(r);
					alloc.deallocate(r, 1);
					r = tmp;
				}
				else if (!r->right && r->left)
				{
					Node *tmp;

					//std::cout << "MADE IT\n";
					tmp = r->left;

					//std::swap(r->data, tmp->data);
					

					//r->left = tmp->left;
					//r->right = tmp->right;
					//r->height = tmp->height;



					alloc.destroy(r);
					alloc.deallocate(r, 1);
					//r = alloc.allocate(1);
					//alloc.construct(r, Node(tmp->data));
					//r->left = tmp->left;
					//r->right = tmp->right;
					//r->height = tmp->height;

					r = tmp;
				}
				else if (r->right && r->left) //! In BST/AVL Visualization it replaces biggest node and not the smallest one
				{
					//* Find the smallest node in the right subtree and replace r with it. (Inorder Successor)
					Node *tmp = minimumNode(r->right);
					//r->data = tmp->data;
					//alloc.destroy(r);
					//alloc.deallocate(r, 1);
					//r = alloc.allocate(1);
					//alloc.construct(r, Node(tmp->data, tmp->height, tmp->right, tmp->left, tmp->parent));

					
					std::swap(r->data, tmp->data);


					//r->data = ft::make_pair(tmp->data.first, tmp->data.second);
					r->right = deleteNode(r->right, tmp->data.first);
				}
			}
			if (!r)
				return (r);
			r->height = std::max(getHeight(r->left), getHeight(r->right)) + 1;
			int bf = getBalance(r);
			if (bf > 1)
			{
				int bf2 = getBalance(r->left);
				if (bf2 >= 0)
					r = rotateRight(r);
				else
				{
					r->left = rotateLeft(r->left);
					r = rotateRight(r);
				}
			}
			else if (bf < -1)
			{
				int bf2 = getBalance(r->right);
				if (bf2 <= 0)
					r = rotateLeft(r->right);
				else
				{
					r->right = rotateRight(r->right);
					r = rotateLeft(r);
				}
			}
			if (r->left)
				r->left->parent = r;
			if (r->right)
				r->right->parent = r;
			return (r);
		}

		Node *rotateLeft(Node *r) //https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/
		{
			Node *tmp = r->right;
			Node *tmp2 = tmp->left;

			tmp->left = r;
			r->right = tmp2;
			//std::cout << tmp2 << std::endl;

			parent_correction(tmp, r->parent);

			r->height = std::max(getHeight(r->left), getHeight(r->right)) + 1;
			tmp->height = std::max(getHeight(tmp->left), getHeight(tmp->right)) + 1;

			if (tmp->left)
				tmp->left->height = std::max(getHeight(tmp->left->left), getHeight(tmp->left->right)) + 1;
			if (tmp->right)
				tmp->right->height = std::max(getHeight(tmp->right->left), getHeight(tmp->right->right)) + 1;


			//if (tmp->left)
			//	tmp->left->height = fixHeight(tmp->left);
			//if (tmp->right)
			//	tmp->right->height = fixHeight(tmp->right);
			//tmp->height = fixHeight(tmp);

			return (tmp);
		}

	
		Node *rotateRight(Node *r)
		{
			Node *tmp;
			Node *tmp2;
			

			tmp = r->left;
			tmp2 = tmp->right;

			tmp->right = r;
			r->left = tmp2;
			//std::cout << "r left data " << r->left << std::endl;
			parent_correction(r, tmp->parent);


			r->height = std::max(getHeight(r->left), getHeight(r->right)) + 1;
			tmp->height = std::max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
			if (tmp->right)
				tmp->right->height = std::max(getHeight(tmp->right->left), getHeight(tmp->right->right)) + 1;
			if (tmp->left)
				tmp->left->height = std::max(getHeight(tmp->left->left), getHeight(tmp->left->right)) + 1;

			//if (tmp->right)
			//	tmp->right->height = fixHeight(tmp->right);
			//if (tmp->left)
			//	tmp->left->height = fixHeight(tmp->left);
			//tmp->height = fixHeight(tmp);
			return (tmp);
		}

		int getHeight(Node *r)
		{
			if (!r)
				return (0);
			else
				return (r->height);
		}

		 Node *find(Node *r, key_type k) const
        {
            Node *tmp;

            if (r == NULL)
                return (NULL);
            tmp = r;
            if (comp_(r->data.first, k))
                tmp = find(r->right, k);
            else if (comp_(k, r->data.first))
                tmp = find(r->left, k);
            return (tmp);
        }

		Node *minimumNode(Node *r)
		{
			if (!r->left)
				return (r);
			else
				return (minimumNode(r->left));
		}

		Node *findSmallest(Node *r)
		{
			if (!r)
				return (r);
			else if (!r->left)
				return (r);
			return (findSmallest(r->left));
		}

		Node *findLargest(Node *r)
		{
			if (!r)
				return (r);
			else if (!r->right)
				return (r);
			return (findLargest(r->right));
		}

		Node *findSmallest(Node *r) const
		{
			if (!r)
				return (r);
			else if (!r->left) 
				return (r);
			return (findSmallest(r->left));
		}

		Node *findLargest(Node *r) const
		{
			if (!r)
				return (r);
			else if (!r->right)
				return (r);
			return (findLargest(r->right));
		}

		value_type *getParent(Node *r)
		{
			return (r->parent);
		}
	
		void inorder(Node *r)
		{
			if (!r)
				return;
			inorder(r->left);
			inorder(r->right);
		}

		//Node *inorderPredecessor(Node *r)
		//{
		//	if (r->left)
		//		return (findLargest(r->left));
		//	else
		//		return (r->parent);
		//}
					

		void count_key(Node *r, const key_type &k, size_t &count) const
		{
			if (!r)
				return;
			if (r->data.first == k)
				count++;
			count_key(r->left, k, count);
			count_key(r->right, k, count);
		}

		Node *inorderPredecessor(Node *r)
		{
			if (!r)
				return (r);
			else
			{
				if (r->left)
				{
					r = r->left;
					while (r->right)
						r = r->right;
				}
				else
				{
					Node *p = r->parent;
					while (p && r == p->left)
					{
						r = p;
						p = p->parent;
					}
					r = p;
				}
			}
			return (r);
		}

		Node *getHeadNode(Node *r)
        {
        	Node *tmp = r;

			while (1) 
			{
                if (!tmp || !tmp->parent)
                    return (tmp);
				tmp = tmp->parent;
			}
			return (tmp);
        }
};
