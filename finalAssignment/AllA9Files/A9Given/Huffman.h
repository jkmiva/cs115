// File: Huffman.h
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: The interface for two ADTS:
//   HuffmanTree
//   HuffmanCodec


#include "TreeNode.h"
#include "FrequencyList.h"
#include "LOCALE.h"

#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

struct HuffmanTree {
  TreeNode *root;
};

struct HuffmanCodec {
  HuffmanTree *huffTree;
  char *codebook[ASCII_SIZE];
};


// createHuffmanTree(frequencies)
// Pre: frequencies is a reference to a FrequencyList
// Post: allocates a new HuffmanTree record
// return: a reference to the Huffman tree, if the list is not empty
HuffmanTree *createHuffmanTree(FrequencyList *frequencies) ;

// createHuffmanCodec(htree)
// Pre: htree is a reference to a HuffmanTree
// Post: allocates a new HuffmanCodec record
// return: a reference to the Huffman codec

HuffmanCodec *createHuffmanCodec(HuffmanTree *t) ;


// find_codes(codec,tree,store,index)
// recursively find and print Huffman codes from a given tree
// pre: codec is a reference to Huffman Codec
//      tree  is a reference to a TreeNode in the HuffmanTree
//      store is a character array used to store partial solutions
//      index is the next unused index in store
// post: the Huffman codes have been printed.
void find_codes(HuffmanCodec *hcdc, TreeNode *t, char s[], int d);

// encode(hcdc, message)
// encode a message using the Huffman Codec
// Pre: hcdc is a referene to a HuffmanCodec
//      message:: a cstring to encode
// return a cstring containing the encoded message
char *encode(HuffmanCodec *h, const char message[]);

// decode(hcdc, message)
// decode the given message
// Pre: hcdc is a reference to a HuffmanCodec
//      message:: cstring containing the coded message
// return: a reference to a cstring containing the decoded message
char *decode(HuffmanCodec *h, char message[]);

// DESTRUCTOR

// delete_huffman_helper(t)
// deallocate the huffman tree and frequency records
// Pre: t::refToTreeNode
// Post: the tree t and its subtrees have been deleted
//       as well as their contents.
void delete_huffman_helper(TreeNode *t);

//  destroyHuffmanTree(ht)
//  Pre: ht is a reference to a HuffmanTree
//  Post: memory for ht is deallocated
void destroyHuffmanTree(HuffmanTree *ht);

  
//  destroyHuffmanCodec(hcdc)
//  Pre: hcdc is a reference to a HuffmanCodec
//  Post: memory for ht is deallocated
void destroyHuffmanCodec(HuffmanCodec *hcdc);

#endif
