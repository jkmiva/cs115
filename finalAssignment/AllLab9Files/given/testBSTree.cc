

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "BSTree.h"

using namespace std;


int main() {
  	Tree *t = CreateBST();
  	Element arr[10] = {1, 20, 3, 17, 4, 15, 5, 11, 8, 14};
	int dataOut;
  
  	for (int i=0; i<10; i++) {
    	InsertBST(t, arr[i]);
  	}
  
	PrintInOrder(t);
		
	int target = 5;
	if(SearchBST(t, target, &dataOut))
		cout << "\n\nFound node " << dataOut << " in the tree" << endl;
	else 
		cout << "\n\nCan't find node " << target << " in the tree" << endl;
	
	if(DeleteBST(t, target, &dataOut))
		cout << "\n\nNode " << dataOut << " is deleted from the tree" << endl;
	else 
		cout << "\n\nCan't delete node " << target << " from the tree" << endl;
	
	cout << "\n\nThe inorder of the binary search tree is: ";
	PrintInOrder(t);
	
	
	target = 2;
	if(SearchBST(t, target, &dataOut))
		cout << "\n\nFound node " << dataOut << " in the tree" << endl;
	else 
		cout << "\n\nCan't find node " << target << " in the tree" << endl;

	cout << "\n\nThe inorder of the binary search tree is: ";
	PrintInOrder(t);
	
	DestroyBST(t);
	
  return EXIT_SUCCESS;
}
