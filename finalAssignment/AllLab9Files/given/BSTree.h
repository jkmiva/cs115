#ifndef _BS_TREE_H_
#define _BS_TREE_H_


typedef int Element;

struct TreeNode {
  Element data;
  TreeNode *left;
  TreeNode *right;
};

struct Tree{
	TreeNode *root;
};

// Create a binary search tree
// Post: a new empty tree is created
// Return: the new tree
//
Tree *CreateBST();

// Destroy a binary search tree
// Pre: given a tree
// Post: the tree is detroyed and all memory returned to the heap
//
void DestroyBST(Tree*);


// Searches a binary search tree starting at node rRoot for target 
// Pre: rTree is a reference to a BST
//      target is the key of the data element to search for
//		rDataOut is a reference of type Element
// Post: tree is unchanged. 
// Return: true if round, false otherwise
bool SearchBST(const Tree * rTree, const Element target, Element *rDataOut);

// Insert a node into a binary search tree
// Pre: rTree is a reference to a binary search tree
//      nData is the data element to insert into a new node
// Post: a new node with nData as data and inserted a new node in the tree such that rTree remains a binary search tree. 
// Return: Nothing
void InsertBST(Tree * rTree, const Element nData);

// Delete a node from a binary search tree 
// Pre: rTree is a reference to a binary search tree
//      nData is the data element of the node to be deleted
//      rDataOut is a reference of type Element
// Post: if there is a node containing nData, it is removed from tree, and its data place in *rDataOut 
// Return: true if node deleted, false otherwise.
bool DeleteBST(Tree * rTree, const Element nData, Element *rDataOut);

// Print the inorder of a given tree
void PrintInOrder(Tree *);

// Print the preorder of a given tree
void PrintPreOrder(Tree *);

// Print the postorder of a given tree
void PrintPostOrder(Tree *);

#endif // _BS_TREE_H_
