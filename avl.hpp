#include <iostream>


//?Difference between Binary Tree, Binary Search Tree and AVL Tree
//* Binary tree is a tree data structure in which each node has at most two children (It has no rules)
//* Binary Search Tree is a Binary tree in which the value of each node is greater than or equal to the value of the node to its left and less than or equal to the value of the node to its right.
//* AVL Tree Is a BT and a Binary Search Tree but it is balanced, It is a self-balancing Binary Search Tree, We use Rotations to balance the tree.

//?Nodes
//* Small nodes goes to the left, large or equal nodes goes to the right

//?Heights
//* Height of each tree path,   Root node = 0
//* No Node = Height = -1
//* Single node = Height = 0
//* Two nodes = Height = 1
//* Three nodes = Height = 2...
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot3.png

//?Balance factor
//* The balance factor is known as the difference between the height of the left subtree and the right subtree. (How many nodes are in each Path)
//! Balance Factor(n) = H(left subtree) - H(right subtree)
//* Allowed values of BF are –1, 0, and +1, any values other than these are not allowed (Unbalanced tree)
//* If the balance factor is 0, it means that the left and right subtrees are of equal height
//* If the balance factor is +1, it means that the right subtree is taller than the left subtree
//* If the balance factor is −1, it means that the left subtree is taller than the right subtree
//* If the balance factor is −2, it means that the left subtree is 2 levels higher than the right subtree

//?Rotations
//* To make the AVL Tree balance itself, when inserting or deleting a node from the tree, rotations are performed
//* There are four types of rotations: Left-Left, Left-Right, Right-Right, and Right-Left
//!https://www.youtube.com/watch?v=u3OVSkuOdqI

//?Left-Left
//* The left-left rotation is performed when the balance factor of the node is −2
//* This rotation is performed when a new node is inserted at the left child of the left subtree.
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot4.png

//?Right-Right
//* The right-right rotation is performed when the balance factor of the node is +2  
//* This rotation is performed when a new node is inserted at the right child of the right subtree.
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot5.png

//?Right-Left
//* The right-left rotation is performed when the balance factor of the node is −1
//* This rotation is performed when a new node is inserted at the right child of the left subtree.
//https://www.guru99.com/images/2/063020_0727_AVLTreesRot6.png

//?Left-Right
//* The left-right rotation is performed when the balance factor of the node is +1
//* This rotation is performed when a new node is inserted at the left child of the right subtree.
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

template <typename T>
class Node 
{
	public:
		T data;
		int height;
		Node *right;
		Node *left;

		Node()
		{
			data = 0;
			height = 0;
			right = NULL;
			left = NULL;
		}
		Node(T n)
		{
			height = 0;
			data = n;
			right = NULL;
			left = NULL;
		}
};




template <typename T>
class Avl
{
	public:
		T data;
		Node<T> *root;
		typedef Node<T> Node;

		Avl()
		{
			root = NULL;
		}

		Avl(T n)
		{
			root = new Node(n);
		}

		size_t getHeight(Node *r)
		{
			size_t rheight;
			size_t lheight;
			
			if (r == NULL)
				return (-1);
			else
			{
				rheight = getHeight(r->right);
				lheight = getHeight(r->left);
			}
			if (lheight > rheight)
				return (lheight + 1);
			else
				return (rheight + 1);
		}

		size_t getRightHeight(Node *r)
		{
			size_t rheight;

			if (r == NULL)
				return (-1);
			else if (r->right == NULL)
				return (0);
			else
				rheight = getRightHeight(r->right);
			return (rheight + 1);
		}

		size_t getLeftHeight(Node *r)
		{
			size_t lheight;

			if (r == NULL)
				return (-1);
			else if (r->left == NULL)
				return (0);
			else
				lheight = getLeftHeight(r->left);
			return (lheight + 1);
		}

		size_t getBalance(Node *r)
		{
			if (r == NULL)
				return (-1);
			return (getLeftHeight(r) - getRightHeight(r));
		}

		Node *newNode(T data)
		{
			return (new Node(data));
		}

		Node *searchNode(Node *r, T data)
		{
			if (r == NULL)
				return (NULL);
			if (r->data == data)
			{
				std::cout << "Found " << data << std::endl;
				return (r);
			}
			else if (data < r->data)
				return (searchNode(r->left, data));
			else
				return (searchNode(r->right, data));
		}

		Node *insertNode(Node *r, T data)
		{
			if (r == NULL)
			{
				r = newNode(data);
				if (root == NULL)
					root = r;
			}
			else if (data < r->data)
			{
				std::cout << "Left" << std::endl;
				r->left = insertNode(r->left, data);
			}
			else if (data >= r->data)
			{
				std::cout << "Right" << std::endl;
				r->right = insertNode(r->right, data);
			}
			return (r);
		}

		//Node *insertNode(Node *r, T data)
		//{
		//	if (r == NULL)
		//	{
		//		r = newNode(data);
		//		if (root == NULL)
		//			root = r;
		//	}
		//	else if (data < r->data)
		//	{
		//		std::cout << "Left" << std::endl;
		//		return (insertNode(r->left, data));
		//	}
		//	else if (data >= r->data)
		//	{
		//		std::cout << "Right" << std::endl;
		//		return (insertNode(r->right, data));
		//	}
		//	return (r);
		//}

		
		//Node *insertNode(Node *r, T data)
		//{
		//	if (!searchNode(r, data))
		//	{
		//		r = newNode(data);
		//		if (root == NULL)
		//			root = r;
		//	}
		//	else
		//		r->right = newNode(data);
		//	return (r);
		//}

		Node* leftRotation(Node *r) //https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/
		{
		
			Node *temp2;

			temp2 = r->left;
			temp2->right = r;

			return (temp2);
		}

		void printLeft(Node *r)
		{
			if (r == NULL)
			{
				std::cout << "NULL found" << std::endl;
				return ;
			}
			std::cout << r->data << std::endl;
			return (printLeft(r->left));
		}
};


