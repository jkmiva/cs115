/***************************************************************************
 Week 11 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

// File: Huffman.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: The implementation for two ADTS:
//   HuffmanTree
//   HuffmanCodec


#include "LOCALE.h"
#include "Huffman.h"
#include "TreeNode.h"
#include "Frequency.h"
#include "List.h"
#include "FrequencyList.h"
#include "copy.h"

#include <cstring>
#include <iostream>

using namespace std;


// createHuffmanTree(frequencies)
// Pre: frequencies is a reference to a FrequencyList
// Post: allocates a new HuffmanTree record
// return: a reference to the Huffman tree, if the list is not empty
HuffmanTree *createHuffmanTree(FrequencyList *frequencies) {
  // TODO:  complete this function
	TreeNode *addLeft, *addRight ,*addMid;
	//TreeNode *addMid = new TreeNode;
	while (getNumElements(frequencies) > 1) {
		addLeft = remove_smallest(frequencies);
		addRight = remove_smallest(frequencies);
		addMid = new TreeNode;
		addMid->data = createFrequency('$',addLeft->data->count + addRight->data->count);
		addMid->left = addLeft;
		addMid->right = addRight;
		insert(frequencies, addMid);
	}
	HuffmanTree *huffmanTree = new HuffmanTree;
	huffmanTree->root = addMid;
//	cout <<"hufftestData "<<huffmanTree->root->data->data<<endl;
//	cout <<"hufftestCount "<<huffmanTree->root->data->count<<endl;
//	cout <<"testHeight "<< height(addMid)<<endl;
	return huffmanTree;
		
		
  //return NULL;
}



// createHuffmanCodec(htree)
// Pre: htree is a reference to a HuffmanTree
// Post: allocates a new HuffmanCodec record
// return: a reference to the Huffman codec

HuffmanCodec *createHuffmanCodec(HuffmanTree *t) {
  HuffmanCodec *hcdc = new HuffmanCodec;
  hcdc->huffTree = t;

  //initialize codebook 
  for (int i = 0; i < ASCII_SIZE; i++){
    hcdc->codebook[i] = NULL;
  }

  // build the codebook using the Tree
  char *acode = new char[height(t->root)+1];
  find_codes(hcdc, t->root, acode, 0);
  return hcdc;
}


// find_codes(codec,tree,store,index)
// recursively find Huffman codes from a given tree
// pre: codec is a reference to Huffman Codec
//      tree  is a reference to a TreeNode in the HuffmanTree
//      store is a character array used to store partial solutions
//      index is the next unused index in store
// post: the Huffman codes have been printed.
void find_codes(HuffmanCodec *hcdc, TreeNode *t, char s[], int d){
  if (t == NULL){
    return;
  }
  else if (isLeaf(t)){
    s[d] = '\0';
    hcdc->codebook[(int) getData(getData(t))] = copy(s);
  }
  else {
    s[d] = '0';
    find_codes(hcdc, getLeft(t), s, d+1);
    s[d] = '1';
    find_codes(hcdc, getRight(t), s, d+1);
  }
}

// delete_huffman_helper(t)
// deallocate the huffman tree and frequency records
// Pre: t::refToTreeNode
// Post: the tree t and its subtrees have been deleted
//       as well as their contents.
void delete_huffman_helper(TreeNode *t){
  if (t == NULL){
    return;
  }
  delete_huffman_helper(getLeft(t));
  delete_huffman_helper(getRight(t));
  //delete the Frequency record
  delete getData(t);
  //delete the current Tree node
  delete t;
}

// DESTRUCTOR
//  destroyHuffmanTree(ht)
//  Pre: ht is a reference to a HuffmanTree
//  Post: memory for ht is deallocated
void destroyHuffmanTree(HuffmanTree *ht){
  delete_huffman_helper(ht->root);
  delete ht;
}

  
//  destroyHuffmanCodec(hcdc)
//  Pre: hcdc is a reference to a HuffmanCodec
//  Post: memory for ht is deallocated
void destroyHuffmanCodec(HuffmanCodec *hcdc){
  destroyHuffmanTree(hcdc->huffTree);
  for (int i = 0; i < ASCII_SIZE; i++){
    if (hcdc->codebook[i] != NULL){
      delete [] hcdc->codebook[i];
    }
  }
}



// encode(hcdc, message)
// encode a message using the Huffman Codec
// Pre: hcdc is a referene to a HuffmanCodec
//      message:: a cstring to encode
// Return a cstring containing the encoded message
char *encode(HuffmanCodec *h, const char message[]){
  // TODO: complete this function
	FrequencyList *freqList = createFrequencyList(message);
	HuffmanTree *huffTree = createHuffmanTree(freqList);
	h = createHuffmanCodec(huffTree);
	size_t mesLen = strlen(message);
	char * encodedStr = new char[10*mesLen];
	char *temp;
	for (size_t i = 0; i < mesLen; i++) {
		temp = h->codebook[(int)message[i]];
		strcat(encodedStr, temp);
	}
	return encodedStr;
}



// decode_char(tnode, message, d){
// decode one character from the message.
// Pre: tnode is a node in a huffman tree
//      message:: cstring, the whole message to decode
//      d:: a reference to an int containing the current
//          index in the message
// Post: d has been increased by the number of 0s and 1s used to
//       encode the character
// Return: the decoded character
char decode_char(TreeNode *t, char message[], int *d){

  // TODO: complete this function
	//if (t == NULL) exit(1);
	if (height(t) == 1){
		d++;
		return getData(getData(t));
	}
	if (isLeaf(t)){
		return getData(getData(t));
	}
	if (message[*d] == '0') {
		(*d)++;
		return decode_char(t->left, message, d);
	}
	if (message[*d] == '1') {
		(*d)++;
		return decode_char(t->right, message, d);
	}
	
 return '.';  // dot returned for no good reason
}

// decode(hcdc, message)
// decode the given message
// Pre: hcdc is a reference to a HuffmanCodec
//      message:: cstring containing the coded message
// return: a reference to a cstring containing the decoded message
char *decode(HuffmanCodec *h, char message[]){
  int d = 0;  // index for the coded message
  int i = 0;  // index for the de-coded message

  // Note: We've simplified by using a fixed size array
  // we could estimate the length of the message
  // more accurately than this by using the length
  // of the message to decode and the tree height.
  char *decoded_msg = new char[MESSAGE_LIMIT];

  // go through the whole message
  while (d < (int)strlen(message)){
    // decode one character using the Huffman Tree
    decoded_msg[i] = decode_char(h->huffTree->root, message, &d);
    i++;
  }
  // ensure the C-string is properly terminated
  decoded_msg[i] = '\0';

  // then make a copy
  char *result = copy(decoded_msg);
  delete [] decoded_msg;
  return result;
}

// eof

