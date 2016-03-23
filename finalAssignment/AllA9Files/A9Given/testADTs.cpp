// File: testADTs.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: runs a bunch of tests on the ADTs
//           for assignment 9
// Compile using:
//   g++ -Wall -pedantic -o newapp List.cc TreeNode.cc Frequency.cc testADTs.cpp


#include <iostream>
#include "List.h"
#include "TreeNode.h"
#include "Frequency.h"
#include "FrequencyList.h"
#include "Huffman.h"

using namespace std;

// function to make testing a little neater
// Pre: passed is a boolean which is true if the test passed, and false if it didn't
void testDecider(int *number, int *nFailed, bool passed, 
                 const char *testannounce, const char *iffailed) {
  *number += 1;
  cout << "Test " << *number << ": " << testannounce;
  if (passed) {
    cout << "Passed!";
  } 
  else {
    *nFailed += 1;
    cout << "Error: " << iffailed << " **** ";
  }
  cout << endl;
}




int testall(){
  // ----------------------------------------------
  // Testing Frequency ADT
  // Try to create a frequency record
  Frequency *freq_for_testing = createFrequency('f',5);
  // test the frequency record
  int testNumber = 0;
  int testFailed = 0;
  testDecider(&testNumber, &testFailed,
              getData(freq_for_testing) == 'f',
              "Frequency getData() ",
              "inconsistent character stored in Frequency record");
  setData(freq_for_testing,'g');
  testDecider(&testNumber, &testFailed,
              getData(freq_for_testing) == 'g',
              "Frequency setData() ",
              "setData() seemed to have no effect!");
  testDecider(&testNumber, &testFailed,
              getCount(freq_for_testing) == 5,
              "Frequency getCount(): ",
              "inconsistent count stored in Frequency record");
  setCount(freq_for_testing,6);
  testDecider(&testNumber, &testFailed,
              getCount(freq_for_testing) == 6,
              "Frequency setCount(): ",
              "setCount() seemed to have no effect!");

  if (testFailed > 10) return testFailed;

  // ----------------------------------------------
  // Testing TreeNode ADT
  // Try to create a tree using the frequency record
  TreeNode *tree_for_testing = createTreeNode(freq_for_testing);
  testDecider(&testNumber, &testFailed,
              isLeaf(tree_for_testing),
              "TreeNode isLeaf(): ",
              "tree record should be a leaf, but isn't");  
  testDecider(&testNumber, &testFailed,
              getData(tree_for_testing) == freq_for_testing,
              "TreeNode getData(): ",
              "tree record should contain the frequency object, but doesn't");  
  testDecider(&testNumber, &testFailed,
              height(tree_for_testing) == 1,
              "TreeNode height(): ",
              "tree record should have height 1, but doesn't");  
  testDecider(&testNumber, &testFailed,
              getLeft(tree_for_testing) == NULL,
              "TreeNode getLeft(): ",
              "Unexpected left subtree not NULL");
  testDecider(&testNumber, &testFailed,
              getRight(tree_for_testing) == NULL,
              "TreeNode getRight(): ",
              "Unexpected right subtree not NULL");

  if (testFailed > 10) return testFailed;
  TreeNode *another_tree = createTreeNode(createFrequency('x',12));
  setRight(tree_for_testing, another_tree);
  testDecider(&testNumber, &testFailed,
              getRight(tree_for_testing) == another_tree,
              "TreeNode setRight(): ",
              "set right subtree failed");
  another_tree = createTreeNode(createFrequency('q',314));
  setLeft(tree_for_testing, another_tree);
  testDecider(&testNumber, &testFailed,
              getLeft(tree_for_testing) == another_tree,
              "TreeNode setLeft(): ",
              "set left subtree failed");
  testDecider(&testNumber, &testFailed,
              !isLeaf(tree_for_testing),
              "TreeNode isLeaf(): ",
              "tree record seems to be a leaf, but shouldn't be!");
  testDecider(&testNumber, &testFailed,
              height(tree_for_testing) == 2,
              "TreeNode height(): ",
              "tree record should have height 2, but doesn't");  

  if (testFailed > 10) return testFailed;
  another_tree = getRight(tree_for_testing);
  testDecider(&testNumber, &testFailed,
              height(another_tree) == 1,
              "TreeNode height(): ",
              "tree record should have height 1, but doesn't");  
  setRight(tree_for_testing,NULL);
  testDecider(&testNumber, &testFailed,
              getRight(tree_for_testing) == NULL,
              "TreeNode setRight(): ",
              "tree record should have NULL right subtree, but doesn't");  
  testDecider(&testNumber, &testFailed,
              height(tree_for_testing) == 2,
              "TreeNode height(): ",
              "tree record should still have height 2, but doesn't");  

  if (testFailed > 10) return testFailed;
  // ----------------------------------------------
  // Testing List ADT
  // Try to create a List record using the tree object
  List *list_for_testing = createList(); 
  // check is empty?
  testDecider(&testNumber, &testFailed,
              isEmpty(list_for_testing),
              "List isEmpty(): ",
              "new list record should be empty, but isn't");  

  // check for zero elements
  testDecider(&testNumber, &testFailed,
              getNumElements(list_for_testing) == 0,
              "List getNumElements(): ",
              "new list record shold have zero elements, but doesn't");  

  // add tree to the list   
  testDecider(&testNumber, &testFailed,
              insert(list_for_testing,tree_for_testing),
              "List insert(): ",
              "should have succeeded, but didn't!");  
  // test the tree record again
  testDecider(&testNumber, &testFailed,
              getNumElements(list_for_testing) == 1,
              "List getNumElements(): ",
              "new list record should have one element, but doesn't");  
  testDecider(&testNumber, &testFailed,
              remove(list_for_testing, tree_for_testing),
              "List remove(): ",
              "remove() failed! ");  
  testDecider(&testNumber, &testFailed,
              insert(list_for_testing,tree_for_testing),
              "List insert(): ",
              "should have succeeded, but didn't!");  
  // add another tree to the list   
  testDecider(&testNumber, &testFailed,
              insert(list_for_testing,another_tree),
              "List insert(): ",
              "should have succeeded, but didn't!");  
  // test the tree record again
  testDecider(&testNumber, &testFailed,
              getNumElements(list_for_testing) == 2,
              "List getNumElements(): ",
              "new list record should have one element, but doesn't");  
  testDecider(&testNumber, &testFailed,
              remove(list_for_testing, another_tree),
              "List remove(): ",
              "remove() failed! ");  
  testDecider(&testNumber, &testFailed,
              insert(list_for_testing,another_tree),
              "List insert(): ",
              "should have succeeded, but didn't!");  
  // test the tree record again
  testDecider(&testNumber, &testFailed,
              getNumElements(list_for_testing) == 2,
              "List getNumElements(): ",
              "new list record should have one element, but doesn't");  
 
  if (testFailed > 10) return testFailed;
  // ----------------------------------------------
  // Testing Iterator ADT
  // Try to create a Iterator record using the list object
  Iterator *lTrav_for_testing = createIterator(list_for_testing);
  testDecider(&testNumber, &testFailed,
              hasNext(lTrav_for_testing),
              "Iterator hasNext(): ",
              "there should be something in the list to look at, but isn't");
  testDecider(&testNumber, &testFailed,
              next(lTrav_for_testing) == tree_for_testing,
              "Iterator next(): ",
              "should have gotten the tree record, but didn't");  
  testDecider(&testNumber, &testFailed,
              hasNext(lTrav_for_testing),
              "Iterator hasNext(): ",
              "there should be something in the list to look at, but isn't");
  testDecider(&testNumber, &testFailed,
              next(lTrav_for_testing) == another_tree,
              "Iterator next(): ",
              "should have gotten a tree record, but didn't");  
  testDecider(&testNumber, &testFailed,
              !hasNext(lTrav_for_testing),
              "Iterator hasNext(): ",
              "there shouldn't be anything in the list to look at, but there is");  

  if (testFailed > 10) return testFailed;
  // ----------------------------------------------
  // Testing FrequencyList ADT
  FrequencyList *flist = createFrequencyList("122333");
  // check is empty?
  testDecider(&testNumber, &testFailed,
              !isEmpty(flist),
              "FrequencyList isEmpty(): ",
              "new frequency list record should not be empty, but seems to be");  
  testDecider(&testNumber, &testFailed,
              getNumElements(flist) == 3,
              "FrequencyList getNumElements(): ",
              "new frequency list record should have 3 elements, but doesn't");

  TreeNode *smallest = remove_smallest(flist);
  testDecider(&testNumber, &testFailed,
              getData(getData(smallest)) == '1',
              "FrequencyList remove_smallest(): ",
              "tried to find the smallest Frequency in the list, but didn't");
  testDecider(&testNumber, &testFailed,
              getNumElements(flist) == 2,
              "FrequencyList getNumElements(): ",
              "new frequency list record should have 2 elements, but doesn't");
  TreeNode *middlest = remove_smallest(flist);
  testDecider(&testNumber, &testFailed,
              getData(getData(middlest)) == '2',
              "FrequencyList remove_smallest(): ",
              "tried to find the smallest Frequency in the list, but didn't");
  testDecider(&testNumber, &testFailed,
              getNumElements(flist) == 1,
              "FrequencyList getNumElements(): ",
              "new frequency list record should have 1 element, but doesn't");
  testDecider(&testNumber, &testFailed,
              insert(flist,middlest),
              "FrequencyList insert(): ",
              "couldn't insert a treenode");
  testDecider(&testNumber, &testFailed,
              getNumElements(flist) == 2,
              "FrequencyList getNumElements(): ",
              "new frequency list record should have 2 elements, but doesn't");
  testDecider(&testNumber, &testFailed,
              insert(flist,smallest),
              "FrequencyList insert(): ",
              "couldn't insert a treenode");

  if (testFailed > 10) return testFailed;
  // ----------------------------------------------
  // Testing HuffmanTree ADT

  HuffmanTree *hufft = createHuffmanTree(flist);
  testDecider(&testNumber, &testFailed,
              hufft != NULL,
              "HuffmanTree createHuffmanTree(): ",
              "couldn't create a HuffmanTree");

  // this test violates the ADT
  testDecider(&testNumber, &testFailed,
              height(hufft->root) == 3,
              "HuffmanTree createHuffmanTree(): ",
              "HuffmanTree is the wrong size!");
  // this test violates the ADT
  testDecider(&testNumber, &testFailed,
              getCount(getData(hufft->root)) == 6,
              "HuffmanTree createHuffmanTree(): ",
              "HuffmanTree calculated the wrong frequency at the root!");

  if (testFailed > 10) return testFailed;
  // ----------------------------------------------
  // Testing HuffmanCodec ADT
  HuffmanCodec *huffcdc = createHuffmanCodec(hufft);
  testDecider(&testNumber, &testFailed,
              huffcdc != NULL,
              "HuffmanCodec createHuffmanTree(): ",
              "HuffmanCodec returned a NULL Codec!");
  char *one, *two, *three;
  one = huffcdc->codebook[(int)'1'];
  cout << "Test " << testNumber << ": Code for \'1\' is " << one
       << " (should be 2 bits long)" << endl;
  testNumber++;
  two = huffcdc->codebook[(int)'2'];
  cout << "Test " << testNumber << ": Code for \'2\' is " << two
       << " (should be 2 bits long)" << endl;
  testNumber++;
  three = huffcdc->codebook[(int)'3'];
  cout << "Test " << testNumber << ": Code for \'3\' is " << three
       << " (should be 1 bit long)" << endl;

  char *coded = encode(huffcdc, "123");
  testDecider(&testNumber, &testFailed,
              coded != NULL,
              "HuffmanCodec encode(): ",
              "HuffmanCodec returned a NULL string as a code!");
  cout << "Test " << testNumber << ": Code for \"123\" is " << coded
       << " (should be : " << one << two << three << ")" << endl;

  char *decoded = decode(huffcdc, one);
  testDecider(&testNumber, &testFailed,
              decoded != NULL,
              "HuffmanCodec decode(): ",
              "returned a NULL string for 1!");
  cout << "Test " << testNumber << ": Decoding \"" << one << "\" gives " 
       << decoded
       << " (should be : 1)" << endl;

  delete [] decoded;
  decoded = decode(huffcdc, two);
  testDecider(&testNumber, &testFailed,
              decoded != NULL,
              "HuffmanCodec decode(): ",
              "returned a NULL string for 2!");
  cout << "Test " << testNumber << ": Decoding \"" << two << "\" gives " 
       << decoded
       << " (should be : 2)" << endl;

  delete [] decoded;
  decoded = decode(huffcdc, three);
  testDecider(&testNumber, &testFailed,
              decoded != NULL,
              "HuffmanCodec decode(): ",
              "returned a NULL string for 3!");
  cout << "Test " << testNumber << ": Decoding \"" << three << "\" gives " 
       << decoded
       << " (should be : 3)" << endl;


  delete [] decoded;
  decoded = decode(huffcdc, coded);
  testDecider(&testNumber, &testFailed,
              decoded != NULL,
              "HuffmanCodec decode(): ",
              "returned a NULL string for 123!");
  cout << "Test " << testNumber << ": Decoding \"" << coded << "\" gives " 
       << decoded
       << " (should be : 123)" << endl;

  cout << "No more tests!" << endl;
  
  // tidy up 
  destroyFrequency( freq_for_testing );
  destroyTreeNode( tree_for_testing );
  destroyList( list_for_testing );
  destroyIterator( lTrav_for_testing );
  destroyHuffmanCodec( huffcdc );
  return testFailed;

}

int main() {

  int failed = testall();
  if (failed == 0) {
    cout << "Congratulations!  You passed all the tests!" << endl;
  }
  else if (failed >= 10) {
    cout << "You failed at least 10 tests, skipped the rest." << endl;
  }
  else {
    cout << "You failed less than 10 tests.  Getting pretty close!" << endl;
  }

  return 0;
}
